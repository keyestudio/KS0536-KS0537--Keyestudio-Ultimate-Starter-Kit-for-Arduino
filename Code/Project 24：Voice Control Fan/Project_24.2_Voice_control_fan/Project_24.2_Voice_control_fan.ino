//**********************************************************************************
/*
Keyestudio 2021 Starter Kit
Project 24.2
Voice control fan
http//www.keyestudio.com
*/
void setup() {
  Serial.begin(9600);
  pinMode(A3, OUTPUT);//sets digital A3 to "output"
  pinMode(A2, OUTPUT);//sets digital A2 to "output"
}
void loop() {
  int Soundvalue = analogRead(A1);  // reads the analog value
  Serial.println(Soundvalue);
  if(Soundvalue>700)
  {
   // when the analog value is greater than the set value, starts the motor
   digitalWrite(A3,HIGH);
   digitalWrite(A2,LOW);
   for(int i=0;i<5;i++){
   delay(5000);                    //  waits 5 seconds
   }
  }
  else{
   // closes the motor
   digitalWrite(A3,LOW);
   digitalWrite(A2,LOW);
    }
}
//**********************************************************************************
