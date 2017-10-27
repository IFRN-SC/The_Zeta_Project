#include "calibracao.h"
#include <robo_hardware2.h>
#include <Servo.h>

media_calibracao valor;

void Calibracao::menu(){  //funçao principal
  bool sair_menu = false;
    while(!sair_menu){                                           //laço para menu principal
      Serial.println("### DIGITE A OPCAO DESEJADA ###");
      Serial.println("            ");
      Serial.println("Calibrar SENSOR DE REFLETANCIA");
      Serial.println("Para o ESQUERDO aperte E "); //avisa qual letra apertar para calibrar o esquerdo
      Serial.println("Para o DIREITO aperte D");                 //avisa qual letra apertar para calibrar o direito
      Serial.println("Para o MAIS ESQUERDO aperte M");                 //avisa qual letra apertar para calibrar o mais esquerdo
      Serial.println("Para o MAIS DIREITO aperte N");                 //avisa qual letra apertar para calibrar o mais direito
      Serial.println("            ");
      
      char espera_ler = esperaLer();
      
      switch(espera_ler){
        
        case 'E':
            calibra_refletancia_E();
            break;
        case 'D':
            calibra_refletancia_D();
            break;
        case 'M':    
            calibra_refletancia_mais_E();
            break;
        case 'N':
            calibra_refletancia_mais_D();
            break;
        case 'S':
          sair_menu=true;
          
      }
    }

}

void Calibracao::calibra_refletancia_E(){           //laço para calibrar o sensor de refletancia esquerdo
  Refletancia EsqDefinitivo;
  EsqDefinitivo.preto=0;
  EsqDefinitivo.branco=100;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
    Serial.println("CALIBRACAO DO SENSOR ESQUERDO");
    calibraSensor(robo.lerSensorLinhaEsq(), escolhaCor(), EsqDefinitivo);
  }
  
  media_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.5;
  Serial.print("Valor Calibrado no sensor Esquerdo ");
  Serial.println(media_esq); 
  Serial.println("           ");
  
  valor.refletancia_esq= media_esq;
  robo.salvarCalibracao(valor);
}

void Calibracao::calibra_refletancia_D(){           //laço para calibrar o sensor de refletancia esquerdo
  Refletancia DirDefinitivo;
  DirDefinitivo.preto=0;
  DirDefinitivo.branco=100;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
    Serial.println("CALIBRACAO DO SENSOR DIREITO");
    calibraSensor(robo.lerSensorLinhaDir(), escolhaCor(), DirDefinitivo);
  }
  
  media_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.5;
  Serial.print("Valor Calibrado no sensor Direito ");
  Serial.println(media_dir); 
  Serial.println("           ");
  
  valor.refletancia_dir= media_dir;
  robo.salvarCalibracao(valor);
}

void Calibracao::calibra_refletancia_mais_E(){           //laço para calibrar o sensor de refletancia esquerdo
  Refletancia EsqDefinitivo;
  EsqDefinitivo.preto=0;
  EsqDefinitivo.branco=100;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
    Serial.println("CALIBRACAO DO SENSOR MAIS ESQUERDO");
    calibraSensor(robo.lerSensorLinhaEsq(), escolhaCor(), EsqDefinitivo);
  }
  
  media_mais_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.5;
  Serial.print("Valor Calibrado no sensor Mais Esquerdo ");
  Serial.println(media_mais_esq); 
  Serial.println("           ");
  
  valor.refletancia_mais_esq= media_mais_esq;
  robo.salvarCalibracao(valor);  
}

void Calibracao::calibra_refletancia_mais_D(){           //laço para calibrar o sensor de refletancia esquerdo
  Refletancia DirDefinitivo;
  DirDefinitivo.preto=0;
  DirDefinitivo.branco=100;
  sair_menu_calibra = false;
  
  while(!sair_menu_calibra){
    Serial.println("CALIBRACAO DO SENSOR MAIS DIREITO");
    calibraSensor(robo.lerSensorLinhaDir(), escolhaCor(), DirDefinitivo);
  }
  
  media_mais_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.5;
  Serial.print("Valor Calibrado no sensor Mais Direito ");
  Serial.println(media_mais_dir); 
  Serial.println("           ");
  
  valor.refletancia_mais_dir= media_mais_dir;
  robo.salvarCalibracao(valor);
}

char Calibracao::escolhaCor(){
  Serial.println("Para calibrar no PRETO aperte P");
  Serial.println("Para calibrar no BRANCO aperte B");
  Serial.println("Para sair aperte S");
  Serial.println("           "); 
   char espera_ler = esperaLer();
   
   return espera_ler;
}

bool Calibracao::calibraSensor(float valorAtual, char espera_ler, Refletancia &Definitivo){
   sair_menu_calibra = false;
    switch(espera_ler){
      
      case 'P':
        Serial.print("Esquerdo preto atual é: ");          
        Serial.println(valorAtual); //imprime na tela o valor lido no esquerdo no preto
        Definitivo.preto = descubraMaior(Definitivo.preto, valorAtual);
        break;
        
      case 'B':
        Serial.print("Esquerdo branco atual é: ");
        Serial.println(valorAtual); //imprime na tela o valor lido no esquerdo no branco
        Definitivo.branco = descubraMenor(Definitivo.branco, valorAtual);
        break;
        
      case 'S':
        sair_menu_calibra = true;
        break;
   } 
  Serial.print("EsqDefinitivo.preto"); 
  Serial.println(Definitivo.preto);
  Serial.print("EsqDefinitivo.branco");
  Serial.println(Definitivo.branco);  
    return sair_menu_calibra;
}

float Calibracao::descubraMaior(float valor1, float valor2){  //funçao para encontrar o maior valor, usada para achar o maior preto
  if(valor2 > valor1){ 
    valor1=valor2;;    //armazena maior valor de preto
  }
  return valor1;
}

float Calibracao::descubraMenor(float valor1, float valor2){  //funçao para encontrar o menor valor, usada para achar o menor branco
 if(valor2 < valor1){ 
    valor1=valor2;;   //armazena menor valor de branco
  }
  return valor1;
}

char Calibracao::esperaLer(){
    while(!Serial.available()){
    }
    return Serial.read();
}

