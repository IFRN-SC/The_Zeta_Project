#include <robo_hardware2.h>

void setup() {
  robo.configurar(true); 

}

void loop() {
  robo.acionarServoGarra1(90);
  robo.acionarServoGarra1(0);
  robo.acionarServoGarra2(90);
  robo.acionarServoGarra2(0);

}
