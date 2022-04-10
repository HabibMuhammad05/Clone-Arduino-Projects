/*-------------------Keypad_Test------------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

#include <Keypad.h>
 
const byte ROWS = 4; //4 baris
const byte COLS = 4; //4 kolom
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte colPins[COLS] = {5, 4, 3, 2}; // pin 2,3,4,5 untuk pin kolom keypad (lihat gambar)
byte rowPins[ROWS] = {9, 8, 7, 6}; // pin 6,7,8,9 untuk pin baris keypad (lihat gambar)
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup(){
  Serial.begin(9600);
}
 
void loop(){
  char key = keypad.getKey();
  if (key){
    Serial.println(key);
  }
 
}
