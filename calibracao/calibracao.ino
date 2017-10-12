#include <robo_hardware2.h> 
#include <Servo.h>
#include "calibracao_.h"

Calibracao cali;

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
  
  while (!Serial){
     ;
  }
 cali.menu();
}

void loop(){               
}
