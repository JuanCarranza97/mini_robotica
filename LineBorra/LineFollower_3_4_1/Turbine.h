#ifndef Turbine_H
#define Turbine_H
  #include <Arduino.h>
  #include "GPIO.h"

  #define TURBINE_ENABLE
  #define MAX_TURBINE    140
  #define MIN_TURBINE     96
 
  #ifdef TURBINE_ENABLE
  #define Turbine_PIN PB11
  
   void Turbine_init(void);
   void ISR_Turbine(void);
  #endif
#endif
