/*------------DFPlayer All Audio Play-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.0---------------------------*/
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial playercomms(10, 11);
DFRobotDFPlayerMini mp3;
static unsigned long timer = millis();

void setup(){
  playercomms.begin(9600);
  Serial.begin(9600);
  
  mp3.begin(playercomms);
  mp3.volume(30);  //0-30
  mp3.play(1);  //Play the first mp3
}

void loop(){
  if (millis() - timer > 6000) {
    timer = millis();
    mp3.next();  //Play next mp3 every 3 second.
  }
}
