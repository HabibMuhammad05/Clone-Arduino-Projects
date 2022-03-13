/*----------------First LED Code-------------------*/
/*---------Source Code by Roboratory --------------*/
/*----Modified & Adapted by Habib.m @Hab_mz--------*/
/*--------------------V1.1-------------------------*/
int LED1 = 9;
int LED2 = 8;
int LED3 = 7;

void setup(){
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
}

void loop(){
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, LOW);
 delay(20);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, HIGH);
 delay(500);
 digitalWrite(LED3, HIGH);
 digitalWrite(LED2, LOW);
 digitalWrite(LED1, LOW);
 delay(2000);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED3, LOW);
 digitalWrite(LED1, LOW);
 delay(500);
}
