#ifndef CALIBRACAO_H
#define CALIBRACAO_H

#include "Refletancia.h"
#include "sensor_cor.h"
#include <robo_hardware.h> 
#include <Servo.h>

class Calibracao{                 //classe "Calibracao"
//Dentro da classe esta a declaraçao das variveis(atribuitos) usadas, sendo elas:
//privadas(private)- as variaveis ou as funçes, so podem ser acessado apenas pela classe
//publicos(public)- as variaveis ou as funçoes, pode ser acessado por qualquer outra classe

  private: 
    Refletancia EsqDefinitivo;      //sensor de refletancia esquerdo, ele eh uma "struct", ou seja, dentro dele tem a variavel "branco" e "preto"
    Refletancia DirDefinitivo;      //sensor de refletancia direito,  ele eh uma "struct", ou seja, dentro dele tem a variavel "branco" e "preto"
    float media_esq;                //variavel que armazena o valor calibrado do sensor de refletancia "ESQUERDO"
    float media_dir;                //variavel que armazena o valor calibrado do sensor de refletancia "DIREITO"
    float media_mais_esq;           //armazena o valor calibrado do sensor de refletancia "MAIS ESQUERDO"
    float media_mais_dir;           //armazena o valor calibrado do sensor de refletancia "MAIS DIREITO"
    char S;                         //variavel responsavel por sair do laço
    bool sair_menu_calibra = false; //variavel para sair do menur de calibracao
    
  public:
    void calibraCorEsquerdo(SensorDeCor sensorCor);
    void calibraCorDireito(SensorDeCor sensorCor);
    void espera();
    void menu_geral(SensorDeCor sensorEsquerdo, SensorDeCor sensorDireito);
    void menu_cor(SensorDeCor sensorEsquerdo, SensorDeCor sensorDireito);
    void menu_refletancia();                    //declaraçao da funçao "menu", ou seja, a funçao principal da classe calibracao
    void calibra_refletancia_E();   //declaraçao da funçao para calibrar o sensor de refletancia "ESQUERDO", ele retorna a media calculada no sensor esquerdo
    void calibra_refletancia_D();   //declaraçao da funçao para calibrar o sensor de refletancia "DIREITO", retorna a media calculada
    void calibra_refletancia_mais_E();//declaraçao da funçao para calibrar o sensor de refletancia "MAIS ESQUERDO", retorna a media calculada
    void calibra_refletancia_mais_D();//declaraçao da funçao para calibrar o sensor de refletancia "MAIS DIREITO", retorna a media calculada
    char escolhaCor();                //declaraçao da funçao que pergunta qual cor vc deseja, preto ou branco
    bool calibraSensor(float valorAtual, char espera_ler, Refletancia &Definitivo);//funçao que faz a calibraçao dos sensores de refletancia
    float descubraMaior(float valor1, float valor2);//declaraçao da funçao que retorna qual o maior valor
    float descubraMenor(float valor1, float valor2);//declaraçao da funçao que retorna qual o menor valor
    char esperaLer();               //declaraçao da funçao que aguarda alguma coisa ser digitada
    calibracao_dados valor;    //declaraçao da classe que armazena os valores calibrados na EEPROM do Arduino
    
    float getRefletanciaEsq(){return media_esq;} //declaraçao do get e set que retorna a media calculada no sensor de refletancia "ESQUERDO"
    float getRefletanciaDir(){return media_dir;} //declaraçao do get e set que retorna a media calculada no sensor de refletancia "DIREITO"
    float getRefletanciaMaisEsq(){return media_mais_esq;} //declaraçao do get e set que retorna a media calculada no sensor de refletancia "MAIS ESQUERDO"
    float getRefletanciaMaisDir(){return media_mais_dir;} //declaraçao do get e set que retorna a media calculada no sensor de refletancia "MAIS DIREITO"
//FUNCIONALIDADE DO "SET" E "GET": 
//o set serve para você passar um valor para um atributo(variavel) privado da classe no qual você não tem acesso
//o get serve para você retornar o valor  
};  

#endif
