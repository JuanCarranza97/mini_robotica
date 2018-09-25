#include "arranques.h"

inicios iniciosOrillas[]={{inicioIzquieraCentro,"Robot Al frente 0"},
                          {inicioDerechaCentro,"Robot Al frente 1"},
                          {inicioDerechadsdsfsgfd,"Robdsgfudhudgsh gdsghdjisgufv y"},
                       
};

#define INICIOS_ORILLAS_TAM    (sizeof(iniciosOrillas)/sizeof(inicios))

long tiempoA=0,tiempoP=0;
extern int lado;
void IniciosOrillas(int x){
  iniciosOrillas[x].Callback();
}


void inicioIzquieraCentro(void){
  lado = 1;
  tiempoP=millis();
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
  do{
    tiempoA = millis()-tiempoP;

      if(tiempoA < 100)                       setMotors(-100,100);
      else                                    setMotors(100,100);
  }while(tiempoA < 300);
  setMotors(0,0);
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
}

void inicioDerechaCentro(void){
  tiempoP=millis();
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
  do{
    tiempoA = millis()-tiempoP;

      if(tiempoA < 100)                       setMotors(-100,100);
      else if(tiempoA >= 100 && tiempoA < 200)digitalWrite(LED_2,HIGH);
      else                            digitalWrite(LED_3,HIGH);
  }while(tiempoA < 400);
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
}

 void inicioDerechaOrilla(void){
   tiempoP=millis();
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
  do{
    tiempoA = millis()-tiempoP;

      if(tiempoA < 100)                       setMotors(-100,100);
      else if(tiempoA >= 100 && tiempoA < 200)digitalWrite(LED_2,HIGH);
      else                            digitalWrite(LED_3,HIGH);
  }while(tiempoA < 400);
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
 }

void inicioDerechaOrill2(void){
     tiempoP=millis();
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
  do{
    tiempoA = millis()-tiempoP;

      if(tiempoA < 100)                       setMotors(-100,100);
      else if(tiempoA >= 100 && tiempoA < 200)digitalWrite(LED_2,HIGH);
      else                            digitalWrite(LED_3,HIGH);
  }while(tiempoA < 400);
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);
}

