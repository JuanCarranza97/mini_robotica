#include "ANALOG_MUX.h"
uint8_t MUX_;

uint16_t MUX_INPUT[NUM_SENSORS];
uint8_t pre = 0;

void MUX_init(void){
  pinMode(MUX_S0,OUTPUT);
  pinMode(MUX_S1,OUTPUT);
  pinMode(MUX_S2,OUTPUT);
  pinMode(MUX_S3,OUTPUT);

  pinMode(ANALOG_INPUT,INPUT_ANALOG);

  MUX_ = 0;

  for(uint8_t i = 0;i<NUM_SENSORS;i++) MUX_INPUT[i]=0;
  
  Timer1.setPeriod(TIMER1_PERIOD);
  Timer1.attachInterrupt(TIMER_CH1,ISR_TIMER1);
}


void MUX_output(uint8_t a){
  if(a&1) digitalWrite(MUX_S0,HIGH);
  else    digitalWrite(MUX_S0,LOW);

  if(a&2) digitalWrite(MUX_S1,HIGH);
  else    digitalWrite(MUX_S1,LOW);

  if(a&4) digitalWrite(MUX_S2,HIGH);
  else    digitalWrite(MUX_S2,LOW);

  if(a&8) digitalWrite(MUX_S3,HIGH);
  else    digitalWrite(MUX_S3,LOW);
}

void ISR_TIMER1(void){
  pre++;
  #ifdef TURBINE_ENABLE 
    ISR_Turbine();
  #endif
  
  if(pre > PREESCALER ){
  pre = 0;
  MUX_++;
  
   if(MUX_ == NUM_SENSORS) {
    MUX_ = 0;
   }
  MUX_output(MUX_);
  MUX_INPUT[MUX_]=analogRead(ANALOG_INPUT);
  }
  
}

void MUX_get(uint16_t data_[NUM_SENSORS]){
  for(uint8_t i = 0;i<NUM_SENSORS;i++) data_[i]=MUX_INPUT[i];
}


