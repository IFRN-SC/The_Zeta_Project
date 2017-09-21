#include "teste.h"
#include <robo_hardware2.h> 
#include <Servo.h>

SensorRefletancia2 EsqDefinitivo;
SensorRefletancia2 DirDefinitivo;

float calibra_esq;                     //variavel que armazena o valor calibrado do esquerdo
float calibra_dir;                     //variavel que armazena o valor calibrado do direito
char C;                                //variavel que armazena a tecla apertada
char S;                                //variavel responsavel por sair do laço;
boolean sair_menu_calibra = false;

float descubra_maior(float valor1, float valor2){
  if(valor2 > valor1){ 
    valor1=valor2;;    //maior preto
  }
  return valor1;
}

float descubra_menor(float valor1, float valor2){
  if(valor2 < valor1){ 
    valor1=valor2;;   //menor branco
  }
  return valor1;
}

void menu(){
  boolean sair_menu = false;
    while(!sair_menu){
      Serial.print("Para calibrar o sensor ESQUERDO aperte E "); //avisa qual letra apertar para calibrar o esquerdo
      Serial.println("Para o DIREITO aperte D");  //avisa qual letra apertar para calibrar o direito
      
      C=esperaLer();
      
      switch(C){
        
        case 'E':
            calibra_refletancia_E();
            break;
        case 'D':
            calibra_refletancia_D();
            break;
        
        case 'S':
          sair_menu=true;
          
      }
    }
}

void calibra_refletancia_E(){           //laço para calibrar o sensor de refletancia esquerdo
  SensorRefletancia2 EsqDefinitivo;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
  Serial.println("CALIBRAÇAO DO SENSOR ESQUERDO");
  calibraSensor(robo.lerSensorLinhaEsq(), EsqDefinitivo);
  }
  
  calibra_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco)/2;
  Serial.print("Valor Calibrado no sensor Esquerdo ");
  Serial.println(calibra_esq); 
  Serial.println("           ");
}

void calibra_refletancia_D(){           //laço para calibrar o sensor de refletancia esquerdo
  SensorRefletancia2 DirDefinitivo;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
  Serial.println("CALIBRAÇAO DO SENSOR DIREITO");
  calibraSensor(robo.lerSensorLinhaDir(), DirDefinitivo);
  }
  
  calibra_dir= (DirDefinitivo.preto + DirDefinitivo.branco)/2;
  Serial.print("Valor Calibrado no sensor Direito ");
  Serial.println(calibra_dir); 
  Serial.println("           ");
}

boolean calibraSensor(float valorAtual, SensorRefletancia2 &Definitivo){
   sair_menu_calibra = false;
   //while(!sair_menu_calibra){
    Serial.println("Para calibrar no PRETO aperte P");
    Serial.println("Para calibrar no BRANCO aperte B");
    Serial.println("Para sair aperte S");
    Serial.println("           ");
    
    C = esperaLer();
    
    switch(C){
      
      case 'P':
        Serial.print("Esquerdo preto atual é: ");          
        Serial.println(valorAtual); //imprime na tela o valor lido no esquerdo no preto
        Definitivo.preto = descubra_maior(Definitivo.preto, valorAtual);
        break;
        
      case 'B':
        Serial.print("Esquerdo branco atual é: ");
        Serial.println(valorAtual); //imprime na tela o valor lido no esquerdo no branco
        Definitivo.branco = descubra_menor(Definitivo.branco, valorAtual);
        break;
        
      case 'S':
        sair_menu_calibra = true;
        break;
   }  
    //} 
    return sair_menu_calibra;
}

char esperaLer(){
    while(!Serial.available()){
      
    }
    return Serial.read();
}

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
  EsqDefinitivo.preto=0;
  EsqDefinitivo.branco=100;
  DirDefinitivo.preto=0;
  DirDefinitivo.branco=100;

  while (!Serial) {
     ;
  }
  menu();
}


void loop(){               
}
//ERRO1: TEM Q APERTAR PRA CALIBRAR 2 VZS, PARA DAR O VALOR CORRETO
//ERR02: OS RESULTADOS ESTAO DANDO ERRADOS
