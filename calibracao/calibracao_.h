#ifndef CALIBRACAO_H
#define CALIBRACAO_H

#include "Refletancia.h"
#include <robo_hardware2.h> 
#include <Servo.h>

class Calibracao{
private: 
  Refletancia EsqDefinitivo;      //definindo sensor de refletancia esquerdo
  Refletancia DirDefinitivo;      //definindo sensor de refletancia direito
  float calibra_esq;                     //variavel que armazena o valor calibrado do esquerdo
  float calibra_dir;                     //variavel que armazena o valor calibrado do direito
  char S;                                //variavel responsavel por sair do laço;
  bool sair_menu_calibra = false;
  
public:
  void menu();
  void calibra_refletancia_E();
  void calibra_refletancia_D();
  char escolhaCor();
  bool calibraSensor(float valorAtual, char espera_ler, Refletancia &Definitivo);
  float descubraMaior(float valor1, float valor2);
  float descubraMenor(float valor1, float valor2);
  char esperaLer(); 
};  

#endif


