#include "sensores.h"



sensores::sensores():sensorEsquerdo(SENSOR_LINHA_ESQUERDO),sensorMaisEsquerdo(SENSOR_LINHA_MAIS_ESQUERDO),sensorDireito(SENSOR_LINHA_DIREITO),sensorMaisDireito(SENSOR_LINHA_MAIS_DIREITO){
  
}

void sensores::luz(){
  Serial.print("+esquerdo: "); 
  Serial.print(sensorMaisEsquerdo.getLuz());
  Serial.print("   ||   ");
  Serial.print("esquerdo: "); 
  Serial.print(sensorEsquerdo.getLuz());
  Serial.print("   ||   ");
  Serial.print("direito: "); 
  Serial.print(sensorDireito.getLuz());
  Serial.print("   ||   ");
  Serial.print("+direitoo: "); 
  Serial.println(sensorMaisDireito.getLuz());  
}  


boolean sensores::branco_branco_branco_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::preto_preto_preto_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
  
boolean sensores::branco_preto_branco_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_branco_preto_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::preto_branco_branco_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_branco_branco_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
  
boolean sensores::preto_preto_branco_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_branco_preto_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::branco_preto_preto_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::preto_branco_branco_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::preto_branco_preto_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_preto_branco_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
  
boolean sensores::preto_preto_preto_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_preto_preto_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::preto_preto_branco_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::preto_branco_preto_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
  
  
//int sensores::distancia_lado(){return robo.distanciaLado();}
//int sensores::distancia_frente(){return robo.distanciaFrente();}  


boolean sensores::configura(boolean realizar_cali){
    if(realizar_cali){
      semCalibracao();
      calibrar();
    }
    else {
      semCalibracao();
    }
}

void sensores::espereCor(){
  char controle = 's';
  while(1){
    if(expor_v_direito){
      hsv_direito = robo.getHSVDireito();
      Serial.print("V direito  -->   ");
      Serial.println(hsv_direito.h);
    }else if(expor_v_esquerdo){
      hsv_esquerdo = robo.getHSVEsquerdo();
      Serial.print("V esquerdo  -->   ");
      Serial.println(hsv_esquerdo.h);
    
    }else{
      luz();
    }
    //delay(500);
    controle = Serial.read();
    if(controle == 'c'){
      controle = 's';
      break;
    }
  } 
}

void sensores::semCalibracao(){
  sensorMaisEsquerdo.setMedia(19);
  sensorEsquerdo.setMedia(33);
  sensorDireito.setMedia(34);
  sensorMaisDireito.setMedia(25);
}

void sensores::calibrar(){
  
  cali.menu_geral(corEsquerdo, corDireito);
  sensorEsquerdo.setMedia(cali.getRefletanciaEsq());//pega o valor rpega a valor do sensor de refletancia esquerda(que dentro da funço de calibracao), e retorna no sensorEsquerdo 
  sensorDireito.setMedia(cali.getRefletanciaDir());
  sensorEsquerdo.setMedia(cali.getRefletanciaMaisEsq());
  sensorDireito.setMedia(cali.getRefletanciaMaisDir());
}

bool sensores::deve_seguir_em_frente(){
   return branco_branco_branco_branco();
}

bool sensores::deve_corrigir_esquerda(){
    return branco_preto_branco_branco();
}

bool sensores::deve_corrigir_direita(){
    return branco_branco_preto_branco();
}

bool sensores::deve_girar_a_esquerda(){
    return (preto_preto_branco_branco() || preto_preto_branco_preto() || preto_branco_preto_branco() || preto_preto_preto_branco());
}

bool sensores::deve_girar_a_direita(){
    return (branco_branco_preto_preto() || preto_branco_preto_preto() || branco_preto_branco_preto() || branco_preto_preto_preto());
}
bool sensores::encruzilhada(){
    return preto_preto_preto_preto();
}
bool sensores::desalinhado(){
    return (branco_branco_preto_preto() || preto_preto_branco_branco() || branco_preto_preto_branco() || preto_branco_branco_preto() || 
    preto_branco_preto_branco() || branco_preto_branco_preto() || branco_preto_branco_branco() || branco_branco_preto_branco() ||
    preto_branco_branco_branco() || branco_branco_branco_preto() || preto_preto_preto_branco() || branco_preto_preto_preto() || 
    preto_preto_branco_preto() || preto_branco_preto_preto() || branco_branco_branco_branco());
}   
bool sensores::algum_sensor_eh_preto(){
    return eh_preto_esquerdo() || eh_preto_direito() || eh_preto_mais_esquerdo() || eh_preto_mais_direito();
}    
