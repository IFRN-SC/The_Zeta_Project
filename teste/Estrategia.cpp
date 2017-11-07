#include "Estrategia.h"

void Estrategia::calibrar(boolean realizarCalibracao){//"calibrar" eh funçao declarada na classe "Estrategia"
  if(realizarCalibracao){
  sensor.calibrar();//objeto da classe sensores, chama a funçao calibrar
  }
  else{
    sensor.semCalibracao();
  }
}  

void Estrategia::execute(){  
  if (sensor.deve_seguir_linha ()){
      robo.acionarMotores(40,40);
          
  }
  else if(sensor.deve_corrigir_esquerda()){
      robo.acionarMotores(-40, 40);
  }
  else if(sensor.deve_corrigir_direita()){
      robo.acionarMotores(40, -40);
  }
  //Identifica se o sensor da esquerda viu banco e o da direita viu preto
  else if (sensor.deve_girar_a_esquerda()){
     while  (sensor.preto_preto_branco_branco()){
        robo.acionarMotores(40,40);	//Aciona o motor direito e mantem o motor esquerdo desligado
        delay (100);
     }
     while (sensor.branco_branco_branco_branco()){
         robo.acionarMotores(-40,40); 
     }
     while (sensor.preto_preto_branco_preto() || sensor.preto_preto_branco_branco()){
        robo.acionarMotores(40,-40);
        delay (200);
        robo.acionarMotores(40,40);
     }
  }
  //Identifica se o sensor da direita viu banco e o da esquerda viu preto
  else if (sensor.deve_girar_a_direita()){
     while  (sensor.branco_branco_preto_preto()){
        robo.acionarMotores(40,40);	//Aciona o motor direito e mantem o motor esquerdo desligado
        delay (100);
     }
     while (sensor.branco_branco_branco_branco()){
       robo.acionarMotores(40,-40); 
        
     }
     while (sensor.preto_branco_preto_preto() || sensor.branco_branco_preto_preto()){
        robo.acionarMotores(-40,40);
        delay (200);
	robo.acionarMotores(40,40);	//Aciona o motor esquerdo e mantem o motor direito desligado
     }
   }
}

  
