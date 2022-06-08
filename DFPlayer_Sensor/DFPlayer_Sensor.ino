#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial playercomms(10, 11);
DFRobotDFPlayerMini player;
void printDetail(uint8_t type, int value);
static unsigned long timer = millis();

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  playercomms.begin(9600);
  Serial.begin(9600);
  
  player.begin(playercomms);
  player.volume(30);  //0-30
}

void loop() {
  if(digitalRead(2) == LOW){
  player.play(6);
  }
  
  else if(digitalRead(3) == LOW){
  player.play(7);
  }
  delay(100);
}
