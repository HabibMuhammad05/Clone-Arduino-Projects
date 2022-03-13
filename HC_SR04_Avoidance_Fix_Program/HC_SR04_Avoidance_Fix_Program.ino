/*---------------Obstacle Avoidance Robot----------------*/
/*-----------Source Code by by Habib.m @Hab_mz-----------*/
/*---------Modified & Adapted by Habib.m @Hab_mz---------*/
/*-------------------------V1.0--------------------------*/
#include <NewPing.h>
#include <Servo.h>

#define trig 11
#define echo 12
#define maxi 200
NewPing sen(trig, echo, maxi);

int RFor = 5;
int RBac = 4;
int LFor = 3;
int LBac = 2;
int Jarak = 100;
boolean KeMaju = false;
Servo servo;

void setup() {
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
  pinMode(LBac, OUTPUT);
  pinMode(RBac, OUTPUT);

  servo.attach(10);
  servo.write(90); delay(2000);
  Jarak = Ping();delay(100);
  Jarak = Ping();delay(100);
  Jarak = Ping();delay(100);
  Jarak = Ping();delay(100);
  
}

void loop() {
  int Kan = 0;
  int Kir = 0;
  delay(50);

  if (Jarak <= 20){
    Stop();
    delay(300);
    Mundur();
    delay(400);
    Stop();
    delay(300);
    Kan = CekKan();
    delay(300);
    Kir = CekKir();
    delay(300);

    if (Jarak >= Kir){
      BelKan();
      Stop();
    }
    else{
      BelKir();
      Stop();
    }
  }
  else{
    Maju(); 
  }
    Jarak = Ping();   
}

int CekKan(){  
  servo.write(10);
  delay(500);
  int Jarak = Ping();
  delay(100);
  servo.write(90);
  return Jarak;
}

int CekKir(){
  servo.write(170);
  delay(500);
  int Jarak = Ping();
  delay(100);
  servo.write(90);
  return Jarak;
  delay(100);
}

int Ping(){
  delay(70);
  int cm = sen.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void Stop(){
  
  digitalWrite(RFor, LOW);
  digitalWrite(LFor, LOW);
  digitalWrite(RBac, LOW);
  digitalWrite(LBac, LOW);
}

void Maju(){

  if(!KeMaju){

    KeMaju=true;
    
    digitalWrite(LFor, HIGH);
    digitalWrite(RFor, HIGH);
  
    digitalWrite(LBac, LOW);
    digitalWrite(RBac, LOW); 
  }
}

void Mundur(){

  KeMaju=false;

    digitalWrite(LFor, LOW);
    digitalWrite(RFor, LOW);
  
    digitalWrite(LBac, HIGH);
    digitalWrite(RBac, HIGH);
}

void BelKan(){

  digitalWrite(LFor, HIGH);
  digitalWrite(RFor, LOW);
  
  digitalWrite(LBac, LOW);
  digitalWrite(RBac, HIGH);
  
  delay(500);
  
  digitalWrite(LFor, HIGH);
  digitalWrite(RFor, HIGH);
  
  digitalWrite(LBac, LOW);
  digitalWrite(RBac, LOW);
}

void BelKir(){
  
  digitalWrite(LFor, LOW);
  digitalWrite(RFor, HIGH);
  
  digitalWrite(LBac, HIGH);
  digitalWrite(RBac, LOW);

  delay(500);
  
  digitalWrite(LFor, HIGH);
  digitalWrite(RFor, HIGH);
  
  digitalWrite(LBac, LOW);
  digitalWrite(RBac, LOW);
}
/*---------------------@Hab_Mz-----------------------*/
