#ifndef PID_H
#define PID_H
  #include <Arduino.h>
  #include <EEPROM.h>
  #include <flash_stm32.h>


  #include "UART.h"
  
  #define EEPROM_DATA         7
  
  #define KP_CONFIG           0
  #define KI_CONFIG           1
  #define KD_CONFIG           2
  #define SAMPLE_TIME_CONFIG  3
  #define SET_POINT           4
  #define MAXD_CONFIG         5
  #define MAXI_CONFIG         6
  
  class PID_Controller{
     public:
      PID_Controller();

        void  FirstADDR_EEPROM(uint16_t first);
        void Compute(float input);
        void Update(uint8_t x,int val);
        void reset(void);
        int  GetValue(uint8_t x);
        void SaveEEPROM(void);
        void ReadEEPROM(void);
        
        uint16_t Kp,Ki,Kd,SampleTime,SetPoint,MaxD,MaxI; //Menor que 255;
        float U,Kp_Div=1,Ki_Div=1,Kd_Div=1;
        int LastTime;
        float P,I,D;        
        uint16_t LastADDR;
        
     private:
        uint16_t EEPROM_ADDRS[EEPROM_DATA];
        float sumError,prevError;
        
  };
#endif
