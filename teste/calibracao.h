#ifndef CALIBRACAO_H
#define CALIBRACAO_H

#include "Refletancia.h"
#include <robo_hardware2.h> 
#include <Servo.h>

class Calibracao{
private: 
  Refletancia EsqDefinitivo;      //definindo sensor de refletancia esquerdo
  Refletancia DirDefinitivo;      //definindo sensor de refletancia direito
  float media_esq;                     //variavel que armazena o valor calibrado do esquerdo
  float media_dir;                     //variavel que armazena o valor calibrado do direito
  float media_mais_esq;
  float media_mais_dir;
  char S;                                //variavel responsavel por sair do laço;
  bool sair_menu_calibra = false;
  
public:
  void menu();
  void calibra_refletancia_E();
  void calibra_refletancia_D();
  void calibra_refletancia_mais_E();
  void calibra_refletancia_mais_D();
  char escolhaCor();
  bool calibraSensor(float valorAtual, char espera_ler, Refletancia &Definitivo);
  float descubraMaior(float valor1, float valor2);
  float descubraMenor(float valor1, float valor2);
  char esperaLer(); 
  
  float getRefletanciaEsq(){return media_esq;}
  float getRefletanciaDir(){return media_dir;}
  //float getRefletanciaMaisEsq(){return media_mais_esq;}
  //float getRefletanciaMaisDir(){return media_mais_dir;}
  
};  

#endif


