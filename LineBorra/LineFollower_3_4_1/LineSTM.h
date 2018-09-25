#ifndef LineSTM_H
#define LineSTM_H

  #include <EEPROM.h>
  #include <flash_stm32.h>

  #include "GPIO.h"
  #include "Motors.h"
  #include "ANALOG_MUX.h"
  #include "UART.h"
  #include "SerialLaB.h"
  #include "GET_LINE.h"
  #include "Turbine.h"
  #include "PID.h"

  #define NUM_TICKERS 3

  
    /*****Direcciones*///////
      #define Turbine_ADDR      50 
      #define MinRan_ADDR       51
      #define MaxRan_ADDR       52
      #define MainSpeed_ADDR    53
      #define LineColor_ADDR    54
      #define MIN_TURN_ADDR     55
      #define MAX_TURN_ADDR     56
      #define TURN_TIME_ADDR    57
    ///*********************//

  void LineSTM_init(void);
  void SaveEEPROM(void);
  void ReadEEPROM(void);
#endif

