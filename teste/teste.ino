#include <robo_hardware2.h>
#include <Servo.h>
#include "sensores.h"
#include "Estrategia.h"

Estrategia escolha;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
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
