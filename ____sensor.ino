
#include <Wire.h>
#include "TSL2561.h"

//DHTesp dht;
TSL2561 tsl(TSL2561_ADDR_FLOAT); 

#include "DHT.h"
#define DHTPIN 12 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup()
{
  Serial.begin(115200);
dht.begin();
 

}
void loop()
{
  TEMP();
  //soil sensor();
 light();



}
void TEMP(){
 delay(2000);
 float h = dht.readHumidity();
 float t = dht.readTemperature();

Serial.print("Humidity: ");  Serial.print(h); Serial.print(" %\t");
  
Serial.print("Temperature: ");  Serial.print(t);  Serial.println(" *C ");

 
}
/*
void soil sensor(){
int sensorPin = A0
int sensorValue = analogRead(sensorPin); 
Serial.print("Moisture of Soil:  ");
Serial.println("sensorValue");
}
*/

void light(){
  
if (tsl.begin()) {
    Serial.println("Found sensor");
  } 
  else {
    Serial.println("No sensor?");
    while (1);
  }

    
  //tsl.setGain(TSL2561_GAIN_0X);         // set no gain (for bright situtations)
  tsl.setGain(TSL2561_GAIN_16X);      // set 16x gain (for dim situations)
  
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);  // shortest integration time (bright light)
  //tsl.setTiming(TSL2561_INTEGRATIONTIME_101MS);  // medium integration time (medium light)
  //tsl.setTiming(TSL2561_INTEGRATIONTIME_402MS);  // longest integration time (dim light)

  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE);     
  //uint16_t x = tsl.getLuminosity(TSL2561_FULLSPECTRUM);
  //uint16_t x = tsl.getLuminosity(TSL2561_INFRARED);
  
  Serial.println(x, DEC);

  
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  Serial.print("IR: "); Serial.print(ir);   Serial.print("\t\t");
  Serial.print("Full: "); Serial.print(full);   Serial.print("\t");
  Serial.print("Visible: "); Serial.print(full - ir);   Serial.print("\t");
  
  Serial.print("Lux: "); Serial.println(tsl.calculateLux(full, ir));
  
  delay(1000); 
}

void DS1820 {

  
}













