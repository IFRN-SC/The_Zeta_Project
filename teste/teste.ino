#include <robo_hardware.h>
#include <Servo.h>
#include "sensores.h"
#include "Estrategia.h"

Estrategia escolha;

void setup(){
  robo.configurar(false);
  Serial.begin(9600);
  escolha.calibrar(true);
}

void loop(){
  escolha.execute();
}
