#include "arranques.h"

inicios iniciosOrillas[]={{inicioOrilla0,"Robot Al frente 0"},
                          {inicioOrilla1,"Robot Al frente 1"},
                          {inicioOrilla2,"Robot Al frente 2"},
};

#define INICIOS_ORILLAS_TAM    (sizeof(iniciosOrillas)/sizeof(inicios))

long tiempoA=0,tiempoP=0;
extern int lado;
void IniciosOrillas(int x){
  iniciosOrillas[x].Callback();
}

void inicioOrilla0(void){
  
}

void inicioOrilla1(void){
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

void inicioOrilla2(void){
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

