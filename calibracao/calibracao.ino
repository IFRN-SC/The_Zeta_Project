#include "teste.h"
#include <robo_hardware2.h> 
#include <Servo.h>

SensorRefletancia2 EsqDefinitivo;
SensorRefletancia2 DirDefinitivo;

float calibra_esq;                     //variavel que armazena o valor calibrado do esquerdo
float calibra_dir;                     //variavel que armazena o valor calibrado do direito
char S;                                //variavel responsavel por sair do laço;
boolean sair_menu_calibra = false;

float descubra_maior(float valor1, float valor2){
  if(valor2 > valor1){ 
    valor1=valor2;;    //armazena maior valor de preto
  }
  return valor1;
}

float descubra_menor(float valor1, float valor2){
  if(valor2 < valor1){ 
    valor1=valor2;;   //armazena menor valor de branco
  }
  return valor1;
}

void menu(){
  boolean sair_menu = false;
    while(!sair_menu){
      Serial.print("Para calibrar o sensor ESQUERDO aperte E "); //avisa qual letra apertar para calibrar o esquerdo
      Serial.println("Para o DIREITO aperte D");  //avisa qual letra apertar para calibrar o direito
      
      char C=esperaLer();
      
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

char escolhaCor(){
  Serial.println("Para calibrar no PRETO aperte P");
  Serial.println("Para calibrar no BRANCO aperte B");
  Serial.println("Para sair aperte S");
  Serial.println("           "); 
   char C = esperaLer();
   
   return C;
}

void calibra_refletancia_E(){           //laço para calibrar o sensor de refletancia esquerdo
  SensorRefletancia2 EsqDefinitivo;
  EsqDefinitivo.preto=0;
  EsqDefinitivo.branco=100;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
    Serial.println("CALIBRAÇAO DO SENSOR ESQUERDO");
    calibraSensor(robo.lerSensorLinhaEsq(), escolhaCor(), EsqDefinitivo);
  }
  
  calibra_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.7;
  Serial.print("Valor Calibrado no sensor Esquerdo ");
  Serial.println(calibra_esq); 
  Serial.println("           ");
}

void calibra_refletancia_D(){           //laço para calibrar o sensor de refletancia esquerdo
  SensorRefletancia2 DirDefinitivo;
  DirDefinitivo.preto=0;
  DirDefinitivo.branco=100;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
    Serial.println("CALIBRAÇAO DO SENSOR DIREITO");
    calibraSensor(robo.lerSensorLinhaDir(), escolhaCor(), DirDefinitivo);
  }
  
  calibra_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.7;
  Serial.print("Valor Calibrado no sensor Direito ");
  Serial.println(calibra_dir); 
  Serial.println("           ");
}

boolean calibraSensor(float valorAtual, char C, SensorRefletancia2 &Definitivo){
   sair_menu_calibra = false;
   //while(!sair_menu_calibra){
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
  Serial.print("EsqDefinitivo.preto"); 
  Serial.println(Definitivo.preto);
  Serial.print("EsqDefinitivo.branco");
  Serial.println(Definitivo.branco); 
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
  
  while (!Serial) {
     ;
  }
  menu();
}


void loop(){               
}
