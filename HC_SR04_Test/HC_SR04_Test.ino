/*----------------HC_SR04_Test-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.1---------------------------*/

#define echoPin 12 
#define trigPin 11 
#define LEDPin 13 

long duration, distance; 

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);

   if (distance >= 200 || distance <= 00){
     Serial.println("-1");digitalWrite(LEDPin, LOW);
   }
   else {
     Serial.println(distance);
     digitalWrite(LEDPin, HIGH);
     delay(50);
   }
}

/*
 if (distance <= 20){
  digitalWrite(led1, HIGH);
 }
 else {
  digitalWrite(led1, LOW);
 }

 if (distance >= 20){
  digitalWrite(led2, HIGH);
 }
 else {
 digitalWrite(led2, LOW);
 }

/*-----------------------------V2---------------------------------
 #define echoPin 12 
#define trigPin 13 
#define LEDPin 10
#define LEDPin2 9
int maximumRange = 200;
int minimumRange = 00; 
long duration, distance; 

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDPin, OUTPUT);
pinMode(LEDPin2, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);


/*-----------------------------LED1---------------------------------
if (distance >= 25 || distance <= 00){
     Serial.println("tidakSatu");digitalWrite(LEDPin, LOW);
   }
   else {
     Serial.println("satu");
     digitalWrite(LEDPin, HIGH);
   }
/*-----------------------------LED2--------------------------------- 
  if (distance >= 50 || distance <= 26){
     Serial.println("tidakDua");digitalWrite(LEDPin2, LOW);
   }
   else {
     Serial.println("dua");
     digitalWrite(LEDPin2, HIGH);
     delay(50);
   }
}
 */
