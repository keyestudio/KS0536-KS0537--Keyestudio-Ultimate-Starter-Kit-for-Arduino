//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 31.2
Intelligent_access_control_system
http//www.keyestudio.com
*/
#include <Wire.h>
#include "MFRC522_I2C.h"
#include <Servo.h>
#define SERVO_PIN 9
#define USER_NUM 4

byte servoRun = 0;
byte userCard[USER_NUM][4] = {  // card storage array
  {77,   82,   132,  2},
  {211,  144,  216,  8},
  {57,  182,  70,  194}
};

// 0x28 is i2c address on SDA. Check your address with i2cscanner if not match.
// MFRC522 mfrc522(0x28, RST_PIN);   // Create MFRC522 instance.
MFRC522 mfrc522(0x28);   // Create MFRC522 instance.
 
void setup() { 
  Serial.begin(115200);           // Initialize serial communications with the PC
  Wire.begin();                   // Initialize I2C
  mfrc522.PCD_Init();              // Initialize MFRC522 
  pinMode(SERVO_PIN, OUTPUT);   // servo controld the port
}
 
void loop() {
  if(servoRun == 1){            // If the servo running variable is 1, it will run. 
    servoControl();             // the function to ocntrol the servo
  }
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) return;       // find cards
  if ( ! mfrc522.PICC_ReadCardSerial())   return;       // 验证NUID是否可读
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  // check MIFARE type
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println("Can identify this card!");
    return;
  }
  
  byte i;
  for (i=0; i<USER_NUM;  i++){    // 
    byte i2;
    for(i2=0;  i2<4; i2++){       // 
      if(mfrc522.uid.uidByte[i2] != userCard[i][i2]) break;  // when it is break，this card is not verified
    }
    if(i2 == 4){                  // when i2 is 4，which indicates that the four-digit value of this card has been verified. 
      Serial.println("Find an accessful card.");  // output the successful information
      servoRun = 1;               // set the variable of opening the door to 1
      break;                      // find the pass card, exit the loop.
    }
  }
  if(i==USER_NUM){                // If i is equal to the number of users, the upper loop does not find the pass card. 
    Serial.print("Find a unknown card, its uid:");
    for(i=0;  i<4;  i++){         // output UID
      Serial.print(mfrc522.uid.uidByte[i], DEC);
      Serial.print(" ");
    }
    Serial.println();
  }
  
  mfrc522.PICC_HaltA();              // Make the IC card placed in the card reading area enter the dormant state, no longer repeat the card reading 
  mfrc522.PCD_StopCrypto1();         // stop to code the card-reading module

}


void servoControl(){              // servo controls functions
  Serial.println("Servo run!");   // output sign to output the function
  servoPulse(0);                  // servo rotate to 0°
  delay(500);                    // wait the servo to rotate
  servoPulse(180);                // servo rotate to 180°
  servoRun = 0;                   // set the variable of running the servo to 0
}

void servoPulse(int myangle)      //Define an impulse function 
{
  int pulseWidth=(myangle*11)+500;// convert the angle to the pulse width of 500-2480
  digitalWrite(SERVO_PIN,HIGH);   //  set the port of the servo to high
  delayMicroseconds(pulseWidth);  // delay the time of the pulse width
  digitalWrite(SERVO_PIN,LOW);    // set the port of the servo to low
  delay(20-pulseWidth/1000);
}
//**********************************************************************************
