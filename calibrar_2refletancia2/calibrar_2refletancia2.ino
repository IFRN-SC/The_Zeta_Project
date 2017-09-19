#include <robo_hardware2.h> 
#include <Servo.h>


char C;                   //variavel que armazena a tecla apertada
char S;       //variavel responsavel por sair do laço;
float esquerdo_preto_definitivo;
float esquerdo_preto_atual;
float esquerdo_branco_definitivo;
float esquerdo_branco_atual;
float direito_branco_definitivo;
float direito_branco_atual;
float direito_preto_definitivo;
float direito_preto_atual;
float calibra_esq;
float calibra_dir;
boolean sair_menu;
boolean sair_menu_calibra_e;
boolean sair_menu_calibra_d;

float descubra_maior(float valor1, float valor2){
  if(valor2 > valor1){ 
    valor1=valor2;;  //maior preto
  }
  return valor1;
}

float descubra_menor(float valor1, float valor2){
  if(valor2 < valor1){ 
    valor1=valor2;;  //menor branco
  }
  return valor1;
}

void menu(){
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

void calibra_refletancia_E(){
  while(!sair_menu_calibra_e){
      Serial.println("CALIBRACAO DO SENSOR ESQUERDO");
      Serial.println("Para calibrar no PRETO aperte P");
      Serial.println("Para calibrar no BRANCO aperte B");
      Serial.println("Para sair aperte S");
      C=esperaLer();
      
      switch(C){
        
        case 'P':
          esquerdo_preto_atual = robo.lerSensorLinhaEsq();
          Serial.print("Esquerdo preto atual é: ");          
          Serial.println(esquerdo_preto_atual); //imprime na tela o valor lido no esquerdo no preto
          esquerdo_preto_definitivo = descubra_maior(esquerdo_preto_definitivo, esquerdo_preto_atual);
          break;
          
        case 'B':
          esquerdo_branco_atual = robo.lerSensorLinhaEsq();
          Serial.print("Esquerdo branco atual é: ");
          Serial.println(esquerdo_branco_atual); //imprime na tela o valor lido no esquerdo no branco
          esquerdo_branco_definitivo = descubra_menor(esquerdo_branco_definitivo, esquerdo_branco_atual);
          break;
          
        case 'S':
          sair_menu_calibra_e  = true;
          break;
        
      }
      
  }
  
      calibra_esq= (esquerdo_preto_definitivo + esquerdo_branco_definitivo)/2;
      Serial.print("Valor Calibrado no sensor Esquerdo ");
      Serial.println(calibra_esq);
}


void calibra_refletancia_D(){
  while(!sair_menu_calibra_d){
      Serial.println("CALIBRACAO DO SENSOR DIREITO");
      Serial.println("Para calibrar no PRETO aperte P");
      Serial.println("Para calibrar no BRANCO aperte B");
      Serial.println("Para sair aperte S");
      C=esperaLer();
      
      switch(C){
        
        case 'P':
          direito_preto_atual = robo.lerSensorLinhaDir();
          Serial.print("Direito preto atual é: ");          
          Serial.println(direito_preto_atual); //imprime na tela o valor lido no esquerdo no preto
          direito_preto_definitivo = descubra_maior(direito_preto_definitivo, direito_preto_atual);
          break;
          
        case 'B':
          direito_branco_atual = robo.lerSensorLinhaDir();
          Serial.print("Direito branco atual é: ");
          Serial.println(direito_branco_atual); //imprime na tela o valor lido no esquerdo no branco
          direito_branco_definitivo = descubra_menor(direito_branco_definitivo, direito_branco_atual);
          break;
          
        case 'S':
          sair_menu_calibra_d  = true;
          break;
        
      }
      
  }
      calibra_dir = (direito_branco_definitivo + direito_preto_definitivo)/2;
      Serial.print("Valor Calibrado no sensor direito ");
      Serial.println(calibra_dir);
}


char esperaLer(){
    while(!Serial.available()){
      
    }
    return Serial.read();
}

void setup()
{
  Serial.begin(9600);
  robo.configurar(false);
  
  while (!Serial) {
     ;
  }
  
  menu();
}


void loop()
{
                
}

