/*
 This is a sample sketch to show how to use the OneButtonLibrary
 to detect double-click events on a button. 
 The library internals are explained at
 http://www.mathertel.de/Arduino/OneButtonLibrary.aspx
  
 Setup a test circuit:
 * Connect a pushbutton to pin A1 (ButtonPin) and ground.
 * The pin 13 (StatusPin) is used for output attach a led and resistor to ground
   or see the built-in led on the standard arduino board.
*/


#include "OneButton.h"
OneButton pb(2, true, true);  //(Pb_Pin;  true = ActiveLow;  true = button PullUp)

bool ledState = false;

void setup(){
  Serial.begin(115200);
  Serial.println("One Button Example");
  pinMode(13, OUTPUT);
  digitalWrite(13, ledState);
  pb.attachClick(singleClick);
  pb.attachDoubleClick(doubleClick); 
  pb.attachLongPressStop(longClick);
  pb.attachMultiClick(multiClick);
}

void loop(){
  pb.tick();
  delay(10);
} 

void singleClick(){
  Serial.println("Single Press Detected!");
  digitalWrite(13, !digitalRead(13));
} 

void doubleClick(){
  Serial.println("Double Press Detected!");
  for(int i=0; i<4; i++){
  digitalWrite(13, !digitalRead(13));
  delay(500);}
} 

void multiClick(){
  Serial.println("Multi Press Detected!");
  for(int i=0; i<6; i++){
  digitalWrite(13, !digitalRead(13));
  delay(500);}
} 

void longClick(){
  Serial.println("Long Press Detected!");
  for(int i=0; i<4; i++){
  digitalWrite(13, !digitalRead(13));
  delay(1000);}
} 


//  ledState = digitalRead(13);
//  digitalWrite(13, !ledState);
