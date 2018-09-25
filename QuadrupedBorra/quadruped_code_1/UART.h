#ifndef UART_H
#define UART_H
  
  #include <Arduino.h>

  #define UART_PORT   Serial
  #define UART_BAUD     9600

  void uartInit(void);
  void uartGet(char *character_,int *size_,int _dato[]);
#endif
