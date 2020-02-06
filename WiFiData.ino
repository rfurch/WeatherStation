#ifndef WIFI_H_INCLUDED
#define WIFI_H_INCLUDED
#include "estmet.h"
#endif

//-----------------------------------------------------------------

int WiFiDataPrint(WiFiData &wfd)
{
Serial.print ("FLASH SSID: ");
Serial.print (wfd.ssid);
Serial.print (" pass: ");
Serial.print (wfd.pass);
Serial.print (" srv: ");
Serial.print (wfd.mqtt_server);
Serial.print (" port: ");
Serial.print (wfd.mqtt_port);
Serial.print (" name: ");
Serial.println (wfd.station_name);
}

//-----------------------------------------------------------------

// the first time program run 
// flash will be clean (deleted at progam upload)
// we set default values for some fields

int WiFiDataInit(WiFiData &wfd)
{
if (strlen(wfd.mqtt_server) < 1)
  strcpy(wfd.mqtt_server, "labredes.ddns.net");

if (strlen(wfd.mqtt_port) < 1)
  strcpy(wfd.mqtt_server, "8889");

if (strlen(wfd.station_name) < 1)
  strcpy(wfd.station_name, "ws0002");
}

//-----------------------------------------------------------------

int WiFicConnect(WiFiData &wfd)
{
int counter = 0;
delay(1000);
Serial.print("\nConnecting to "); Serial.println(wfd.ssid);
WiFi.begin(wfd.ssid, wfd.pass);
while (WiFi.status() != WL_CONNECTED && counter++<30) 
  {
  if ((counter % 14) == 0)
    {
    Serial.print("Forcing WiFi.begin... ");
    Serial.print(" ssid: "); Serial.print(wfd.ssid);
    Serial.print(" pass: "); Serial.print(wfd.pass);

    Serial.print("WIFI status = ");  Serial.println(WiFi.getMode());
    
    WiFi.disconnect(true); delay(1000);
    WiFi.mode(WIFI_OFF);   delay(1000);
    WiFi.mode(WIFI_STA);   delay(1000);
    WiFi.begin(wfd.ssid, wfd.pass);  delay(1000);
    Serial.print("WIFI mode = ");  Serial.println(WiFi.getMode());
    }
  Serial.print("Wifi Status: ");  Serial.println(WiFi.status());
  delay(1000);
  }
  
if (  WiFi.status() == WL_CONNECTED )
  {
  Serial.print("\nWiFi connected   IP: "); Serial.println(WiFi.localIP());
  }
else
  Serial.print("\n ERROR connecting to WiFi !!! ");
}

//-----------------------------------------------------------------
