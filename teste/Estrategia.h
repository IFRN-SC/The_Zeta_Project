#include <robo_hardware2.h>
#include <Servo.h>
#include "sensores.h"

class Estrategia{
  public:
  void execute(); 
  void calibrar(boolean);
  
  private:
  sensores sensor;
};




