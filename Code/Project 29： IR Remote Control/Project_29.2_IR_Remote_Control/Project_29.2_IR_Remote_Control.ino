//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 29.2
IR Remote Control
http//www.keyestudio.com
*/
#include <IRremote.h>
int IR_Recv = 11;   //the pin of the IR receiver is 11
int bluePin = 10;
int greenPin = 9;
int yellowPin = 8;
IRrecv irrecv(IR_Recv);
decode_results results;
void setup(){
  Serial.begin(9600);  //start serial communication
  irrecv.enableIRIn(); // start receiving
  pinMode(bluePin, OUTPUT);      // set the digital pin to OUTPUT
  pinMode(greenPin, OUTPUT);      // set the digital pin to OUTPUT
  pinMode(yellowPin, OUTPUT);      // set the digital pin to OUTPUT
}
 void loop(){
  // decode the IR signals input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value,HEX);
    //switch to case to use the selected remote control button
    switch (results.value){
      case  0x00FF6897: //when you press the button 1
        digitalWrite(bluePin, HIGH);
        break;   
      case  0x00FF30CF: //when you press the button 4
        digitalWrite(bluePin, LOW);   
        break;
       case 0x00FF9867: //when you press the button 2
        digitalWrite(greenPin, HIGH);
        break;           
       case 0x00FF18E7: //when you press the button 5
        digitalWrite(greenPin, LOW);
        break;       
       case 0x00FFB04F: //when you press the button 3
        digitalWrite(yellowPin, HIGH);
        break;       
       case 0x00FF7A85: //when you press the button 6
        digitalWrite(yellowPin, LOW);
        break;
    }
    irrecv.resume(); // receive the next value
  }
  delay(10);
}
//**********************************************************************************
