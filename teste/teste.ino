#include <robo_hardware2.h>
#include <Servo.h>
#include "sensores.h"
#include "Estrategia.h"

Estrategia escolha;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  robo.configurar(false);
  Serial.begin(9600);
  escolha.calibrar(true);
}

void loop(){
  escolha.execute();
}
