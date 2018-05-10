#include "Estrategia.h"
#include "sensores.h"
#include "sensor_cor.h"
#include <robo_hardware2.h>

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
  
  robo.lerSensorSonarFrontal();
}

void Estrategia::execute(){                                   //"execute" eh funçao da classe "Estrategia", para o robo executar alguma açao
  valor_sensor_sonar_frontal = robo.lerSensorSonarFrontal();
  valor_sensor_sonar_lateral_Esquerdo = robo.lerSensorSonarLateralEsquerdo();
  valor_sensor_sonar_lateral_Direito = robo.lerSensorSonarLateralDireito();

  if((valor_sensor_sonar_lateral_Esquerdo > 1 && valor_sensor_sonar_lateral_Esquerdo < 10) && 
  (valor_sensor_sonar_lateral_Direito > 1 && valor_sensor_sonar_lateral_Direito < 10)){
     rampa();
  }
  else if((valor_sensor_sonar_frontal > 1) && (valor_sensor_sonar_frontal < 7)){
    contornarObstaculo();
   }
   
   void Estrategia::seguirlinha(){
	else if (sensor.deve_seguir_em_frente()){                           //"deve_seguir_linha" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(40,40);
  }
	else if(sensor.deve_corrigir_esquerda()){                   //"deve_corrigir_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(-35, 35);                           //se a esquerda tiver vendo preto, ele vai girar a roda esquerda para tras e direita para frente
  }
	else if(sensor.deve_corrigir_direita()){                    //"deve_corrigir_direita" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
      robo.acionarMotores(35, -35);                           //se a direita tiver vendo preto, ele vai girar a roda esquerda para frente e direita para tras
  }
  
	else if (sensor.deve_girar_a_esquerda()){  
     if(sensor.eh_verde_esquerdo()){
         girar_esquerdo_verde();
     }    //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
     else{
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
     //}
  }
  
  else if (sensor.deve_girar_a_direita()){                    //"deve_girar_a_esquerda" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
     if(sensor.eh_verde_direito()){
         robo.acionarMotores(40, -40);
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

}
void Estrategia::alinhaObstaculo(){
     while(sensor.desalinhado()){
	if (sensor.branco_branco_branco_preto() || sensor.branco_branco_preto_preto() || sensor.branco_preto_preto_preto() || 
            sensor.branco_preto_branco_preto() || sensor.preto_branco_preto_preto() || sensor.branco_branco_preto_branco()){ 
	    robo.acionarMotores(-25, 0); 
	}
	else if (sensor.preto_branco_branco_branco() || sensor.preto_preto_branco_branco() || sensor.preto_preto_preto_branco() || 
            sensor.preto_branco_preto_branco() || sensor.preto_preto_branco_preto() || sensor.branco_preto_branco_branco()){
	    robo.acionarMotores(0, -25); 
	}
     }
}           
      
void Estrategia::contornarObstaculo(){
   robo.acionarMotores(0, 0);
   delay(300);  
   robo.acionarMotores(-25, -25);
   delay(150);
   
   while (!sensor.branco_branco_branco_preto()){
        robo.acionarMotores(-40, 40);
   }
   
   Estrategia::alinhaObstaculo();
   
   robo.acionarMotores(40, 40);
   delay(700);
   robo.acionarMotores(40, -40);
   delay(470);
   robo.acionarMotores(40, 40);
   delay(1150);
   robo.acionarMotores(40, -40);
   delay(470);

   while (sensor.branco_branco_branco_branco()){
	robo.acionarMotores(40, 40);
   }
   robo.acionarMotores(40, 40);
   delay(250);
   
   while (!sensor.branco_branco_preto_branco()){
	robo.acionarMotores(-40, 40);
   }
   robo.acionarMotores(0,0);
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

void Estrategia::rampa(){
  if(sensor.branco_preto_branco_branco()){
     robo.acionarMotores(40, 55); 
  }
  else if(sensor.branco_branco_preto_branco()){
      robo.acionarMotores(55, 40);
  }
  else if(sensor.preto_branco_branco_branco()){
      robo.acionarMotores(-20, 45);
  }
  else if(sensor.branco_branco_branco_preto()){
      robo.acionarMotores(45, -20);
  }
  else{
      robo.acionarMotores(45, 45);
  }
}
