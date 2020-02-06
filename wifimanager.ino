
#ifndef WIFI_H_INCLUDED
#define WIFI_H_INCLUDED
#include "estmet.h"
#endif

// The extra parameters to be configured (can be either global or just in the setup)
// After connecting, parameter.getValue() will get you the configured value
// id/name placeholder/prompt default length

WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, MAX_TEXT_LEN);
WiFiManagerParameter custom_mqtt_name("name", "station name", station_name, MAX_TEXT_LEN);
WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, MAX_PORT_LEN);

// setup WiFi access point to capture configuration info. 

void WiFiManagerRun(int timeout, WiFiData &d, char *APName, int WMReset) {

    //WiFiManager Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings (we keep them in FLASH / EEPROM on our own) 
    
    if (WMReset)
      wifiManager.resetSettings();
  
    //add all your parameters here
    wifiManager.addParameter(&custom_mqtt_server);
    wifiManager.addParameter(&custom_mqtt_name);
    wifiManager.addParameter(&custom_mqtt_port);

    //wifiManager.setTimeout(timeout);
    //wifiManager.setConnectTimeout(timeout);
    wifiManager.setConfigPortalTimeout(timeout);
    wifiManager.setDebugOutput(1);

    //wifiManager.setBreakAfterConfig(1);
    //wifiManager.startConfigPortal(APName);
    wifiManager.autoConnect(APName);
    
    // save data to EEPROM
    if (wifiManager.getSSID().length() > 0)
      wifiManager.getSSID().toCharArray(d.ssid, MAX_TEXT_LEN);

    if (wifiManager.getPassword().length() > 0)
      wifiManager.getPassword().toCharArray(d.pass, MAX_TEXT_LEN);

    if (strlen(custom_mqtt_server.getValue()) > 0)
      strlcpy(d.mqtt_server, custom_mqtt_server.getValue(), MAX_TEXT_LEN);

    if (strlen(custom_mqtt_name.getValue()) > 0)
      strlcpy(d.station_name, custom_mqtt_name.getValue(), MAX_TEXT_LEN);
      
    if (strlen(custom_mqtt_port.getValue()) > 0)
      strlcpy(d.mqtt_port, custom_mqtt_port.getValue(), MAX_PORT_LEN);

    WiFiDataPrint(wfd);

}
