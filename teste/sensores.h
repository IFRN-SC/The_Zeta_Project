#ifndef SENSORES_H
#define SENSORES_H

#include <robo_hardware.h>
#include "sensor_refletancia.h"
#include "sensor_cor.h"
#include "calibracao.h"

#define BRANCO 1
#define PRETO 2
#define VERDE 3

class sensores{                                   //classe "sensores", nela tem declarado boa parte das funçoes usadas nos sensores no geram, tanto de cor quanto de refletancia
  public:                                         //as variaveis ou as funçoes, pode ser acessado por qualquer outra classe

    HSV getHSVBrancoDireito(){return corDireito.getHSVBranco();}
    HSV getHSVPretoDireito(){return corDireito.getHSVPreto();}
    HSV getHSVVerdeDireito(){return corDireito.getHSVVerde();}
    HSV getHSVCinzaDireito(){return corDireito.getHSVCinza();}
    
    HSV getHSVBrancoEsquerdo(){return corDireito.getHSVBranco();}
    HSV getHSVPretoEsquerdo(){return corDireito.getHSVPreto();}
    HSV getHSVVerdeEsquerdo(){return corDireito.getHSVVerde();}
    HSV getHSVCinzaEsquerdo(){return corDireito.getHSVCinza();}
    
    
    char zona_resgate;
    
    sensores();                                    //construtor da classe "sensores"
    boolean configura(boolean realizar_cali);      //declaraçao da funçao "configura", que recebe como parametro "ralizar_cali"
   
    boolean branco_branco_branco_branco();         //declaraçao da funçao "branco_branco_branco_branco", que retorna um boleano
    boolean preto_preto_preto_preto();             //declaraçao da funçao "preto_preto_preto_preto", que retorna um boleano
    
    boolean branco_preto_branco_branco();          //declaraçao da funçao "branco_preto_branco_branco", que retorna um boleano
    boolean branco_branco_preto_branco();          //declaraçao da funçao "branco_branco_preto_branco", que retorna um boleano
    boolean preto_branco_branco_branco();          //declaraçao da funçao "preto_branco_branco_branco", que retorna um boleano
    boolean branco_branco_branco_preto();          //declaraçao da funçao "branco_branco_branco_preto", que retorna um boleano
    
    boolean preto_preto_branco_branco();           //declaraçao da funçao "preto_preto_branco_branco", que retorna um boleano
    boolean branco_branco_preto_preto();           //declaraçao da funçao "branco_branco_preto_preto", que retorna um boleano
    boolean branco_preto_preto_branco();           //declaraçao da funçao "branco_preto_preto_branco", que retorna um boleano
    boolean preto_branco_branco_preto();           //declaraçao da funçao "preto_branco_branco_preto", que retorna um boleano
    boolean preto_branco_preto_branco();           //declaraçao da funçao "preto_branco_preto_branco", que retorna um boleano
    boolean branco_preto_branco_preto();           //declaraçao da funçao "branco_preto_branco_preto", que retorna um boleano
    
    boolean preto_preto_preto_branco();            //declaraçao da funçao "preto_preto_preto_branco", que retorna um boleano
    boolean branco_preto_preto_preto();            //declaraçao da funçao "branco_preto_preto_preto", que retorna um boleano
    boolean preto_preto_branco_preto();            //declaraçao da funçao "preto_preto_branco_preto", que retorna um boleano
    boolean preto_branco_preto_preto();            //declaraçao da funçao "preto_branco_preto_preto", que retorna um boleano
    
  
    void luz();  
    inline boolean eh_preto_esquerdo(){return (sensorEsquerdo.ehPreto());}//robo.getHSVEsquerdo()));}//return (sensorEsquerdo.ehPreto());}
    inline boolean eh_branco_esquerdo(){return (sensorEsquerdo.ehBranco());}//robo.getHSVEsquerdo()));}// return(determine_cor() == BRANCO);}
    
    inline boolean eh_preto_cor_esquerdo(){return (corEsquerdo.ehPreto(robo.getHSVEsquerdo()));}
    inline boolean eh_verde_esquerdo(){return (corEsquerdo.ehVerde(robo.getHSVEsquerdo()));}
    inline boolean eh_cinza_esquerdo(){return (corEsquerdo.ehCinza(robo.getHSVEsquerdo()));}
    
    inline boolean eh_preto_direito(){return (sensorDireito.ehPreto());}
    inline boolean eh_branco_direito(){return (sensorDireito.ehBranco());}//robo.getHSVDireito()));}//return();}
    
    inline boolean eh_preto_cor_direito(){return (corDireito.ehPreto(robo.getHSVDireito()));}
    inline boolean eh_verde_direito(){return (corDireito.ehVerde(robo.getHSVDireito()));}
    inline boolean eh_cinza_direito(){return (corDireito.ehCinza(robo.getHSVDireito()));}
    
    inline boolean eh_preto_mais_esquerdo(){return (sensorMaisEsquerdo.ehPreto());}
    inline boolean eh_branco_mais_esquerdo(){return (sensorMaisEsquerdo.ehBranco());}
    
    inline boolean eh_preto_mais_direito(){return (sensorMaisDireito.ehPreto());}
    inline boolean eh_branco_mais_direito(){return (sensorMaisDireito.ehBranco());}  
  
    bool algum_sensor_eh_preto();
        
    void calibrar();
    void semCalibracao();
    void executar();
    void calibrar_auto();
    bool deve_seguir_em_frente();
    bool deve_corrigir_esquerda();
    bool deve_corrigir_direita();
    bool deve_girar_a_esquerda();
    bool deve_girar_a_direita();
    bool encruzilhada();
    bool desalinhado();
    
   // int distancia_lado();
   // int distancia_frente();
   
  private:
    SensorRefletancia sensorEsquerdo, sensorMaisEsquerdo, sensorDireito, sensorMaisDireito;
    SensorDeCor corDireito, corEsquerdo;
   
    Calibracao cali;
    
    void espereCor();
    
    HSV hsv_esquerdo;
    HSV hsv_direito;
    boolean expor_v_esquerdo = false;
    boolean expor_v_direito = false;
};


#endif
