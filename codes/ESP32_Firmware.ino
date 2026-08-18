#include <ESP32Servo.h>
// noms de mes servos 
Servo coxa1;
Servo femur1;
Servo coxa2;
Servo femur2;
Servo coxa3;
Servo femur3;
Servo coxa4;
Servo femur4;

// declaration de mes broches 
const int PIN_COXA1  = 4;
const int PIN_FEMUR1 = 13;
const int PIN_COXA2  = 16;
const int PIN_FEMUR2 = 14;
const int PIN_COXA3  = 19;
const int PIN_FEMUR3 = 17;
const int PIN_COXA4  = 26;
const int PIN_FEMUR4 = 18;
const int LED_ROUGE = 2;   // arret obstacle
const int LED_VERT =15;    // marche normale

// broches de capteur ultra son
#define trig 32
#define echo 33
#define seuil 15
// fonction pour la position neutre 
void positionNeutre() {
  coxa1.write(150);
  femur1.write(150);
  coxa2.write(30);
  femur2.write(90);
  coxa3.write(120);
  femur3.write(120);
  coxa4.write(90);
  femur4.write(110);
}
//fonction detecteur de l'obstacle
bool obstacle(){
  //variables de utra_son
  long duree;
  float distance;

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duree = pulseIn(echo,HIGH);
  distance = duree*0.0343/2;

  if (distance<=seuil && distance>0){
    return true;
  }else{
    return false;
  }

}
// lever les pattes 1 et 3
void leverPatte1et3(){
  femur1.write(130);
  femur3.write(80);
  delay(500);
}
// avancer la patte 1 et 3 
void avancerPatte1et3(){
  coxa1.write(130);
  coxa3.write(140);
  delay(500);
}
// poser les pattes 1 et  3
void posePatte1et3(){
  femur1.write(150);
  femur3.write(120);
  delay(500);
}
// lever patte 2 et 4
void leverPatte2et4(){
  femur2.write(110);
  femur4.write(130);
  delay(500);
}
// avancer pattes 2 et 4
void avancerPatte2et4() {
  coxa2.write(0);
  coxa4.write(100);
  delay(500);
}
// poser les pattes 2 et 4
void posePatte2et4() {
  femur2.write(90);
  femur4.write(110);
  delay(500);
}
// remettre au sol
void remettrePatte1et3() {
  coxa1.write(150);
  coxa3.write(120);
  delay(500);
}

void remettrePatte2et4() {
  coxa2.write(30);
  coxa4.write(90);
  delay(500);
}

// je configure mes broches 

void setup() {
  Serial.begin(115200);
  coxa1.attach(PIN_COXA1);
  femur1.attach(PIN_FEMUR1);
  coxa2.attach(PIN_COXA2);
  femur2.attach(PIN_FEMUR2);
  coxa3.attach(PIN_COXA3);
  femur3.attach(PIN_FEMUR3);
  coxa4.attach(PIN_COXA4);
  femur4.attach(PIN_FEMUR4);

  // configuration des broches de ultrason
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  //configuration leds
  pinMode(LED_ROUGE,OUTPUT);
  pinMode(LED_VERT,OUTPUT);

  // Mettre le robot debout
  positionNeutre();
  delay(2000);
}

// le mouvement de marche se repete donc jappelle les fonctions cree plus haut dans le void loop
void loop() {
  if(obstacle()==false){
  digitalWrite(LED_ROUGE,LOW);
  digitalWrite(LED_VERT,HIGH);
    // Lever les pattes 1 et 3
  leverPatte1et3();
  // Les pattes 1 et 3 avancent
  avancerPatte1et3();
  // Poser les pattes 1 et 3
  posePatte1et3();
  // Les pattes 2 et 4 poussent le robot
  remettrePatte1et3();
  // Lever les pattes 2 et 4
  leverPatte2et4();
  // Les pattes 2 et 4 avancent
  avancerPatte2et4();
  // Poser les pattes 2 et 4
  posePatte2et4();
  // Revenir à la position de départ
  remettrePatte2et4();
  delay(300);
  }else{
    digitalWrite(LED_VERT,LOW);
    digitalWrite(LED_ROUGE,HIGH);
    positionNeutre();
  }
  delay(500);
}
