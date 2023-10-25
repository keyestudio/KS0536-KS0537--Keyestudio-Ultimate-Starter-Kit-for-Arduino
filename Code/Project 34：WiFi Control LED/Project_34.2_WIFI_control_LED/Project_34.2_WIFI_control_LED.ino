//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 34.2
WIFI control LED
http//www.keyestudio.com 
*/
const int ledPin = 13;
char wifiData;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0)
  {
    wifiData = Serial.read();
    Serial.print(wifiData);
    if(wifiData == '#')
    {
      Serial.println("");
    }
    delay(100);
    
    if(wifiData == 'a')
    {
      digitalWrite(ledPin, HIGH);
    }
    else if(wifiData == 'b')
    {
      digitalWrite(ledPin, LOW);
    }
  }
}
//**********************************************************************************
 
