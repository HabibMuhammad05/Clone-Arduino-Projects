int pwm1 = 9;
int in1 = 8;
int in2 = 10;
int in3 = 12;
int in4 = 13;
int pwm2 = 11;

void setup() {
  pinMode(pwm1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(pwm2,OUTPUT);
}

void loop() {
 maju(255);
 delay(1000);
 berhenti();
 delay(500);
 mundur(255);
 delay(1000);
 berhenti();
 delay(500);
 kanan(255, 100);
 delay(1000);
 berhenti();
 delay(500);
 kiri(100, 255);
 delay(1000);
 berhenti();
 delay(1500);
}

void mundur(int spdmundur){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
  
  analogWrite(pwm1, spdmundur);
  analogWrite(pwm2, spdmundur);
}
void maju(int spdmaju){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  
  analogWrite(pwm1, spdmaju);
  analogWrite(pwm2, spdmaju);
}
void kanan(int spdkir, int spdkan){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);

  analogWrite(pwm1, spdkir);
  analogWrite(pwm2, spdkan);
}
void kiri(int spdkir2, int spdkan2){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);

  analogWrite(pwm1, spdkir2);
  analogWrite(pwm2, spdkan2);
}
void berhenti(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);

  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}
