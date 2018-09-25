#ifndef GPIO_H
#define GPIO_H
    #include <Arduino.h>

    #define LED_1         13
    #define LED_2          4
    #define LED_3          3

    #define PUSH_1        12
    #define PUSH_2        11

    #define LEFT_SENSOR    15   //A1
    #define RIGHT_SENSOR   14   //A0

    #define READY           7
    #define GO              8
    
    void gpioInit(void);
#endif
