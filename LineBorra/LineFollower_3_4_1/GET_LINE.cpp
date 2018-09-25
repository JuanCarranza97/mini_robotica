#include "GET_LINE.h"

uint16_t MinSensors[NUM_SENSORS];
uint16_t MaxSensors[NUM_SENSORS];
uint16_t SensorsValues[NUM_SENSORS];
uint16_t Max = 0;
int Posicion = 0;
int LastPosicion = 0;
int LineaBlanca = false;
int SensorsDetected = 0;
int LastRect = 0;

void Init_Timer2(void){
  Timer2.setPeriod(TIMER2_PERIOD);
  Timer2.attachInterrupt(TIMER_CH1,UpdateLine);
}

void Line_calibrate(int a){
  for(uint8_t i = 0;i<NUM_SENSORS;i++){
    MinSensors[i]=4095;
    MaxSensors[i]=0;
  }
  
  for(int j = 0;j<a;j++){
      MUX_get(SensorsValues);
    for(uint8_t i = 0;i<NUM_SENSORS;i++){
      MinSensors[i]=SensorsValues[i] < MinSensors[i]?SensorsValues[i]:MinSensors[i];
      MaxSensors[i]=SensorsValues[i] > MaxSensors[i]?SensorsValues[i]:MaxSensors[i];
    }
  }    
}

void ShowCalibratedValues(void){
  for(uint8_t i = 0;i<NUM_SENSORS;i++){
    UART_PORT.println("L"+String(i)+","+String(MinSensors[i]));
  }
  for(uint8_t i = 0;i<NUM_SENSORS;i++){
    UART_PORT.println("U"+String(i)+","+String(MaxSensors[i]));
  }  
}

void GetMapValues(uint16_t values[NUM_SENSORS]){
  MUX_get(values);
  SensorsDetected = 0;
  
  for(int i = 0;i<NUM_SENSORS;i++){
    values[i] = values[i]<MinSensors[i]?MinSensors[i]:values[i];
    values[i] = values[i]>MaxSensors[i]?MaxSensors[i]:values[i];
    if(LineaBlanca) values[i]=map(values[i],MinSensors[i],MaxSensors[i],MIN_VALUE,MAX_VALUE);
    else            values[i]=map(values[i],MinSensors[i],MaxSensors[i],MAX_VALUE,MIN_VALUE);  

    if(values[i]<400) {
      values[i]=0;
    }
    else{
      SensorsDetected++;
      LastRect = i;
    }
  }
}

void UpdateLine(void){
  bool OnLine = false;
  int num=0;
  int den = 0;
  uint16_t values[NUM_SENSORS];
  MUX_get(values);
  Max =0;
  SensorsDetected = 0;
  for(uint8_t i = 0;i< NUM_SENSORS;i++){
    values[i] = values[i]<MinSensors[i]?MinSensors[i]:values[i];
    values[i] = values[i]>MaxSensors[i]?MaxSensors[i]:values[i];
    
    if(LineaBlanca) values[i]=map(values[i],MinSensors[i],MaxSensors[i],MIN_VALUE,MAX_VALUE);
    else            values[i]=map(values[i],MinSensors[i],MaxSensors[i],MAX_VALUE,MIN_VALUE);  

    if(values[i]<400) {
      values[i]=0;
    }
    else{
      SensorsDetected++;
      LastRect = i;
    }
    
    num+=i*values[i]*1000;
    den+=values[i];
    
      if(i != 0) {
        if(((values[i]-values[i-1]) > 250) || ((values[i]-values[i-1]) < -250)) {
          OnLine = true;
        }
      }   
  }
  if(OnLine){
    Posicion = num/den;   
    LastPosicion = Posicion;
  }
  else{
    if(LastPosicion < (((int)(NUM_SENSORS)-1)*500)) Posicion = 0;
    else        Posicion = (((int)(NUM_SENSORS)-1)*1000);
  }
  //return(Posicion);
}

void SaveCalibration(void){
  for(int i = 0;i<NUM_SENSORS;i++){
    EEPROM.write((FIRST_ADDR_MIN)+i,MinSensors[i]);
    EEPROM.write((FIRST_ADDR_MIN)+16+i,MaxSensors[i]);
  }
  
}

void ReadCalibration(void){
  for(int i = 0;i<NUM_SENSORS;i++){
    MinSensors[i]=EEPROM.read((FIRST_ADDR_MIN)+i);
    MaxSensors[i]=EEPROM.read((FIRST_ADDR_MIN)+i+16);
  }
  ShowCalibratedValues();
}

