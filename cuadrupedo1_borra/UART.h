#ifndef UART_H
#define UART_H
  #include <Arduino.h>

  #define UART_PORT    Serial1
  #define UART_BAUD    115200

  #include "GPIO.h"
  void UART_init(void);
  void UART_get(char *caracter_,int *size_,int _datos[]);
#endif UART_H
