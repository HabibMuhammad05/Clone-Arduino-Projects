
/*----------------L293D MOTOR DRIVER-------------------*/
/*-------------Source Code by---------------------------*/
/*------Modified & Adapted by Habib.m @Hab_mz-----------*/
/*-----------------------V1.3---------------------------*/
#define in1 10
#define in2 11
#define en1 2

const int speedStep =15;
const int speedDelay = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en1, OUTPUT);
 
}

void loop() {
 for(int speed=0; speed<=255; speed +=speedStep){
  L293D('L',speed, 1); 
  delay(speedDelay);
 }
  delay(50);
}


void L293D(char dir,int spd, int en){
  
  if(dir =='L'){
    if(en ==0){
       Serial.println(" CW Motor Stopped");
    }
    else{
       Serial.print(" Rotating CW: "); 
       Serial.println(spd);      
    }
    digitalWrite(en1 ,en); 
    analogWrite(in1,spd);
    digitalWrite(in2,LOW);
  }

  else{
    if(en ==0){
       Serial.println(" CCW Motor Stopped");
    }
    else{
       Serial.print(" Rotating CCW: "); 
       Serial.println(spd);  
    }    
    digitalWrite(en1 ,en); 
    digitalWrite(in1,LOW);
    analogWrite(in2,spd);
  }
}

/*------------------v1.0-----------------*
 
   int LFor = 11;
   int RFor = 9;
   
void setup() {
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);

void loop() {
  Maju();
  delay(1000);
  Kanan();
  delay(1000);
  Kiri();
  delay(1000);
  Mundur();
  delay(1000);
  Stop();
  delay(1000);
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


//---------------------------------------v1.1----------------------------

int RFor = 5;
int RBac = 4;
int LFor = 3;
int LBac = 2;
void setup() {
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
  pinMode(LBac, OUTPUT);
  pinMode(RBac, OUTPUT);

}

void loop() {
  Maju();
  delay(1000);
  Kanan();
  delay(1000);
  Kiri();
  delay(1000);
  Mundur();
  delay(1000);
  Stop();
  delay(1000);
}



void Stop(){
  
  digitalWrite(RFor, LOW);
  digitalWrite(LFor, LOW);
  
  digitalWrite(RBac, LOW);
  digitalWrite(LBac, LOW);
}

void Maju(){
  
  digitalWrite(RFor, HIGH);
  digitalWrite(LFor, HIGH);
  
  digitalWrite(RBac, LOW);
  digitalWrite(LBac, LOW);
}

void Mundur(){
  
  digitalWrite(RFor, LOW);
  digitalWrite(LFor, LOW);
  
  digitalWrite(RBac, HIGH);
  digitalWrite(LBac, HIGH);
}

void Kanan(){
  
  digitalWrite(RFor, LOW);
  digitalWrite(LFor, HIGH);
  
  digitalWrite(RBac, HIGH);
  digitalWrite(LBac, LOW);
}

void Kiri(){
  
  digitalWrite(RFor, HIGH);
  digitalWrite(LFor, LOW);
  
  digitalWrite(RBac, LOW);
  digitalWrite(LBac, HIGH);
}
*/
