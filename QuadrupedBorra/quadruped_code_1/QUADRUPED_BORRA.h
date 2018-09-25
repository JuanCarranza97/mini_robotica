#ifndef QUADRUPED_BORRA_H
#define QUADRUPED_BORRA_H

  #include <Arduino.h>

  #include <Servo.h>
  #include <EEPROM.h>
  
  #include "UART.h"
  #include "TERMINAL.h"
  
  /*******ADDR_EEPROM****/
  #define CIF_ADDR    1
  #define HIF_ADDR    2  
  #define CDF_ADDR    3
  #define HDF_ADDR    4
  #define CIA_ADDR    5
  #define HIA_ADDR    6
  #define CDA_ADDR    7
  #define HDA_ADDR    8
  float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
  
  void saveEEPROM(void);
  void readEEPROM(void);
  float getVoltage(void);
#endif
