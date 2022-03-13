#define in1 5
#define in2 6
#define in3 7
#define in4 8
#define pwm1 9
#define pwm2 10

void setup() {
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
 pinMode(pwm1,OUTPUT);
 pinMode(pwm2,OUTPUT);

}

void loop() {
  
  maju(5);
  delay(1000);
  maju(125);
  delay(1000);


  mundur(5);
  delay(1000);
  mundur(125);
  delay(1000);

}

void mundur(int spd){
  digitalWrite(in1,HIGH);
  digitalWrite(in4,HIGH);
  
  analogWrite(pwm1,spd);
  analogWrite(pwm2,spd);
  
}

void maju(int spd){
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  
  analogWrite(pwm1,spd);
  analogWrite(pwm2,spd);
}

void kiri(int spd1, int spd2){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  
  analogWrite(pwm1,spd1);
  analogWrite(pwm2,spd2);
}

void kanan(int spd1, int spd2){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  
  analogWrite(pwm1,spd1);
  analogWrite(pwm2,spd2);
}
