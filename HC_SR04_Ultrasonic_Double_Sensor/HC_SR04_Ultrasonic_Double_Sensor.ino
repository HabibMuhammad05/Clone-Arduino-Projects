#define gnd2 6
#define echo1 5 
#define trig1 4
#define vcc 3 

#define gnd2 A3
#define echo2 A2 
#define trig2 A1
#define vcc2 A0

long duration,distance, sen1,sen2;

void setup() {
  Serial.begin (9600);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);

  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(vcc2, OUTPUT);
  pinMode(gnd2, OUTPUT);
  digitalWrite(vcc2, HIGH);
  digitalWrite(gnd2, LOW);
}

void loop() {
  hitung(trig1,echo1);
  sen1 = distance;
  hitung(trig2,echo2);
  sen2 = distance;

  Serial.println(sen1);
  Serial.println("");
  Serial.println(sen2);
}

void hitung(int tr,int ec){
  digitalWrite(tr, LOW);
  delayMicroseconds(2);
  digitalWrite(tr, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr, LOW);
  duration = pulseIn(ec, HIGH);
  distance = duration/58.2;
}
