#include "sensor_cor.h"

#define AJUSTE_1 5
#define AJUSTE_2 16

SensorDeCor::SensorDeCor(){
  
}

void SensorDeCor::calibra(){
  vCinzaBranco = 50;
  vBrancoVerde = media(branco.v,verde.v) + AJUSTE_2;
  vVerdePreto = preto.v + 5;
  hVerdePreto = media(preto.h,verde.h) + AJUSTE_1 ;
  vBrancoPreto = media(branco.v,preto.v);
  Serial.print("v-Cinza Branco");
  Serial.println(vCinzaBranco);
  Serial.println("    ");
  Serial.print("v-Branco Verde");
  Serial.println(vBrancoVerde);
  Serial.println("    ");
  Serial.print("v-Verde Preto");
  Serial.println(vVerdePreto);
  Serial.println("    ");
  Serial.print("h-Verde Preto");
  Serial.println(hVerdePreto);
  Serial.println("    ");
  Serial.print("v-Branco Preto");
  Serial.println(vBrancoPreto);
}

void SensorDeCor::atualizarHSV(HSV hsvAt){
  hsv = hsvAt;
}
boolean SensorDeCor::ehBranco(){
  return (hsv.v > vCinzaBranco && hsv.v < vBrancoVerde);
}
boolean SensorDeCor::ehPreto(){
  return (hsv.v > vBrancoVerde && hsv.v < vVerdePreto);
}
boolean SensorDeCor::ehVerde(){
  return ( hsv.h < hVerdePreto);
}
boolean SensorDeCor::ehCinza(){
  return(hsv.v < vCinzaBranco);
}


boolean SensorDeCor::ehBranco(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehBranco();
}
boolean SensorDeCor::ehPreto(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehPreto();
}
boolean SensorDeCor::ehVerde(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehVerde();
}
boolean SensorDeCor::ehCinza(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehCinza();
}

// colocanco valores dos sensores de cor 

void SensorDeCor::setBranco(HSV brancoAt){
  branco = brancoAt;

}
void SensorDeCor::setPreto(HSV pretoAt){ 
  preto = pretoAt;
}
void SensorDeCor::setVerde(HSV verdeAt){ 
  verde = verdeAt;
}
void SensorDeCor::setCinza(HSV cinzaAt){
  cinza = cinzaAt;
}


float SensorDeCor:: media(int num1, int num2){ return (num1 + num2)/2; }

void SensorDeCor::calibrar(){
  vCinzaBranco = (cinza.v + branco.v)/2;

}
 //float vCinzaBranco = 50;
 //float vBrancoVerde = 75;
 float hVerdePreto = 40;
 float vBrancoPreto = 86;
