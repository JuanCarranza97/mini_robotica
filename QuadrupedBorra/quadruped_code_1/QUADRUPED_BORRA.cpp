#include "QUADRUPED_BORRA.h"

Servo articulacion[8];

int servosPinOut[8]={2,3,4,5,6,7,8,9};

const int servos_addr[8]={CIF_ADDR,HIF_ADDR,CDF_ADDR,HDF_ADDR,CIA_ADDR,HIA_ADDR,CDA_ADDR,HDA_ADDR};

void saveEEPROM(void){
  for(int i=0;i<8;i++){
    EEPROM.write((byte)(servos_addr[i]),(byte)(servosPinOut[i]));
  }
}

void readEEPROM(void){
  for(int i = 0;i<8;i++){
    servosPinOut[i]=(int)(EEPROM.read((byte)(servos_addr[i])));
  }
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float getVoltage(void){
  return(mapfloat(analogRead(A7),787,842,7.76,8.31));
}

