#include <WiFi.h>               
#include <EEPROM.h>

#include <DNSServer.h>
#include <WebServer.h>
#include <WiFiManager.h>         

#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <ESPmDNS.h>

#include <NTPClient.h>
#include <WiFiUdp.h>

#include <time.h>

#ifndef WIFI_H_INCLUDED 
#define WIFI_H_INCLUDED
#include "estmet.h"
#endif

char mqtt_server[MAX_TEXT_LEN] = "labredes.ddns.net";
char station_name[MAX_TEXT_LEN] = "ws0002";
char mqtt_port[MAX_PORT_LEN] = "8886";

WiFiData      wfd;
hw_timer_t    *timer = NULL;

WiFiClientSecure  espClient;
PubSubClient      pubSubClient(espClient);

// Define NTP Client to get time
WiFiUDP ntpUDP;
#define NTP_OFFSET 0 * 60 * 60 // In seconds
#define NTP_INTERVAL 60 * 1000 // In miliseconds
#define NTP_ADDRESS "0.pool.ntp.org"
 
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -3*3600;
const int   daylightOffset_sec = 0;

// the following counter controls how PIN 2 led Blinks
// flash / blink follows this rule:
// 4 flashes after booting.  detecting networks or getting in AP mode
// 3 flashes:  getting int AP mode
// 2 flashes: wifi conected
// 1 flash: MQTT connected, normal state

volatile int IRQCounter=0;      // counter for IRQ
volatile int blinkSetPoint=4;   // (number of blinks in one second)

int totalErrors=0;
int WIFIErrors=0;
int NTPErrors=0;
int MQTTErrors=0;
int BMEErrors=0;
int MCPErrors = 0;
int VEMLErrors = 0;

//--------------------------------------------------------

void IRAM_ATTR onTimer() {
if (IRQCounter < (2 * blinkSetPoint))
  digitalWrite(2, !digitalRead(2));
else if (IRQCounter > 20)
  IRQCounter=0;
else
  digitalWrite(2, LOW);

IRQCounter++;
}

//--------------------------------------------------------

void setup() {

    Wire.begin();

    // put your setup code here, to run once:
    Serial.begin(9600);

    // for WiFiConfig reset
    pinMode(0, INPUT_PULLUP);
    
    // flash rapidly while in AP mode 
    pinMode(2, OUTPUT);
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 200000, true);
    timerAlarmEnable(timer);
    blinkSetPoint=4;

    if (!EEPROM.begin(256))
      Serial.println("failed to initialise EEPROM"); 

    EEPROM.get( 0, wfd);
    WiFiDataInit(wfd);

  // borrar

    WiFiManagerRun(90, wfd, "ESTACION01", 0);

    WiFiDataPrint(wfd);
    EEPROM.put( 0, wfd);
    EEPROM.commit();

    // flash slowly while connecting to WiFi
    blinkSetPoint = 2;
    setup_pubSub(wfd);

    timeClient.begin();
    timeClient.setTimeOffset(-3 * 3600);
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    if (!pubSubClient.connected())  // check if MQTT connection is lost and retry
      fn_MQTTconnect(wfd); 

    if (!timeClient.update()) {
       int n=0;
       while ( ((n++) < 3) && !timeClient.forceUpdate());
    }
        
    setup_BME280();
    setup_VEML6070();
    setup_MCP9808();
}

//--------------------------------------------------------

int n = 1;
void loop() {     


    // check if Wireless connection is lost,  retry
    if (WiFi.status() != WL_CONNECTED) 
      {
      totalErrors++;
      WIFIErrors++;
        
      blinkSetPoint = 3;
      WiFiManagerRun(90, wfd, "ESTACION01", 0);
      }
    else if (!pubSubClient.connected())  // check if MQTT connection is lost and retry
      {
      totalErrors++;
      MQTTErrors++;

      blinkSetPoint = 2;
      fn_MQTTconnect(wfd); 
      }
    else  
      blinkSetPoint = 1;

    // check if BOOT  button is pressed for more than 5 seconds
    // and restart WiFi Manager with clean memory (Careful:  this resets all config)
    if(digitalRead(0) < 1)
      {
      blinkSetPoint = 4;
      WiFiManagerRun(90, wfd, "ESTACION01", 1);      
      }

    // in case of errors, reset board
    if (totalErrors > 30)
      ESP.restart();

      sendTopicLife(wfd);  delay (1000);

      if (++n >= 4)  {
        if (!timeClient.update()) {
          totalErrors++;
          NTPErrors++;
          }

      sendTopicTime(wfd);  delay (1000);
    
      sendMeassurementTopics();
      sendErrorTopics();
      n=1;
      }
      
    Serial.println(n);  
    Serial.println(ESP.getFreeHeap());
    delay(10000);
}
