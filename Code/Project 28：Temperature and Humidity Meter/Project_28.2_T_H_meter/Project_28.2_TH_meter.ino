//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 28.2
Temperature_and_humidity_meter
http//www.keyestudio.com
*/
#include "DHT.h"
#define DHTPIN 11     // the pin connected the DHT sensor
DHT dht(DHTPIN, DHT11);
#include <lcd.h>  //add library files
lcd Lcd;  //define a Lcd class instance 

void setup() {
  Lcd.Init(); //initialize
  Lcd.Clear();  //clear

  dht.begin();
}
char string[10];

//lcd displays humidity and temperature values
void loop() {
  Lcd.Cursor(0,0);
  Lcd.Display("Humidity:"); 
  Lcd.Cursor(0,9);
  Lcd.DisplayNum(dht.readHumidity());
  Lcd.Cursor(0,12);
  Lcd.Display("%RH");
  
  Lcd.Cursor(2,0);
  Lcd.Display("Temperature:");
  Lcd.Cursor(2,12);
  Lcd.DisplayNum(dht.readTemperature());
  Lcd.Cursor(2,15);
  Lcd.Display("C");
  delay(200);
}
//**********************************************************************************
