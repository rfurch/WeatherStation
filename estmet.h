
#ifndef WIRE_H_INCLUDED
#define WIRE_H_INCLUDED
  #include <Wire.h>
#endif




#define MAX_TEXT_LEN    50  
#define MAX_PORT_LEN    10


// data structure to keep WiFi config
typedef struct WiFiData{
  char    mqtt_server[MAX_TEXT_LEN];
  char    mqtt_port[MAX_PORT_LEN];
  char    ssid[MAX_TEXT_LEN];
  char    pass[MAX_TEXT_LEN];
  char    station_name[MAX_TEXT_LEN];
}WiFiData;


int WiFiConnect(WiFiData &wfd);
int WiFiDataInit(WiFiData &wfd);
int WiFiDataPrint(WiFiData &wfd);
