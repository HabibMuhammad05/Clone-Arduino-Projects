/*-----Ultrasonic Sensor object Detection W/ LED-----*/
/*---------Source Code by Habib.m @Hab_mz------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.0-------------------------*/
#include <Servo.h>
#define echoPin 13 
#define trigPin 12
#define vcc 11
#define LEDPin1 7
#define LEDPin2 6
#define LEDPin3 5
#define LEDPin4 4
long duration, distance; 
Servo servo;
void setup() {
servo.attach(6);
Serial.begin (9600);
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(LEDPin1, OUTPUT);
pinMode(LEDPin2, OUTPUT);
pinMode(LEDPin3, OUTPUT);
pinMode(LEDPin4, OUTPUT);
pinMode(vcc, OUTPUT);
digitalWrite(vcc, HIGH);
}

void loop() {
  for (int pos = 15; pos <= 165; pos ++) { 
    servo.write(pos);           
    delay(20);  
    distance = hitung(); 
    Serial.println(distance);
    Serial.println("");
    /*-----------------------------LED1---------------------------------*/
    if (distance >= 20 || distance <= 00){
     Serial.println("-");
     digitalWrite(LEDPin1, LOW);
    }
      else {
       Serial.println("satu");
       digitalWrite(LEDPin1, HIGH);
      }  
    /*-----------------------------LED2--------------------------------- */
        if (distance >= 40 || distance <= 21){
         Serial.println("-");
         digitalWrite(LEDPin2, LOW);
        }
          else {
           Serial.println("dua");
           digitalWrite(LEDPin2, HIGH);
          }
    /*-----------------------------LED3--------------------------------- */
        if (distance >= 60 || distance <= 41){
         Serial.println("-");
         digitalWrite(LEDPin3, LOW);
        }
          else {
           Serial.println("tiga");
           digitalWrite(LEDPin3, HIGH);
          }
    /*-----------------------------LED4--------------------------------- */
        if (distance >= 400 || distance <= 61){
         Serial.println("-");
         digitalWrite(LEDPin4, LOW);
        }
          else {
           Serial.println("skip");
           digitalWrite(LEDPin4, HIGH);
          }   
  }
  for (int pos = 165; pos <= 15; pos --) { 
    servo.write(pos);            
    distance = hitung(); 
    Serial.println(distance);
    Serial.println(""); 
    /*-----------------------------LED1---------------------------------*/
    if (distance >= 20 || distance <= 00){
     Serial.println("-");
     digitalWrite(LEDPin1, LOW);
    }
      else {
       Serial.println("satu");
       digitalWrite(LEDPin1, HIGH);
      }  
    /*-----------------------------LED2--------------------------------- */
        if (distance >= 40 || distance <= 21){
         Serial.println("-");
         digitalWrite(LEDPin2, LOW);
        }
          else {
           Serial.println("dua");
           digitalWrite(LEDPin2, HIGH);
          }
    /*-----------------------------LED3--------------------------------- */
        if (distance >= 60 || distance <= 41){
         Serial.println("-");
         digitalWrite(LEDPin3, LOW);
        }
          else {
           Serial.println("tiga");
           digitalWrite(LEDPin3, HIGH);
          }
    /*-----------------------------LED4--------------------------------- */
        if (distance >= 400 || distance <= 61){
         Serial.println("-");
         digitalWrite(LEDPin4, LOW);
        }
          else {
           Serial.println("skip");
           digitalWrite(LEDPin4, HIGH);
          }
  }
}

int hitung(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  delay(5);
  return distance;
}
/*-------------------------------@Hab_mz--------------------------------*/
