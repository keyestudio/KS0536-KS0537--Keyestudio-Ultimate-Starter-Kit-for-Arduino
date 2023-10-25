//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 27.2
Control Stepper Motor with Joystick 
http//www.keyestudio.com
*/
const int X_pin = 0; // analog pin A0 is connected to X 
const int Y_pin = 1; // analog pin A1 is connected to Y
int SW_pin = 11;
int X_Rotate;
int Y_Rotate;
//the pin of the stepper motor
const int IN1_pin = 10;
const int IN2_pin = 9;
const int IN3_pin = 6;
const int IN4_pin = 5;
void setup() {
//set the pin of the joystic module
pinMode(SW_pin, INPUT);
digitalWrite(SW_pin, HIGH);
//set the pin of the stepper motor
pinMode(IN1_pin,OUTPUT);
pinMode(IN2_pin,OUTPUT);
pinMode(IN3_pin,OUTPUT);
pinMode(IN4_pin,OUTPUT);
}
void loop() {
X_Rotate = analogRead(X_pin);
Y_Rotate = analogRead(Y_pin);
if (Y_Rotate < 500) {
digitalWrite(IN1_pin, HIGH);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, LOW);
delay((Y_Rotate/2)+2);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, HIGH);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, LOW);
delay((Y_Rotate/2)+2);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, HIGH);
digitalWrite(IN4_pin, LOW);
delay((Y_Rotate/2)+2);
digitalWrite(IN1_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN4_pin, HIGH);
delay((Y_Rotate/2)+2);
}
else if (Y_Rotate > 550){
digitalWrite(IN4_pin, HIGH);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
delay((1028-Y_Rotate)/2);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, HIGH);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
delay((1028-Y_Rotate)/2);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, HIGH);
digitalWrite(IN1_pin, LOW);
delay((1028-Y_Rotate)/2);
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, HIGH);
delay((1028-Y_Rotate)/2);
}
else if (Y_Rotate > 500 && Y_Rotate < 550) {
digitalWrite(IN4_pin, LOW);
digitalWrite(IN3_pin, LOW);
digitalWrite(IN2_pin, LOW);
digitalWrite(IN1_pin, LOW);
}}
//**********************************************************************************
