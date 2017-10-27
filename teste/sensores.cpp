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
      lerCalibracao();
      calibrar();
    }
    else {
      lerCalibracao();
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

void sensores::lerCalibracao(){
}

void sensores::calibrar(){
  cali.menu();
  sensorEsquerdo.setMedia(cali.getRefletanciaEsq());
  sensorDireito.setMedia(cali.getRefletanciaDir());
  sensorEsquerdo.setMedia(cali.getRefletanciaMaisEsq());
  sensorDireito.setMedia(cali.getRefletanciaMaisDir());
}
