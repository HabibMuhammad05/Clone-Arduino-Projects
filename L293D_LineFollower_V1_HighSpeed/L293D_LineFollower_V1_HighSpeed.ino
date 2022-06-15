/*-------------L298N Line Follower Program----------------*/
/*-------------------Source Code by ----------------------*/
/*---------Modified & Adapted by Habib.m @Hab_mz----------*/
/*-------------------------V1.0---------------------------*/
//https://projectiot123.com/2019/03/25/l298-motor-driver-simulation-in-proteus/


int pwmL = 9;
int ForL = 10;
int BacL = 8;
int ForR = 13;
int BacR = 12;
int pwmR = 11;

int Skanan = 3;
int Stengah = 4;
int SKiri = 2;
 
void setup() {
  Serial.begin(9600);
  pinMode(pwmL,OUTPUT);
  pinMode(ForL,OUTPUT);
  pinMode(BacL,OUTPUT);
  pinMode(ForR,OUTPUT);
  pinMode(BacR,OUTPUT);
  pinMode(pwmR,OUTPUT);
  
  pinMode(Skanan, INPUT);
  pinMode(Stengah, INPUT);
  pinMode(SKiri, INPUT);
}
void loop()
{  
if ((digitalRead(SKiri)== 0 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 0 ))  {Serial.println("Maju"); maju();}
 
if ((digitalRead(SKiri)== 1 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 0 ))  {Serial.println("Kiri"); kiri();}
if ((digitalRead(SKiri)== 1 )&&(digitalRead(Stengah)== 0 )&&(digitalRead(Skanan)== 0 ))  {Serial.println("Kiri"); kiri();}
 
if ((digitalRead(SKiri)== 0 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 1 ))  {Serial.println("Kanan");kanan();}
if ((digitalRead(SKiri)== 0 )&&(digitalRead(Stengah)== 0 )&&(digitalRead(Skanan)== 1 ))  {Serial.println("Kanan");kanan();}
 
if ((digitalRead(SKiri)== 1 )&&(digitalRead(Stengah)== 1 )&&(digitalRead(Skanan)== 1 ))  {Serial.println("Stop"); berhenti();}

}

void maju(){
  digitalWrite(ForL,HIGH);
  digitalWrite(ForR,HIGH);
  digitalWrite(BacL,LOW);
  digitalWrite(BacR,LOW);
  analogWrite(pwmL, 100);
  analogWrite(pwmR, 100);
}

void kanan(){
  digitalWrite(ForL,HIGH);
  digitalWrite(ForR,LOW);
  digitalWrite(BacL,LOW);
  digitalWrite(BacR,HIGH);
  analogWrite(pwmL, 150);
  analogWrite(pwmR, 100);
}

void kiri(){
  digitalWrite(ForL,LOW);
  digitalWrite(ForR,HIGH);
  digitalWrite(BacL,HIGH);
  digitalWrite(BacR,LOW);
  analogWrite(pwmL, 100);
  analogWrite(pwmR, 150);
}
void berhenti(){
  digitalWrite(ForL,LOW);
  digitalWrite(ForR,LOW);
  digitalWrite(BacL,LOW);
  digitalWrite(BacR,LOW);

  analogWrite(pwmL, 0);
  analogWrite(pwmR, 0);
}
