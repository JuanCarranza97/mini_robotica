#include "LineSTM.h"

extern int16_t Turbine;
extern int16_t MainSpeed;
extern int MinRan,MaxRan;
extern PID_Controller lateralPID,turbinePID,centralPID;
extern int LineaBlanca;
extern int TurnTime,MaxN,MinN;

void LineSTM_init(void){
  GPIO_init();
  Motors_init();
  MUX_init();
  UART_init();
  #ifdef TURBINE_ENABLE
    Turbine_init();
  #endif
  Init_Timer2();
}

void SaveEEPROM(void){
  EEPROM.write(Turbine_ADDR,Turbine);
  EEPROM.write(MinRan_ADDR,MinRan);
  EEPROM.write(MaxRan_ADDR,MaxRan);
  EEPROM.write(MainSpeed_ADDR,MainSpeed);
  EEPROM.write(LineColor_ADDR,LineaBlanca);
  EEPROM.write(MIN_TURN_ADDR,MinN);
  EEPROM.write(MAX_TURN_ADDR,MaxN);
  EEPROM.write(TURN_TIME_ADDR,TurnTime);
  lateralPID.SaveEEPROM();
  centralPID.SaveEEPROM();
  turbinePID.SaveEEPROM();
}

void ReadEEPROM(void){
  Turbine = EEPROM.read(Turbine_ADDR);
  MinRan = EEPROM.read(MinRan_ADDR);
  MaxRan = EEPROM.read(MaxRan_ADDR);
  MainSpeed = EEPROM.read(MainSpeed_ADDR);
  MinN = EEPROM.read(MIN_TURN_ADDR);
  MaxN = EEPROM.read(MAX_TURN_ADDR);
  TurnTime = EEPROM.read(TURN_TIME_ADDR);
  LineaBlanca = EEPROM.read(LineColor_ADDR);;
  
  lateralPID.ReadEEPROM();
  centralPID.ReadEEPROM();
  turbinePID.ReadEEPROM();
}

