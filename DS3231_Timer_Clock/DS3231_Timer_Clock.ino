/*----------------DS3231_Timer_Clock-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/
#include <DS3231.h>

int Relay = 4;

DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 10;
const int OnMin = 14;
const int OffHour = 12;
const int OffMin = 25;
const int OnHour2 = 12;
const int OnMin2 = 24;
const int OffHour2 = 12;
const int OffMin2 = 25;


void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(Relay, OUTPUT);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  delay (1000);
  
  if(t.hour == OnHour && t.min == OnMin){
    digitalWrite(Relay,LOW);
    Serial.println("LIGHT ON");
    }
    
    else if(t.hour == OffHour && t.min == OffMin){
      digitalWrite(Relay,LOW);
      Serial.println("LIGHT OFF");
    }
  if(t.hour == OnHour2 && t.min == OnMin2){
    digitalWrite(Relay,HIGH);
    Serial.println("LIGHT ON");
    }
    
    else if(t.hour == OffHour2 && t.min == OffMin2){
      digitalWrite(Relay,LOW);
      Serial.println("LIGHT OFF");
    }
}
