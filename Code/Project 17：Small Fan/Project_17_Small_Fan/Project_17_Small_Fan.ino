//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 17
Small_Fan
http//www.keyestudio.com
*/
void setup(){
  pinMode(A3, OUTPUT);//set A3 to OUTPUT
  pinMode(A2, OUTPUT);//set A2 to OUTPUT
}
void loop(){
//Set to rotate for 3000ms anticlockwise
  digitalWrite(A3,LOW);
  digitalWrite(A2,HIGH);
  delay(3000);
//et to stop rotating for 1000ms anticlockwise
  digitalWrite(A3,LOW);
  digitalWrite(A2,LOW);
  delay(1000);
//Set to rotate for 3000ms clockwise
  digitalWrite(A3,HIGH);
  digitalWrite(A2,LOW);
  delay(3000);
}
//********************************************************************************
