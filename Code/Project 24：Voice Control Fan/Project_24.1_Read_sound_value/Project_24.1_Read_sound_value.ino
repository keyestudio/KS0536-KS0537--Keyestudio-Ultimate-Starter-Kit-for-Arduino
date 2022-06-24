//**********************************************************************************
/*
Keyestudio 2021 Starter Kit
Project 24.1
Read_the_sound_sensor_analog_value
http//www.keyestudio.com
*/
int soundpin=A1;// initializes the analog PIN A1 of the sound sensor
int val=0;// initializes the variable "val" with a value of 0
void setup()
{
Serial.begin(9600);// sets baudrate to 9600
}
void loop()
{
val=analogRead(soundpin);// reads the analog value of the sensor and assigns its value to "val"
Serial.println(val);// displays the value of "val"
delay(1000);// waits a second
}
//**********************************************************************************
