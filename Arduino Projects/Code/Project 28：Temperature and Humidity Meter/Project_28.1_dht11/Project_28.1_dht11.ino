//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 28.1
Read_the_temperature_and_humidity_values
http//www.keyestudio.com
*/
#include "DHT.h"
#define DHTPIN 11     // connect the DHT sensor to the digital pins
DHT dht(DHTPIN, DHT11);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // wait for a few seconds between two measurment
  delay(2000);

  // It takes about 250 milliseconds to read the temperature or humidity! 
  // 
  float h = dht.readHumidity();
  // the temperature is Celsius (default value)
  float t = dht.readTemperature();
  // Calculate the Fahrenheit temperature (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // fail to read or not, exit(try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Calculate the Fahrenheit temperature index 
  float hif = dht.computeHeatIndex(f, h);
  // (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
//**********************************************************************************
