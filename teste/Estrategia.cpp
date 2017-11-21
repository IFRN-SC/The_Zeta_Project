#include "Estrategia.h"
#include "sensores.h"
#include "sensor_cor.h"
#include <robo_hardware2.h>

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
  if(valor_sensor_sonar_frontal < 7){
    robo.acionarMotores(0,0);
    delay(500);
    robo.acionarMotores(-30,30);
    delay(800);
    robo.acionarMotores(0,0);
    delay(500);
    while(!sensor.algum_sensor_eh_preto()){
      robo.acionarMotores(-25,-25);
    }
   robo.acionarMotores(0,0);
    delay(500);
     alinhaObstaculo();
   }
  /*else
  if (sensor.deve_seguir_em_frente()){                           //"deve_seguir_linha" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(40,40);
  }
  else if(sensor.deve_corrigir_esquerda()){                   //"deve_corrigir_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(-40, 40);                           //se a esquerda tiver vendo preto, ele vai girar a roda esquerda para tras e direita para frente
  }
  else if(sensor.deve_corrigir_direita()){                    //"deve_corrigir_direita" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(40, -40);                           //se a direita tiver vendo preto, ele vai girar a roda esquerda para frente e direita para tras
  }
  
  else if (sensor.deve_girar_a_esquerda()){                   //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
     while  (sensor.preto_preto_branco_branco()){             //enquanto ele ver preto_preto_branco_branco, ele vai para frente por 100 milisegundos
        robo.acionarMotores(40,40);
        delay (100);
     }
     while (sensor.branco_branco_branco_branco()){            //enquanto ele ver todos branco, ele vai girar pro lado esquerdo
         robo.acionarMotores(-40,40); 
     }
     while (sensor.preto_preto_branco_preto() || sensor.preto_preto_branco_branco()){//enquanto ele preto_preto_branco_preto, ele vai girar um pouco pra direita e voltar a seguir em frente
        robo.acionarMotores(40,-40);
        delay (200);
        robo.acionarMotores(40,40);
     }
  }
  
  else if (sensor.deve_girar_a_direita()){                    //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
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
   }*/
}


void Estrategia::alinhaObstaculo(){
     while(sensor.desalinhado()){
	if (sensor.branco_branco_branco_preto() || sensor.branco_branco_preto_preto() || sensor.branco_preto_preto_preto()){ 
	    robo.acionarMotores(-35, 0); 
	}
	else if (sensor.preto_branco_branco_branco() || sensor.preto_preto_branco_branco() || sensor.preto_preto_preto_branco()){
	    robo.acionarMotores(0, -35); 
	}
     }
}           
      
void Estrategia::contornarObstaculo(){
   robo.acionarMotores(0, 0);
   delay(300);  
   robo.acionarMotores(-35, -35);
   delay(150);
   
   while (!sensor.branco_branco_branco_preto()){
        robo.acionarMotores(-35, 35);
   }
   
   Estrategia::alinhaObstaculo();
   
   robo.acionarMotores(40, 40);
   delay(1300);
   robo.acionarMotores(40, -40);
   delay(810);
   robo.acionarMotores(40, 40);
   delay(1770);
   robo.acionarMotores(40, -40);
   delay(650);
   
   while (sensor.branco_branco_branco_branco()){
	robo.acionarMotores(35, 35);
   }
   robo.acionarMotores(35, 35);
   delay(250);
   
   while (!sensor.branco_branco_preto_branco()){
	robo.acionarMotores(-35, 35);
   }
   
}
 
void Estrategia::girar_esquerdo_verde(){
    while(sensor.eh_preto_esquerdo()){
      robo.acionarMotores(-40, 40);
    }
    while(sensor.eh_branco_esquerdo()){
      robo.acionarMotores(-40, 40);
    }
}

void Estrategia::girar_direito_verde(){
    while(sensor.eh_preto_direito()){
      robo.acionarMotores(40, -40);
    }
    while(sensor.eh_branco_direito()){
      robo.acionarMotores(40, -40);
    }
}
