//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 32.1
4x4_Keypad_display
http//www.keyestudio.com
*/
#include <Keypad.h>
const byte ROWS = 4; // define the row 4
const byte COLS = 4; // define the row 4 
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
//  connect the port of 4*4 keypad to the corresponding digital port of the control board
byte rowPins[ROWS] = {2,3,4,5};
// connect the port of 4*4 keypad to the corresponding digital port of the control board
byte colPins[COLS] = {6,7,8,9};
// call on the corresponding functions from libraries
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey();
if (key != NO_KEY){
Serial.println(key);
}
}
//**********************************************************************************
