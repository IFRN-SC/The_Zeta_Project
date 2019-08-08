#include <robo_hardware.h>
#include <Servo.h>
#include "sensores.h"
#include "Estrategia.h"

#define COR_ESQ 50
#define COR_DIR 38

Estrategia escolha;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(COR_ESQ,OUTPUT);
  pinMode(COR_DIR,OUTPUT);
  
  digitalWrite(COR_DIR, HIGH);
  digitalWrite(COR_ESQ, HIGH);
  
  robo.habilitaTCS34();
  
  robo.configurar(false);
  Serial.begin(9600);
  //repetir 10 vezes
  for(int i=0; i<=10; i++){
    if(robo.botao1Pressionado()){
      robo.ligarLed(1);
      delay(100);
      robo.desligarLed(1);
      delay(100);
      escolha.calibrar(true);
      break;
    }
    robo.ligarLed(2);
    delay(100);
    robo.desligarLed(2);
    delay(100);
  }
  escolha.calibrar(false);
}

void loop(){
  escolha.execute();
 
}
