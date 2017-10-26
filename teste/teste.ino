#include <robo_hardware2.h>
#include <Servo.h>
#include "sensores.h"

sensores sensores;

void setup(){
  robo.configurar(false);
  sensores.calibrar();
}

void loop(){
}

