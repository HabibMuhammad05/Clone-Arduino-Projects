
#include <TimerOne.h>

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial playercomms(2,3);
DFRobotDFPlayerMini mp3;

#include <MD_MAX72xx.h>
#define MAX_DEVICES  4
#define DELAYTIME  100
MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, 10, MAX_DEVICES);

void setup() {
  mx.begin();
  Serial.begin(9600);
  playercomms.begin(9600);
  
  pinMode(7, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
  
  
  mp3.begin(playercomms);
  mp3.volume(20);  //0-30
  
  Timer1.initialize(10000); 
  Timer1.attachInterrupt( PIR_START ); 

}

void loop() {
     scrollText("Hello!   ");
     delay(500);
     spiral(35);
     stripe(50);
}

void PIR_START(){
  if(digitalRead(7) == LOW){
  digitalWrite(A0,HIGH);
  }else{
    digitalWrite(A0,LOW);
  }
  delay(100);
}
