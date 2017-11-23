#include <robo_hardware2.h>
#include <Servo.h>
#include "sensores.h"
#include "Estrategia.h"

Estrategia escolha;

void setup(){
  robo.configurar(false);
  Serial.begin(9600);
  escolha.calibrar(false);
}

void loop(){
  escolha.execute();
}
