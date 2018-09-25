#include "UART.h"

void uartInit(void){
  UART_PORT.begin(UART_BAUD);
}

void uartGet(char *caracter_,int *size_,int _datos[]){
   *caracter_ = UART_PORT.read();
    bool bufferComplete = false;
    char actual;
    int index = 0;
    String valores[20];
    bool error = false;
     do{
       if(UART_PORT.available()){
          actual = UART_PORT.read();
          if(actual != '\n'){
            if(actual == ',') index++;
            else              valores[index]+=actual;
          }
          else{
            bufferComplete=true;
          }
       }   
     }while(!bufferComplete);
     
     if(error == false){
      *size_ = index+1;
      for(int i = 0;i<=index;i++) _datos[i]=valores[i].toInt();
     }
     else{
      *size_ = 1;
      _datos[0]=0;
      *caracter_ = 'x';
     }
     
}

