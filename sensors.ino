
#ifndef WIFI_H_INCLUDED
#define WIFI_H_INCLUDED
#include "estmet.h"
#endif


#include "Adafruit_VEML6070.h"
#include "Adafruit_BME280.h"
#include "Adafruit_MCP9808.h"


#define BME280_ADD 0x76

#define I2C_SDA 21
#define I2C_SCL 22
//#define SEALEVELPRESSURE_HPA (1013.25)
#define SEALEVELPRESSURE_HPA (1019)

// Create sensors....
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();
Adafruit_VEML6070 uv = Adafruit_VEML6070();
Adafruit_BME280 bme(I2C_SDA, I2C_SCL);

//--------------------------------------------------------

int setup_BME280() {
  bool status;

  status = bme.begin(BME280_ADD);
  if (!status) 
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  else  
    Serial.println("BME280 sensor found and OK!");
}

//--------------------------------------------------------

int setup_VEML6070() {
uv.begin(VEML6070_1_T);  // pass in the integration time constant
return(1);
}  

//--------------------------------------------------------

int setup_MCP9808() {
  // Make sure the sensor is found, you can also pass in a different i2c
  // address with tempsensor.begin(0x19) for example, also can be left in blank for default address use
  // Also there is a table with all addres possible for this sensor, you can connect multiple sensors
  // to the same i2c bus, just configure each sensor with a different address and define multiple objects for that
  //  A2 A1 A0 address
  //  0  0  0   0x18  this is the default address
  //  0  0  1   0x19
  //  0  1  0   0x1A
  //  0  1  1   0x1B
  //  1  0  0   0x1C
  //  1  0  1   0x1D
  //  1  1  0   0x1E
  //  1  1  1   0x1F
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    //while (1);
  }
  else     
   Serial.println("Found MCP9808!");

  tempsensor.setResolution(3); // sets the resolution mode of reading, t
                               // he modes are defined in the table bellow:
  
  // Mode Resolution SampleTime
  //  0    0.5°C       30 ms
  //  1    0.25°C      65 ms
  //  2    0.125°C     130 ms
  //  3    0.0625°C    250 ms

  tempsensor.wake();   // wake up, ready to read!
  return(1);
}

//--------------------------------------------------------

int readUV(float *value) {
  *value = uv.readUV();

  if (*value < 0 || *value > 5000) {
     totalErrors++;
     VEMLErrors++;
     return(0);
     }
  return(1);
}

//--------------------------------------------------------

int readTempPrec(float *value) {
  *value = tempsensor.readTempC();
  if (*value < -30 || *value > 100) {
     totalErrors++;
     MCPErrors++;
     return(0);
     }
return(1);
}

//--------------------------------------------------------

int  readTemp(float *value) {  
  *value = bme.readTemperature();

  if (*value < -30 || *value > 100) {
     totalErrors++;
     BMEErrors++;
     return(0);
     }
return(1);
}

//--------------------------------------------------------

int  readPressure(float *value) {
  *value = bme.readPressure() / 100.0F;

  if (*value < 0 || *value > 1500) {
     totalErrors++;
     BMEErrors++;
     return(0);
     }
return(1);
}

//--------------------------------------------------------

int readAlt(float *value) {
  *value= bme.readAltitude(SEALEVELPRESSURE_HPA);

  if (*value < -200 || *value > 10000) {
     totalErrors++;
     BMEErrors++;
     return(0);
     }
return(1);
}

//--------------------------------------------------------

int readHumidity(float *value) {
    *value = bme.readHumidity();

  if (*value < 0 || *value > 110) {
     totalErrors++;
     BMEErrors++;
     return(0);
     }
return(1);
}

//--------------------------------------------------------
