/*-----Single Servo Control With MIT App Inventor--------*/
/*---Source Code by Dejan, www.HowToMechatronics.com ----*/
/*---------Modified & Adapted by Habib.m @Hab_mz---------*/
/*-------------------------V1.1--------------------------*/

#include <Servo.h>
Servo ser1;
int ser1PPos = 90;
int spd = 5;
int val;
void setup() {
  Serial.begin(9600);
  ser1.attach(9);
  ser1.write(ser1PPos);
}

void loop() {
  if(Serial.available()>0){
    val = Serial.read();
    Serial.println(" ");
    Serial.println(val);
    int ser1pos = val;
    ser1pos = map(ser1pos, 0, 82, 0, 180);
    Serial.println("Servo1");
    Serial.println(ser1pos);
       if(ser1PPos > ser1pos) {
          for( int j = ser1PPos; j >= ser1pos; j--){
               ser1.write(j);
               delay(spd);}}
       if(ser1PPos < ser1pos) {
          for( int j = ser1PPos; j <= ser1pos; j++){
              ser1.write(j);
              delay(spd);}}
       ser1PPos = ser1pos;
  }}
  
/*------------------@Hab_mz--------------------*/
/*-------------------V1.0----------------------
if(Serial.available()>0){
    val = Serial.read();
    Serial.println(val);
    val = map(val, 0, 255, 0, 180);
    ser1.write(val);      
    delay(15); } */
/*------------------@Hab_mz--------------------*/
