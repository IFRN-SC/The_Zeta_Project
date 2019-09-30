#include "Estrategia.h"
#include "sensores.h"
#include "sensor_cor.h"
#include <robo_hardware2.h>

int led=1;
int led2=2;
int led3=3;
#define DELAY_TIME 500
Estrategia::Estrategia(){
  valor_sensor_sonar_frontal = 100000000;
  valor_sensor_sonar_lateral_Esquerdo = 100000000;
  valor_sensor_sonar_lateral_Direito = 100000000;
}

void Estrategia::calibrar(boolean realizarCalibracao){        //"calibrar" eh funçao da classe "Estrategia"
  if(realizarCalibracao){                                     //se realizarCalibraçao ele vai chamar a funçao calibrar
      sensor.calibrar();                                      //objeto "sensor" da classe "sensores", chama a funçao "calibrar"
  }
  else{                                                       //senao realizarCalibraçao
      sensor.semCalibracao();                                 //objeto "sensor" da classe "sensores", chama a funçao "semcalibrar"
  }  
}

void Estrategia::execute(){                                   //"execute" eh funçao da classe "Estrategia", para o robo executar alguma açao
  valor_sensor_sonar_frontal = robo.lerSensorSonarFrontal();
  valor_sensor_sonar_lateral_Esquerdo = robo.lerSensorSonarEsq();
  valor_sensor_sonar_lateral_Direito =  robo.lerSensorSonarDir();

  seguir_linha();   
  
  if((valor_sensor_sonar_frontal > 1) && (valor_sensor_sonar_frontal < 3)){
    robo.ligarLed(led2);
    contornarObstaculo();
   } 
  if((valor_sensor_sonar_lateral_Esquerdo > 1 && valor_sensor_sonar_lateral_Esquerdo < 10)){
     subir_rampa();      
 }
}
void Estrategia::piscarLeds(){
  while(true){
      robo.acionarMotores(0,0);
      for(int led=1; led<=3; led++){
        robo.ligarLed(led);
        delay(DELAY_TIME);
      }
      for(int led=1; led<=3; led++){
        robo.desligarLed(led);
        delay(DELAY_TIME);
      }
      for(int led=3; led<=1; led--){
        robo.ligarLed(led);
        delay(DELAY_TIME);
      }
      for(int led=3; led<=1; led--){
        robo.desligarLed(led);
        delay(DELAY_TIME);
      }
    
      for(int i=0; i<2; i++){ 
      robo.ligarTodosLeds();
      delay(DELAY_TIME/2);
    
      robo.desligarTodosLeds();
      delay(DELAY_TIME/2);
      }  
      }
}
void Estrategia::seguir_linha(){ 
  if (sensor.deve_seguir_em_frente()){                           //"deve_seguir_linha" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(40,40);
  }
    else if(sensor.deve_corrigir_esquerda()){                   //"deve_corrigir_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(-30,30);                           //se a esquerda tiver vendo preto, ele vai girar a roda esquerda para tras e direita para frente
    }
    else if(sensor.deve_corrigir_direita()){                    //"deve_corrigir_direita" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(30, -30);                           //se a direita tiver vendo preto, ele vai girar a roda esquerda para frente e direita para tras
  }else if(sensor.deve_girar_a_esquerda()){
      robo.acionarMotores(0,0);
      robo.acionarMotores(-10,-10);
      robo.acionarMotores(10,10);
      testar_verde();                                        //testa se esta vendo verde ou nao
      
      while(!sensor.branco_branco_branco_branco()){
        robo.acionarMotores(50,50);
      }
      while(sensor.eh_branco_esquerdo()){
        robo.acionarMotores(-30, 30);  
      }
      while(!sensor.eh_branco_esquerdo()){
        robo.acionarMotores(-30, 30);  
      }
      
  }else if(sensor.deve_girar_a_direita()){
    robo.acionarMotores(0,0);
    robo.acionarMotores(-10,-10);
      robo.acionarMotores(10,10);
    testar_verde();                                    //testa se esta vendo verde ou nao
    
    while (!sensor.branco_branco_branco_branco()){
      robo.acionarMotores(50,50);
    }
    while (sensor.eh_branco_direito()){
      robo.acionarMotores(30, -30);  
    }
    while (!sensor.eh_branco_direito()){
      robo.acionarMotores(30, -30);  
    }    
  }else if(sensor.branco_preto_preto_branco()){
    robo.acionarMotores(30, -30);
  }
}

 void Estrategia::testar_verde(){
  //piscarLeds();

  if(sensor.eh_verde_esquerdo() && sensor.eh_verde_direito()){
    robo.acionarMotores(-40,40);
    delay(1000);
     robo.acionarMotores(25,25);
    
  }
 if (sensor.deve_girar_a_esquerda()){
     delay(1000);  
     if(sensor.eh_verde_esquerdo()){
         girar_esquerdo_verde();
     }   //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
     else{
       while(sensor.preto_preto_branco_branco()){             //enquanto ele ver preto_preto_branco_branco, ele vai para frente por 100 milisegundos
          robo.acionarMotores(30,30);
          delay (100);
       }
       while(sensor.branco_branco_branco_branco()){            //enquanto ele ver todos branco, ele vai girar pro lado esquerdo
           robo.acionarMotores(-30,30); 
       }
       while(sensor.preto_preto_branco_preto() || sensor.preto_preto_branco_branco()){//enquanto ele preto_preto_branco_preto, ele vai girar um pouco pra direita e voltar a seguir em frente
          robo.acionarMotores(30,-30);
          delay (200);
          robo.acionarMotores(30,30);
       }
    }
  }
  
   if (sensor.deve_girar_a_direita()){                    //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
     if(sensor.eh_verde_direito()){
     
         //robo.acionarMotores(30, -30);
         girar_direito_verde();
     }    //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
     else{
       while  (sensor.branco_branco_preto_preto()){             //enquanto ele ver branco_branco_preto_preto, ele vai para frente por 100 milisegundos
          robo.acionarMotores(40,40);	
          delay (100);
       }
       while (sensor.branco_branco_branco_branco()){            //enquanto ele ver todos branco, ele vai girar pro lado direito
         robo.acionarMotores(40,-40); 
          
       }
       while (sensor.preto_branco_preto_preto() || sensor.branco_branco_preto_preto()){//enquanto ele branco_branco_preto_preto, ele vai girar um pouco pra esquerda e voltar a seguir em frente
          robo.acionarMotores(-40,40);
          delay (200);
  	robo.acionarMotores(40,40);
       }
     }
   }
  else if(sensor.encruzilhada()){
       robo.acionarMotores(0,0);     
         if(sensor.eh_verde_esquerdo()){
           girar_esquerdo_verde();
         }
         else if(sensor.eh_verde_direito()){
           girar_direito_verde();
         }
         else{
           robo.acionarMotores(40,40);
         }  
   }

   else if(sensor.branco_branco_preto_branco()){
         girar_direito_verde();
   }
   else if(sensor.branco_preto_branco_branco()){
         girar_esquerdo_verde();
   }
}

void Estrategia::girar_esquerdo_verde(){
    while(sensor.eh_preto_esquerdo()){
      robo.ligarLed(led2);
      robo.acionarMotores(30,-30);
    }
    while(sensor.eh_branco_esquerdo()){
      robo.acionarMotores(30,-30);
    }
}

void Estrategia::girar_direito_verde(){
    robo.ligarLed(led);
    while(sensor.eh_preto_direito()){
      robo.acionarMotores(-35, 35);
    }
    while(sensor.eh_branco_direito()){
      robo.acionarMotores(-35, 35);
    }
}

// NÃO ESTAMOS UTILIZANDO ESSA FUNÇÃO
/*void Estrategia::alinhaObstaculo(){
  robo.ligarLed(led2);
  	if (sensor.branco_branco_branco_preto() || sensor.branco_branco_preto_preto() || sensor.branco_preto_preto_preto() || 
              sensor.branco_preto_branco_preto() || sensor.preto_branco_preto_preto() || sensor.branco_branco_preto_branco()){ 
  	    robo.acionarMotores(-20,20);
  	} else if (sensor.preto_branco_branco_branco() || sensor.preto_preto_branco_branco() || sensor.preto_preto_preto_branco() || 
              sensor.preto_branco_preto_branco() || sensor.preto_preto_branco_preto() || sensor.branco_preto_branco_branco()){
  	    robo.acionarMotores(20, -20); 
  	}
}   
*/      
      
void Estrategia::contornarObstaculo(){
   robo.acionarMotores(0, 0);//vai para um tempo
   delay(1000);     
   robo.acionarMotores(-20, -20);//da rer um pouco
   delay(400);
   robo.acionarMotores(0, 0);
   delay(1000);  
   robo.acionarMotores(-25,25);
   delay(1000);   
      
   robo.acionarMotores(0, 0);
   delay(1000); 
   
   /* Testado sem isso
     while (!(sensor.preto_branco_branco_branco())){
        robo.acionarMotores(-20,10);
   }
      
   robo.acionarMotores(0, 0);
   delay(1000); 

   while(!(sensor.eh_preto_mais_direito())){
        robo.acionarMotores(0,0);
   }*/
    
   robo.desligarLed(led);
   robo.acionarMotores(25, 25);//anda em paralelo ao robo
   delay(1200);
   robo.acionarMotores(0, 0);
   delay(1100);    
   robo.acionarMotores(30, -30);//gira para ficar pra frente
   delay(600);
   robo.acionarMotores(0, 0);
   delay(1000); 
   robo.acionarMotores(35, 35);//anda pra frente, lado a lado ao robo
   delay(1400);
   robo.acionarMotores(0, 0);
   delay(1000);    
   robo.acionarMotores(30, -30);//gira para ficar de lado
   delay(600);
   robo.acionarMotores(0, 0);
   delay(1000); 

   while (sensor.branco_branco_branco_branco()){
    robo.acionarMotores(30, 30);
   }
   
   while (!sensor.branco_branco_preto_branco()){
   robo.acionarMotores(0,0);
   }
   robo.acionarMotores(0,0);
}

void Estrategia::subir_rampa(){
  /*robo.acionarMotores(30,-30);
  delay(250);

  while((!robo.fimDeCurso1Pressionado()) && (!robo.fimDeCurso2Pressionado()) ) {
     robo.acionarMotores(-30,-30);
  }*/
  int valor_sensor_sonar_lateral_Esquerdo = robo.lerSensorSonarEsq();
  //FALTA ADICIONAR NO WHILE A UTILIZAÇÃO DO SENSOR SONAR ESQUERDO
  while(((valor_sensor_sonar_lateral_Esquerdo > 1 && valor_sensor_sonar_lateral_Esquerdo < 10))){
    robo.ligarLed(led3);
    if(sensor.branco_branco_branco_branco()){
      robo.acionarMotores(60, 60);
    }else if(sensor.branco_branco_preto_branco() ||
             sensor.branco_branco_preto_preto()  ||
             sensor.branco_branco_branco_preto()){
      robo.acionarMotores(55,-40);
    }else if(sensor.branco_preto_branco_branco() ||
             sensor.preto_preto_branco_branco()  ||
             sensor.preto_branco_branco_preto()){
      robo.acionarMotores(-40, 65);
    }else{
      robo.acionarMotores(40, 40);
    }
    valor_sensor_sonar_lateral_Esquerdo= robo.lerSensorSonarEsq();
  }
  robo.desligarLed(led3);
  robo.acionarMotores(60, 60);
  delay(400);
  robo.acionarMotores(20, 20);
  while(1);
  resgate.alinhar(); 
}

 
