#ifndef SerialLAB_H
#define SerialLAB_H
  #include "UART.h"
  #include "Motors.h"
  #include "ANALOG_MUX.h"
  #include "GPIO.h"
  #include "GET_LINE.h"
  #include "Turbine.h"
  #include "PID.h"
  #include "LineSTM.h"
  //#define UART_RESPONSES 
  
  #define SET_LEFT_MOTOR     'L'
  #define SET_RIGHT_MOTOR    'R'
  #define QTR_SENSORS        'Q'
  #define MAP_QTR_SENSORS    'M'
  #define SHOW_CALIBRATED    'G'
  #define CALIBRATE_SENSORS  'C'
  #define SET_TURBINE        'T'
  #define TURBINE_INCREMENT  'I'
  #define SEND_POSITION      'P'
  #define UPDATE_PID         'U'
  #define MAIN_SPEED         'S'
  #define MIN_RANG           'E'
  #define MAX_RANG           'D'
  #define SAVE_EEPROM        'W'
  #define READ_EEPROM        'K'
  #define READ_VALUES        'Y'
  #define SAVE_CALIBRATION_E   'A'
  #define READ_CALIBRATION_E   'B'
  
  #define LATERAL_PID         0
  #define TURBINE_PID         1
  #define CENTRAL_PID         2
  
  void SerialLabActions(void);
#endif
