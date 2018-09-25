#ifndef TERMINAL_H
#define TERMINAL_H

  #include <Arduino.h>

  #include "QUADRUPED_BORRA.h"

  #define TERMINAL_MESSAGES 
  typedef void (*terminalCallback)(int var[],int tam);  

  typedef struct{
    terminalCallback Callback;
    const char caracter;
    int tam;
    const char *helpString;
    const char *actionString;
  }terminal_actions;

  void terminalLab(void);

  void terminalAction_A(int var[],int tam);
  void terminalAction_a(int var[],int tam);
  void terminalAction_B(int var[],int tam);
  void terminalAction_b(int var[],int tam);
#endif
