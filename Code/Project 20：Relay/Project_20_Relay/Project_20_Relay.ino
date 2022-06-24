//**********************************************************************************
/*
Keyestudio 2021 Starter Kit
Project 20
Relay
http//www.keyestudio.com
*/
int Relay = 3; // defines digital 3
void setup()
{
pinMode(Relay, OUTPUT); // sets "Relay" to "output"
}
void loop()
{
digitalWrite(Relay, HIGH); // turns on the relay
delay(2000); //delays 2 seconds
digitalWrite(Relay, LOW); // turns off the relay
delay(2000); // delays 2 seconds
}
//**********************************************************************************
