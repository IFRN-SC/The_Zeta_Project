#include "Estrategia.h"

void Estrategia::calibrar(boolean realizarCalibracao){        //"calibrar" eh funçao da classe "Estrategia"
  if(realizarCalibracao){                                     //se realizarCalibraçao ele vai chamar a funçao calibrar
      sensor.calibrar();                                      //objeto "sensor" da classe "sensores", chama a funçao "calibrar"
  }
  else{                                                       //senao realizarCalibraçao
      sensor.semCalibracao();                                 //objeto "sensor" da classe "sensores", chama a funçao "semcalibrar"
  }
}  

void Estrategia::execute(){                                   //"execute" eh funçao da classe "Estrategia", para o robo executar alguma açao
  if (sensor.deve_seguir_linha ()){                           //"deve_seguir_linha" eh funçao da classe "sensores", que esta sendo acessada atraves do objeto "sensor"
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
}

  
