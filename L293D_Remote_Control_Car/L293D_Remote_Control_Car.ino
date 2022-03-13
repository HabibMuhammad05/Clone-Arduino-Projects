/*--- -Bluetooth Controlled Car W/ L293D Driver-----*/
/*---------Source Code by Habib.m @Hab_mz------------*/
/*------Modified & Adapted by Habib.m @Hab_mz--------*/
/*----------------------V1.1-------------------------*/
const int derek=8;
int RFor = 5;
int RBac = 4;
int LFor = 3;
int LBac = 2;
void setup() {
  Serial.begin(9600);
  pinMode(derek,OUTPUT);
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
  pinMode(LBac, OUTPUT);
  pinMode(RBac, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    char data = Serial.read();
    switch(data){
    //derek
      case '0':
        digitalWrite(derek,HIGH);//mati
        break;
      case '1':
        digitalWrite(derek,LOW);//hidup
        break;  
    //Mundur
      case '3':
        Mundur();
        break;
    //MAJU
      case '4':
        Maju();
        break;
    //stop
      case '5':
        Stop();
        break;
    //Belok kanan
      case '6':
        Kanan();
        break;
    //Belok kiri
      case '7':
        Kiri();
        break;
    //darurat
      case '8':
        Stop();
        digitalWrite(derek,HIGH);
        break;
      default:
        break;
      }
    Serial.print(data);
  }
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
