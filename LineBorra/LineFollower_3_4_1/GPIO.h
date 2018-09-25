#ifndef GPIO_H
#define GPIO_H

 #include <Arduino.h> 
 
  #define LED_1            PC13
  #define LED_2            PB12

  #define PUSH_1           PB13
  #define PUSH_2           PB14
  #define PUSH_3           PA8

  #define GO_PIN           PA0
  
  #define LED1_ON          (digitalWrite(LED_1,LOW))
  #define LED2_ON          (digitalWrite(LED_2,LOW))
  #define LED1_OFF         (digitalWrite(LED_1,HIGH))
  #define LED2_OFF         (digitalWrite(LED_2,HIGH))

  #define PUSH1_PRESSED   (digitalRead(PUSH_1) == 0)
  #define PUSH2_PRESSED   (digitalRead(PUSH_2) == 0)
  #define PUSH3_PRESSED   (digitalRead(PUSH_3) == 0)
  #define INPUT_GO        (digitalRead(GO_PIN) == 1)
  
  void GPIO_init(void);
#endif
