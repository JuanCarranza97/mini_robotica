#include "ReceptorIR.h"
#include "GPIO.h"
#include "Motores.h"
#include "arranques.h"

extern int Arranque;

int lado = 1;

void setup() {
  Serial.begin(115200);
  receptorInit();
  gpioInit();
  motorsInit();
}

void loop() {
  Receptor();
  digitalWrite(LED_1,digitalRead(LEFT_SENSOR));
  digitalWrite(LED_3,digitalRead(RIGHT_SENSOR));

  if(digitalRead(GO)){
    digitalWrite(LED_1,HIGH);
    IniciosOrillas(Arranque);
    do{
      pelea();
    }while(digitalRead(GO));
    setMotors(0,0);
    digitalWrite(LED_1,LOW);
  }
  else{
    digitalWrite(LED_1,LOW);
  }
}

void pelea(void){
  int sen = (!digitalRead(LEFT_SENSOR)<<1)|!(digitalRead(RIGHT_SENSOR));

   switch(sen){
    case 0:
      if(lado == 1 ) setMotors(-100,100);
      else           setMotors(100,-100);
      break;
    case 1:
      lado = 0;
      setMotors(60,100);
      break;
    case 2:
      lado = 1;
      setMotors(100,60);
      break;
    case 3:
      setMotors(100,100);
      break;
   }
}

