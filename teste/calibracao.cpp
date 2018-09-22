#include "calibracao.h"

void Calibracao::menu_geral(SensorDeCor sensorEsquerdo, SensorDeCor sensorDireito){ // função do menu geral
 bool sair_menu_geral = false;
  while(!sair_menu_geral){
      Serial.println("### DIGITE A OPCAO DESEJADA ###");
      Serial.println("            ");
      Serial.println("Para calibrar sensor de REFLETANCIA aperte R");
      Serial.println("Para calibrar sensor de COR aperte C");               //avisa qual letra apertar para calibrar o esquerdo
      Serial.println("Para sair aperte S");    
      
      char espera_ler = esperaLer();      

      switch(espera_ler){                                        //switch(escolha caso), recebe como parametro a variavel "espera_ler"
        
        case 'R':
            menu_refletancia();                            //caso seja "E", ele executa a funçao "calibra_refletancia_E()"
            break;
        case 'C':
            menu_cor(sensorEsquerdo, sensorDireito);                             //caso seja "D", ele executa a funçao "calibra_refletancia_D()"
            break;
        case 'S':
          sair_menu_geral=true; 
      }  
  }   
}

void Calibracao::menu_refletancia(){                                             // função do menu refletancia , "menu" eh a funçao principal da classe calibraçao
  bool sair_menu_refletancia = false;                                            //variavel"sair_menu" recebeu falso e retorna um boleano
    while(!sair_menu_refletancia){                                               //laço para menu principal
      Serial.println("### DIGITE A OPCAO DESEJADA ###");
      Serial.println("            ");
      Serial.println("Calibrar SENSOR DE REFLETANCIA");
      Serial.println("Para todos os BRANCOS aperte B");
      Serial.println("Para o ESQUERDO aperte E ");               //avisa qual letra apertar para calibrar o esquerdo
      Serial.println("Para o DIREITO aperte D");                 //avisa qual letra apertar para calibrar o direito
      Serial.println("Para o MAIS ESQUERDO aperte M");           //avisa qual letra apertar para calibrar o mais esquerdo
      Serial.println("Para o MAIS DIREITO aperte N");            //avisa qual letra apertar para calibrar o mais direito
      Serial.println("            ");
      
      char espera_ler = esperaLer();                             //a variavel "espera_ler" que retorna um char, recebe a funçao de "esperaLer()"
      
      switch(espera_ler){                                        //switch(escolha caso), recebe como parametro a variavel "espera_ler"
        case 'B':
            calibra_todos_brancos();                              // caso seja "B", ele executa a função de calibrar todos os sensores de refletancia
            break;
        case 'E':
            calibra_refletancia_E();                             //caso seja "E", ele executa a funçao "calibra_refletancia_E()"
            break;           
        case 'D':
            calibra_refletancia_D();                             //caso seja "D", ele executa a funçao "calibra_refletancia_D()"
            break;
        case 'M':    
            calibra_refletancia_mais_E();                        //caso seja "M", ele executa a funçao "calibra_refletancia_mais_E()"
            break;
        case 'N':
            calibra_refletancia_mais_D();                        //caso seja "N", ele executa a funçao "calibra_refletancia_mais_D()"
            break;
        case 'S':
          sair_menu_refletancia=true;
          
      }
    }
}


void Calibracao::calibra_todos_brancos(){

}
   
/*
  bool sair_menu_geral = false;
  Refletancia EsqDefinitivo;  
  Refletancia DirDefinitivo;
  EsqDefinitivo.branco=100;
  EsqDefinitivo.preto=0;
  DirDefinitivo.preto=0;
  DirDefinitivo.branco=100;
 // sair_menu_calibra = false;                                   
  
  while(!sair_menu_geral){
  
  Serial.println("+Esq");
  Serial.print(robo.lerSensorLinhaMaisEsq());
  Serial.println("Esq");
  Serial.print(robo.lerSensorLinhaEsq());
  Serial.println("+Dir");
  Serial.print(robo.lerSensorLinhaMaisDir());
  Serial.println("Dir");
  Serial.print(robo.lerSensorLinhaDir());  
  Serial.println("Quando tiver certeza digite L");
   char espera_ler = esperaLer(); 

   switch(espera_ler){                                        //switch(escolha caso), recebe como parametro a variavel "espera_ler"
        case 'L':
            calibra_todos_brancos();                             
            break;
  }
  }
   sair_menu_calibra = false;
  
  while(!sair_menu_calibra){                                   //enquanto for diferente de "sair_menu_calibra", ele vai continuar a executar o laço
    Serial.println("CALIBRACAO DE TODOS OS SENSORES PARA O BRANCO");
    calibraSensor(robo.lerSensorLinhaMaisEsq(), escolhaCor(), EsqDefinitivo); //executa a funçao "calibraSensor", e recebe como parametro a funçao que ler o sensor,a funçao de escolher entre branco e preto, e a variavel com nome do sensor
    calibraSensor(robo.lerSensorLinhaEsq(), escolhaCor(), EsqDefinitivo);     
    calibraSensor(robo.lerSensorLinhaMaisDir(), escolhaCor(), EsqDefinitivo); 
    calibraSensor(robo.lerSensorLinhaDir(), escolhaCor(), DirDefinitivo);       
  }
 
  media_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.5; //"media_esq" calcula a media do sensor esquerdo
  Serial.print("Sou o esquerdo gata");
  Serial.print("Valor Calibrado no sensor Esquerdo ");          
  Serial.println(media_esq);                                    //imprimindo a media calculada
  Serial.println("           ");
  valor.refletancia_esq= media_esq;                             //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_esq" recebe "media_esq"
  robo.salvarCalibracao(valor); 

  media_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.5;  //"media_dir" calcula a media do sensor direito
  Serial.print("Valor Calibrado no sensor Direito ");
  Serial.println(media_dir);                                   //imprimindo a media calculada
  Serial.println("           ");  
  valor.refletancia_dir= media_dir;                            //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_dir" recebe "media_dir"
  robo.salvarCalibracao(valor); 

  media_mais_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.5;   //"media_mais_esq" calcula a media do sensor mais esquerdo
  Serial.print("Valor Calibrado no sensor Mais Esquerdo ");
  Serial.println(media_mais_esq);                              //imprimindo a media calculada
  Serial.println("           ");  
  valor.refletancia_mais_esq= media_mais_esq;                  //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_mais_esq" recebe "media_mais_esq"
  robo.salvarCalibracao(valor); //funçao "salvarCalibracao" recebe como parametro o objeto "valor"

  media_mais_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.5;  //"media_mais_dir" calcula a media do sensor mais direito
  Serial.print("Valor Calibrado no sensor Mais Direito ");
  Serial.println(media_mais_dir);                             //imprimindo a media calculada
  Serial.println("           ");  
  valor.refletancia_mais_dir= media_mais_dir;                  //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_mais_dir" recebe "media_mais_dir"
  robo.salvarCalibracao(valor);

}
*/

void Calibracao::calibra_refletancia_E(){           //"calibra_refletancia_E()" eh a funçao da classe "calibracao", para calibrar o sensor de refletancia ESQUERDO
   
  Refletancia EsqDefinitivo;                                      //struct do sensor de refletancia esquerdo, que dentro dela tem as variaveis preto e branco
  EsqDefinitivo.preto=0;                                          //a variavel "preto" do sensor de refletancia esquerdo, recebe como valor inicial "0"
  EsqDefinitivo.branco=100;                                       //a variavel "branco" do sensor de refletancia esquerdo, recebe como valor inicial "100"
  sair_menu_calibra = false;                                      //a variavel "sair_menu_calibra" recebe "false"
  
  while(!sair_menu_calibra){    
    Serial.println("Coloque o  sensor no devido lugar");
    aguardaPosicionamento();
    espera();
    escolha= Serial.read();                                    
    Serial.println("CALIBRACAO DO SENSOR ESQUERDO");
    calibraSensor(robo.lerSensorLinhaEsq(), escolhaCor(), EsqDefinitivo); //executa a funçao "calibraSensor", e recebe como parametro a funçao que ler o sensor,a funçao de escolher entre branco e preto, e a variavel com nome do sensor
  }  
  media_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.5; //"media_esq" calcula a media do sensor esquerdo
  Serial.print("Valor Calibrado no sensor Esquerdo ");          
  Serial.println(media_esq);                                    //imprimindo a media calculada
  Serial.println("           ");
  valor.refletancia_esq= media_esq;                             //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_esq" recebe "media_esq"
  robo.salvarCalibracao(valor);                                 //funçao "salvarCalibracao" recebe como parametro o objeto "valor"
}


void Calibracao::calibra_refletancia_D(){               //"calibra_refletancia_D()" eh a funçao da classe "calibracao", para calibrar o sensor de refletancia DIREITO
  Refletancia DirDefinitivo;                                    //struct do sensor de refletancia direito, que dentro dela tem as variaveis preto e branco
  DirDefinitivo.preto=0;                                        //a variavel "preto" do sensor de refletancia direito, recebe como valor inicial "0"
  DirDefinitivo.branco=100;                                     //a variavel "branco" do sensor de refletancia direito, recebe como valor inicial "100"
  sair_menu_calibra = false;                                    //a variavel "sair_menu_calibra" recebe "false"
  
  while(!sair_menu_calibra){                                    //enquanto for diferente de "sair_menu_calibra", ele vai continuar a executar o laço
    Serial.println("CALIBRACAO DO SENSOR DIREITO");
    calibraSensor(robo.lerSensorLinhaDir(), escolhaCor(), DirDefinitivo); //executa a funçao "calibraSensor", e recebe como parametro a funçao que ler o sensor,a funçao de escolher entre branco e preto, e a variavel com nome do sensor
  }
  
  media_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.5;  //"media_dir" calcula a media do sensor direito
  Serial.print("Valor Calibrado no sensor Direito ");
  Serial.println(media_dir);                                   //imprimindo a media calculada
  Serial.println("           ");
  
  valor.refletancia_dir= media_dir;                            //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_dir" recebe "media_dir"
  robo.salvarCalibracao(valor);                                //funçao "salvarCalibracao" recebe como parametro o objeto "valor"
}

void Calibracao::calibra_refletancia_mais_E(){       //"calibra_refletancia_mais_E()" eh a funçao da classe "calibracao", para calibrar o sensor de refletancia MAIS ESQUERDO
  Refletancia EsqDefinitivo;                                   //struct do sensor de refletancia mais esquerdo, que dentro dela tem as variaveis preto e branco 
  EsqDefinitivo.preto=0;                                       //a variavel "preto" do sensor de refletancia mais esquerdo, recebe como valor inicial "0"
  EsqDefinitivo.branco=100;                                    //a variavel "branco" do sensor de refletancia mais esquerdo, recebe como valor inicial "100"
  sair_menu_calibra = false;                                   //a variavel "sair_menu_calibra" recebe "false"
  
  while(!sair_menu_calibra){                                   //enquanto for diferente de "sair_menu_calibra", ele vai continuar a executar o laço
    Serial.println("CALIBRACAO DO SENSOR MAIS ESQUERDO");
    calibraSensor(robo.lerSensorLinhaMaisEsq(), escolhaCor(), EsqDefinitivo); //executa a funçao "calibraSensor", e recebe como parametro a funçao que ler o sensor,a funçao de escolher entre branco e preto, e a variavel com nome do sensor
  }
  
  media_mais_esq= (EsqDefinitivo.preto + EsqDefinitivo.branco) * 0.5;   //"media_mais_esq" calcula a media do sensor mais esquerdo
  Serial.print("Valor Calibrado no sensor Mais Esquerdo ");
  Serial.println(media_mais_esq);                              //imprimindo a media calculada
  Serial.println("           ");
  
  valor.refletancia_mais_esq= media_mais_esq;                  //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_mais_esq" recebe "media_mais_esq"
  robo.salvarCalibracao(valor);                                //funçao "salvarCalibracao" recebe como parametro o objeto "valor"
}

void Calibracao::calibra_refletancia_mais_D(){       //"calibra_refletancia_mais_D()" eh a funçao da classe "calibracao", para calibrar o sensor de refletancia MAIS DIREITO
  Refletancia DirDefinitivo;                                  //struct do sensor de refletancia mais direito, que dentro dela tem as variaveis preto e branco
  DirDefinitivo.preto=0;                                      //a variavel "preto" do sensor de refletancia mais direito, recebe como valor inicial "0"
  DirDefinitivo.branco=100;                                   //a variavel "branco" do sensor de refletancia mais direito, recebe como valor inicial "100"
  sair_menu_calibra = false;                                  //a variavel "sair_menu_calibra" recebe "false"
  
  while(!sair_menu_calibra){                                  //enquanto for diferente de "sair_menu_calibra", ele vai continuar a executar o laço
    Serial.println("CALIBRACAO DO SENSOR MAIS DIREITO");
    calibraSensor(robo.lerSensorLinhaMaisDir(), escolhaCor(), DirDefinitivo); //executa a funçao "calibraSensor", e recebe como parametro a funçao que ler o sensor,a funçao de escolher entre branco e preto, e a variavel com nome do sensor
  }
  
  media_mais_dir= (DirDefinitivo.preto + DirDefinitivo.branco) * 0.5;  //"media_mais_dir" calcula a media do sensor mais direito
  Serial.print("Valor Calibrado no sensor Mais Direito ");
  Serial.println(media_mais_dir);                             //imprimindo a media calculada
  Serial.println("           ");
  
  valor.refletancia_mais_dir= media_mais_dir;                  //objeto "valor" da classe "calibracao_dados" para armazenar na EEPROM do arduino, "refletancia_mais_dir" recebe "media_mais_dir"
  robo.salvarCalibracao(valor);                                //funçao "salvarCalibracao" recebe como parametro o objeto "valor"
}
char Calibracao::escolhaCor(){                                 //funçao "escolhaCor" da classe "Calibracao"
  Serial.println("Para calibrar no PRETO aperte P");           
  Serial.println("Para calibrar no BRANCO aperte B");
  Serial.println("Para sair aperte S");
  Serial.println("           "); 
   char espera_ler = esperaLer();                             //char "espera_ler" armazena a escolha da pessoa. e recebe a funçao "esperaLer", ou seja, espera ate digitarem alguma escolha
   
   return espera_ler;                                         //retorna a opçao escolhida, ou seja, a letra
}

bool Calibracao::calibraSensor(float valorAtual, char espera_ler, Refletancia &Definitivo){//funçao "calibraSensor" da classe "Calibracao", "valorAtual" recebe o valor lido na hora pelo sensor, "espera_ler" retorna a cor escolhida, a Struct Refletancia retorna qual o sensor
   sair_menu_calibra = false;
   Serial.println(valorAtual);
    switch(espera_ler){     
      
      case 'P':
        Serial.print("Esquerdo preto atual é: ");          
        Serial.println(valorAtual);                           //imprime na tela o valor lido no preto
        Definitivo.preto = descubraMaior(Definitivo.preto, valorAtual);//armazena no definivo.preto, a funçao de descubrir o maior valor, que recebe como parametro o valo definitivo e o atual
        break;
        
      case 'B':
        Serial.print("Esquerdo branco atual é: ");
        Serial.println(valorAtual);                         //imprime na tela o valor lido no branco
        Definitivo.branco = descubraMenor(Definitivo.branco, valorAtual);//armazena no definivo.branco, a funçao de descubrir o menor valor, que recebe como parametro o valo definitivo e o atual
        break;
        
      case 'S':
        sair_menu_calibra = true;
        break;
   } 
  Serial.print("EsqDefinitivo.preto"); 
  Serial.println(Definitivo.preto);                      //imprime o valor armazenado como definitivo preto
  Serial.print("EsqDefinitivo.branco");
  Serial.println(Definitivo.branco);                     //imprime o valor armazenado como definitivo branco 
    return sair_menu_calibra;
}

void Calibracao::menu_cor(SensorDeCor sensorEsquerdo, SensorDeCor sensorDireito){                                             //"menu" eh a funçao principal da classe calibraçao
  bool sair_menu_cor = false;                                            //variavel"sair_menu" recebeu falso e retorna um boleano
    while(!sair_menu_cor){                                               //laço para menu principal
      Serial.println("### DIGITE A OPCAO DESEJADA ###");
      Serial.println("            ");
      Serial.println("Calibrar SENSOR DE COR");
      Serial.println("Para o ESQUERDO aperte E ");               //avisa qual letra apertar para calibrar o esquerdo
      Serial.println("Para o DIREITO aperte D");                 //avisa qual letra apertar para calibrar o direito
      Serial.println("            ");
      
      char espera_ler = esperaLer();                             //a variavel "espera_ler" que retorna um char, recebe a funçao de "esperaLer()"
      
      switch(espera_ler){                                        //switch(escolha caso), recebe como parametro a variavel "espera_ler"

        case 'B':
            calibra_todos_brancos();                              // caso seja "B", ele executa a função de calibrar todos os sensores de refletancia
            break;
        case 'E':
            calibraCorEsquerdo(sensorEsquerdo);                           
            break;
        case 'D':
            calibraCorDireito(sensorDireito);
            break;
        case 'S':
          sair_menu_cor=true;
          
      }
    }
}

void Calibracao::calibraCorEsquerdo(SensorDeCor sensor){
  Serial.println("CALIBRE HSV DO BRANCO");
  espera();
  sensor.setBranco(robo.getHSVEsquerdo()) ;
  Serial.println("CALIBRE HSV DO PRETO");
  espera();
  sensor.setPreto(robo.getHSVEsquerdo());
  Serial.println("CALIBRE HSV DO VERDE");
  espera();
  sensor.setVerde(robo.getHSVEsquerdo());
  Serial.println("CALIBRE HSV DO CINZA");
  espera();
  sensor.setCinza(robo.getHSVEsquerdo());
  
  sensor.calibra();
  
}

void Calibracao::calibraCorDireito(SensorDeCor sensor){
  Serial.println("CALIBRE HSV DO BRANCO");
  espera();
  sensor.setBranco(robo.getHSVDireito()) ;
  Serial.println("CALIBRE HSV DO PRETO");
  espera();
  sensor.setPreto(robo.getHSVDireito());
  Serial.println("CALIBRE HSV DO VERDE");
  espera();
  sensor.setVerde(robo.getHSVDireito());
  Serial.println("CALIBRE HSV DO CINZA");
  espera();
  sensor.setCinza(robo.getHSVDireito());
  
  sensor.calibra();
  
}

void Calibracao::aguardaPosicionamento() {
  Serial.println("ATENÇÃO!");
  Serial.println(("Insira algo quando estiver posicionado de forma correta"));
  while(1) {
    Serial.print("+Esq: ");
    Serial.print(robo.lerSensorLinhaMaisEsq());
    Serial.print("Esq: ");
    Serial.print(robo.lerSensorLinhaEsq());
    Serial.print("+Dir: ");
    Serial.print(robo.lerSensorLinhaMaisDir());
    Serial.print("Dir: ");
    Serial.print(robo.lerSensorLinhaDir());
    Serial.println(" ");
    delay(2000);
    if(Serial.available()) {
      Serial.read();
      break;
    }
  }
}

void Calibracao::espera(){  
  while(1){
    if(Serial.available()){
      if(Serial.read() == 'S')
        break;     
    }
  }
}

char Calibracao::esperaLer(){                           //funçao usada para esperar ate que alguem digite algo
    while(!Serial.available()){                         //enquanto for diferente de serial.available, ou seja, enquanto nao digitar nada ele nao vai fazer nada
    }
    return Serial.read();                               //quando alguem digitar algo, ele vai sair do laço e vai retornar o char que foi digitado
}

float Calibracao::descubraMaior(float valor1, float valor2){  //funçao para encontrar o maior valor, usada para achar o maior preto
  if(valor2 > valor1){ 
    valor1=valor2;;                                      //armazena maior valor, usado para descobrir o maior valor do preto
  }
  return valor1;                                         //retorna o maior valor comparado
}

float Calibracao::descubraMenor(float valor1, float valor2){  //funçao para encontrar o menor valor, usada para achar o menor branco
 if(valor2 < valor1){ 
    valor1=valor2;;                                      //armazena menor valor, usado para descobrir o menor valor do branco
  }
  return valor1;                                         //retorna o menor valor comparado
}
