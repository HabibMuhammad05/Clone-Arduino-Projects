int pwmL = 9;
int ForL = 10;
int BacL = 8;
int ForR = 13;
int BacR = 12;
int pwmR = 11;

void setup() {
  pinMode(pwmL,OUTPUT);
  pinMode(ForL,OUTPUT);
  pinMode(BacL,OUTPUT);
  pinMode(ForR,OUTPUT);
  pinMode(BacR,OUTPUT);
  pinMode(pwmR,OUTPUT);
}

void loop() {
 maju();
 delay(1000);
 berhenti();
 delay(2500);
 kanan(220, 125);
 delay(500);
 berhenti();
 delay(1000);
 kiri(120, 220);
 delay(500);
 berhenti();
 delay(2500);
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
