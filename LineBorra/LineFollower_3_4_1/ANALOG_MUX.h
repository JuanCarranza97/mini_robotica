#ifndef ANALOG_MUX_H
#define ANALOG_MUX_H

 #include <Arduino.h> 
 #include "Turbine.h"
 
 // Timer 1 Para el multiplexor
  #define TIMER1_PERIOD   10  //Microseconds
  #define PREESCALER      50
  
  #define NUM_SENSORS     16
  #define ANALOG_INPUT   PA1

  #define MUX_S0         PA5
  #define MUX_S1         PA4
  #define MUX_S2         PA3
  #define MUX_S3         PA2


  void ISR_TIMER1(void);
  
  void MUX_init(void);
  void MUX_output(uint8_t a);
  void MUX_get(uint16_t data_[NUM_SENSORS]);
#endif
