#include <robo_hardware2.h>
#include <Servo.h>
#include "sensores.h"
#include "sensor_cor.h"

class Estrategia{              //classe Estrategia
  public:                      //todos as variaveis e funçoes publicas pode ser acessados em outra classe
    Estrategia();
    void execute();              
	void seguirlinha(); // seguir linha é uma função para quando o robô for seguir a linha 
    void calibrar(boolean realizarCalibracao);      //"calibrar" eh uma funçao criada para decidir caso queira calibrar ou nao o robo
    void alinhaObstaculo();
    void contornarObstaculo();
    void girar_esquerdo_verde();
    void girar_direito_verde();
    void rampa();
    
  private:                    //todos as variaveis funçoes privadas s podem ser acessadas na classe em que foi criada
    sensores sensor;            //"sensor"  o objeto da classe "sensores". objeto criado para usar as funçoes criadas dentro da classe "sensores"
    float valor_sensor_sonar_frontal;
    float valor_sensor_sonar_lateral_Esquerdo;
    float valor_sensor_sonar_lateral_Direito;
};





