//*********************************************************************************
/*
Keyestudio 2021 starter learning kit 
Project 15
PIR_control_buzzer
http//www.keyestudio.com
*/

int buzzerpin = 8;  // the pin of the buzzer
int pirPin = 3;     // the pin of the PIR motion sensor
int pirStat = 0;   // the state of the PIR motion sensor
void setup() {
 pinMode(buzzerpin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop()
{
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH)
 {            // if people or moving animals are detected
   digitalWrite(buzzerpin, HIGH);  // the buzzer chirps
   Serial.println("Hey I got you!!!");
 } 
 else {
   digitalWrite(buzzerpin, LOW); // if people or moving animals are not detected, turn off buzzers
 }
}
//*********************************************************************************
