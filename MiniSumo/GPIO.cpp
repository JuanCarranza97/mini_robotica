#include "GPIO.h"

void gpioInit(void){
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(PUSH_1,INPUT_PULLUP);
  pinMode(PUSH_2,INPUT_PULLUP);

  pinMode(LEFT_SENSOR,INPUT);
  pinMode(RIGHT_SENSOR,INPUT);

  pinMode(READY,INPUT);
  pinMode(GO,INPUT);
}

