int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;

int in1_2 = 4;
int in2_2 = 5;
int in3_2 = 6;
int in4_2= 7;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  
  pinMode(in1_2,OUTPUT);
  pinMode(in2_2,OUTPUT);
  pinMode(in3_2,OUTPUT);
  pinMode(in4_2,OUTPUT);

}

void loop() {
 l293d_1();
}

void l293d_1(){
//  MAJU
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
//  MAJU
  digitalWrite(in1_2,HIGH);
  digitalWrite(in2_2,LOW);
  digitalWrite(in4_2,HIGH);
  digitalWrite(in3_2,LOW);
  delay(1500);
  
//MUNDUR
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
//MUNDUR
  digitalWrite(in1_2,LOW);
  digitalWrite(in2_2,HIGH);
  digitalWrite(in4_2,LOW);
  digitalWrite(in3_2,HIGH);
  delay(1500);

//KANAN
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
//KANAN
  digitalWrite(in1_2,HIGH);
  digitalWrite(in2_2,LOW);
  digitalWrite(in4_2,LOW);
  digitalWrite(in3_2,HIGH);
  delay(1500);

//  KIRI
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
//  KIRI
  digitalWrite(in1_2,LOW);
  digitalWrite(in2_2,HIGH);
  digitalWrite(in4_2,HIGH);
  digitalWrite(in3_2,LOW);
  delay(1500);

//  STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);
//  STOP
  digitalWrite(in1_2,LOW);
  digitalWrite(in2_2,LOW);
  digitalWrite(in4_2,LOW);
  digitalWrite(in3_2,LOW);
  delay(1500);
}

void l293d_2(){
//  MAJU
  digitalWrite(in1_2,HIGH);
  digitalWrite(in2_2,LOW);
  digitalWrite(in4_2,HIGH);
  digitalWrite(in3_2,LOW);

  delay(1500);
  
//MUNDUR
  digitalWrite(in1_2,LOW);
  digitalWrite(in2_2,HIGH);
  digitalWrite(in4_2,LOW);
  digitalWrite(in3_2,HIGH);

  delay(1500);

//KANAN
  digitalWrite(in1_2,HIGH);
  digitalWrite(in2_2,LOW);
  digitalWrite(in4_2,LOW);
  digitalWrite(in3_2,HIGH);

  delay(1500);

//  KIRI
  digitalWrite(in1_2,LOW);
  digitalWrite(in2_2,HIGH);
  digitalWrite(in4_2,HIGH);
  digitalWrite(in3_2,LOW);

  delay(1500);
  
//  STOP
  digitalWrite(in1_2,LOW);
  digitalWrite(in2_2,LOW);
  digitalWrite(in4_2,LOW);
  digitalWrite(in3_2,LOW);

  delay(1500);
}
