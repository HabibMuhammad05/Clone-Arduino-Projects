#define LEDPin1 A5
#define gnd A4
#define LEDPin2 1
#define gnd2 0

void setup() {
pinMode(LEDPin1, OUTPUT);
pinMode(gnd, OUTPUT);
digitalWrite(gnd, LOW);
pinMode(LEDPin2, OUTPUT);
pinMode(gnd2, OUTPUT);
digitalWrite(gnd, LOW);
}

void loop() {
  
  analogWrite(LEDPin1, 200);
  delay(5);
digitalWrite(LEDPin1, LOW);
  delay(900);

  analogWrite(LEDPin2, 200);
  delay(5);
    digitalWrite(LEDPin2, LOW);
  delay(785);
}
