// Los contactos en uno = activados.
int s_paro;
int s_marcha;
int s_final_carrera_1;
int s_final_carrera_2;
int s_final_carrera_3;
int s_final_carrera_4;
//
int paro=2;
int marcha=3;

int piston_subida=4;
int piston_avance=5;
int piston_vacio=6;

int final_carrera_1=7;  // Reposo, final carrera subida 
int final_carrera_2=8;  // Activado, final carrera subida 

int final_carrera_3=9;  // Reposo, final carrera avance
int final_carrera_4=10; // Activado, final carrera avance

int proceso=0; //Variable proceso


void setup() {
Serial.begin(9600);
pinMode(paro,INPUT);
pinMode(marcha,INPUT);
pinMode(piston_avance,OUTPUT);
pinMode(piston_subida,OUTPUT);
pinMode(piston_vacio,OUTPUT);
pinMode(final_carrera_1,INPUT);
pinMode(final_carrera_2,INPUT);
pinMode(final_carrera_3,INPUT);
pinMode(final_carrera_4,INPUT);
}



void loop() {
 lectura();
 escritura();
 if (s_paro==LOW && s_marcha==HIGH && s_final_carrera_1==HIGH && s_final_carrera_3==HIGH && 
 s_final_carrera_2==LOW && s_final_carrera_4==LOW && proceso==0) {
 
  digitalWrite(piston_avance,HIGH);
  digitalWrite(piston_subida,LOW);
  digitalWrite(piston_vacio,LOW);
  proceso=1;
 }
 lectura();
 escritura();
 if (s_final_carrera_1==HIGH && s_final_carrera_3==LOW && 
 s_final_carrera_2==LOW && s_final_carrera_4==HIGH && proceso==1) {
  
  digitalWrite(piston_avance,HIGH);
  digitalWrite(piston_subida,LOW);
  digitalWrite(piston_vacio,HIGH);
  delay(10000);
  proceso=2;
 }
  lectura();
  escritura();
if (s_final_carrera_1==HIGH && s_final_carrera_3==HIGH && 
 s_final_carrera_2==LOW && s_final_carrera_4==LOW && proceso==2) {
 
  digitalWrite(piston_avance,LOW);
  digitalWrite(piston_subida,LOW);
  digitalWrite(piston_vacio,HIGH);
  proceso=3;
 }
  lectura();
  escritura();
 if (s_final_carrera_1==LOW && s_final_carrera_3==HIGH && 
 s_final_carrera_2==HIGH && s_final_carrera_4==LOW && proceso==3) {
 
  digitalWrite(piston_avance,LOW);
  digitalWrite(piston_subida,HIGH);
  digitalWrite(piston_vacio,HIGH);
  proceso=4;
 }
  lectura();
  escritura();
 if (s_final_carrera_1==LOW && s_final_carrera_3==LOW && 
 s_final_carrera_2==HIGH && s_final_carrera_4==HIGH && proceso==4) {
 
  digitalWrite(piston_avance,HIGH);
  digitalWrite(piston_subida,HIGH);
  digitalWrite(piston_vacio,HIGH);
  delay(20000);
  proceso=5;
 }
  lectura();
  escritura();
 if (s_final_carrera_1==LOW && s_final_carrera_3==LOW && 
 s_final_carrera_2==HIGH && s_final_carrera_4==HIGH && proceso==5) {
 
  digitalWrite(piston_avance,HIGH);
  digitalWrite(piston_subida,HIGH);
  digitalWrite(piston_vacio,LOW);
  delay(5000);
  proceso=6;
  
 }
  lectura();
  escritura();
 if (s_final_carrera_1==LOW && s_final_carrera_3==HIGH && 
 s_final_carrera_2==HIGH && s_final_carrera_4==LOW && proceso==6) {
 
  digitalWrite(piston_avance,LOW);
  digitalWrite(piston_subida,HIGH);
  digitalWrite(piston_vacio,LOW);
  delay(5000);
  proceso=7;
 }
  lectura();
  escritura();
 if (s_final_carrera_1==HIGH && s_final_carrera_3==HIGH && 
 s_final_carrera_2==LOW && s_final_carrera_4==LOW && proceso==7) {
 
  digitalWrite(piston_avance,LOW);
  digitalWrite(piston_subida,LOW);
  digitalWrite(piston_vacio,LOW);
  proceso=0;
 }

}


void lectura() {
  s_paro=digitalRead(paro);
  s_marcha=digitalRead(marcha);
 // s_piston_subida=digitalRead(piston_lateral);
 // s_piston_avance=digitalRead(piston_avance);
  //s_piston_vacio=digitalRead(piston_vacio);
  s_final_carrera_1=digitalRead(final_carrera_1);
  s_final_carrera_2=digitalRead(final_carrera_2);
  s_final_carrera_3=digitalRead(final_carrera_3);
  s_final_carrera_4=digitalRead(final_carrera_4);
}

void escritura() {
  Serial.print(s_paro);
  Serial.print(s_marcha);
  Serial.print(s_final_carrera_1);
  Serial.print(s_final_carrera_2);
  Serial.print(s_final_carrera_3);
  Serial.print(s_final_carrera_4);
  Serial.println(proceso);
}
