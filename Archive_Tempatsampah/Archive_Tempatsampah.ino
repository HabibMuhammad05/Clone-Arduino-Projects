#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(3);
}

void loop() {
  if(digitalRead(2) == LOW){
  myservo.write(180);
  }
  
  else{
  myservo.write(0);
  }
  delay(100);
}
