/*------------------------MILLIS(); execution---------------------------*/
/*----------------Source Code by Life Tech @Youtube---------------------*/
/*--------------Modified & Adapted by Habib.m @Hab_mz-------------------*/
/*------------------------------V1.1------------------------------------*/
/*----------------------------------------------------------------------*/
unsigned long waktu1=0;
unsigned long waktu2=0;
int led1=13;
int led2=12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
unsigned long waktusekarang = millis();
if(waktusekarang-waktu1>= 1000){
  //Keadaan 1
  waktu1=millis();
}
if(waktusekarang-waktu2>= 500){
  //Keadaan 2
  waktu2=millis();
}
}

/*---------------------@Hab_Mz-----------------------*/
