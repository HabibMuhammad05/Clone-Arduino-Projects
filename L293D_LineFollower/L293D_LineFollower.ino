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

int R_S = 2;
int C_S = 3;
int L_S = 4;
 
void setup() {
  Serial.begin(9600);
  pinMode(pwmL,OUTPUT);
  pinMode(ForL,OUTPUT);
  pinMode(BacL,OUTPUT);
  pinMode(ForR,OUTPUT);
  pinMode(BacR,OUTPUT);
  pinMode(pwmR,OUTPUT);
  
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

void maju(){
  digitalWrite(ForL,HIGH);
  digitalWrite(ForR,HIGH);
  analogWrite(pwmL, 125);
  analogWrite(pwmR, 120);
}

void kanan(int spdkir, int spdkan){
  digitalWrite(ForL,HIGH);
  digitalWrite(ForR,HIGH);
  analogWrite(pwmL, spdkir);
  analogWrite(pwmR, spdkan);
}

void kiri(int spdkir2, int spdkan2){
  digitalWrite(ForL,HIGH);
  digitalWrite(ForR,HIGH);
  analogWrite(pwmL, spdkir2);
  analogWrite(pwmR, spdkan2);
}
void berhenti(){
  digitalWrite(ForL,LOW);
  digitalWrite(ForR,LOW);
  digitalWrite(BacL,LOW);
  digitalWrite(BacR,LOW);

  analogWrite(pwmL, 0);
  analogWrite(pwmR, 0);
}
