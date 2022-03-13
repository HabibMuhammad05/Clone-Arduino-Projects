/*-------------L298N Line Follower Program----------------*/
/*-------------------Source Code by ----------------------*/
/*---------Modified & Adapted by Habib.m @Hab_mz----------*/
/*-------------------------V1.0---------------------------*/
//https://projectiot123.com/2019/03/25/l298-motor-driver-simulation-in-proteus/


int LFor = 11;
int RFor = 9;



int R_S = 2;
int C_S = 3;
int L_S = 4;
 
void setup() {
  Serial.begin(9600);
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
  pinMode(R_S, INPUT);
  pinMode(C_S, INPUT);
  pinMode(L_S, INPUT);
}
void loop()
{  
if ((digitalRead(L_S)== 0 )&&(digitalRead(C_S)== 1 )&&(digitalRead(R_S)== 0 ))  {Serial.println("Maju"); Maju();}
 
if ((digitalRead(L_S)== 1 )&&(digitalRead(C_S)== 1 )&&(digitalRead(R_S)== 0 ))  {Serial.println("Kiri"); Kiri();}
if ((digitalRead(L_S)== 1 )&&(digitalRead(C_S)== 0 )&&(digitalRead(R_S)== 0 ))  {Serial.println("Kiri"); Kiri();}
 
if ((digitalRead(L_S)== 0 )&&(digitalRead(C_S)== 1 )&&(digitalRead(R_S)== 1 ))  {Serial.println("Kanan");Kanan();}
if ((digitalRead(L_S)== 0 )&&(digitalRead(C_S)== 0 )&&(digitalRead(R_S)== 1 ))  {Serial.println("Kanan");Kanan();}
 
if ((digitalRead(L_S)== 1 )&&(digitalRead(C_S)== 1 )&&(digitalRead(R_S)== 1 ))  {Serial.println("Stop"); Stop();}
}

void Maju(){
  analogWrite(RFor, 127);
  analogWrite(LFor, 127);
}
 
void Kanan(){
  analogWrite(RFor, 127);
  analogWrite(LFor, 255);
}
 
void Kiri(){
  analogWrite(RFor, 255);
  analogWrite(LFor, 127);
}
 
void Stop(){
  analogWrite(RFor, 0);
  analogWrite(LFor, 0);
}
