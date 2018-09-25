#include "GPIO.h"

void GPIO_init(void){
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  LED1_OFF;
  LED2_OFF;
  pinMode(PUSH_1,INPUT_PULLUP);
  pinMode(PUSH_2,INPUT_PULLUP);
  pinMode(PUSH_3,INPUT_PULLUP); 
  pinMode(GO_PIN,INPUT_PULLUP);
  digitalWrite(GO_PIN,LOW);
}

