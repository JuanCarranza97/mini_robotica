#ifndef GET_LINE_H
#define GET_LINE_H

  #include "ANALOG_MUX.h"
  #include "UART.h"
  #include <EEPROM.h>
  #include <flash_stm32.h>

  #define MAX_VALUE      0
  #define MIN_VALUE      1000

  #define TIMER2_PERIOD  2000

  #define FIRST_ADDR_MIN    70
  #define FIRST_ADDR_MAX    90
  
  void Init_Timer2(void);
  void Line_calibrate(int a);
  void ShowCalibratedValues(void);
  void GetMapValues(uint16_t values[NUM_SENSORS]);
  void UpdateLine(void);
  void SaveCalibration(void);
  void ReadCalibration(void);
#endif
