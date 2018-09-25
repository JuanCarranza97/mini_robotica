#include "UART.h"
#include "LineSTM.h"

extern int Ticker[NUM_TICKERS];

void UART_init(void){
  UART_PORT.begin(UART_BAUD);
}


void UART_get(char *caracter_,int *size_,int _datos[]){

    *caracter_ = UART_PORT.read();
    bool bufferComplete = false;
    char actual;
    int index = 0;
    String valores[20];
    bool error = false;
     do{
       if(UART_PORT.available()){
          actual = UART_PORT.read();
          Ticker[0]=0;
          if(actual != '\n'){
            if(actual == ',') index++;
            else              valores[index]+=actual;
          }
          else{
            bufferComplete=true;
          }
       }   
       if(Ticker[0] > 50) {
        
        bufferComplete=true;
        error = true;
          for(int i = 0;i< 5;i++){
            LED1_ON;
            LED2_OFF;
            delay(50);
            LED1_OFF;
            delay(50);
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

