#include "Turbine.h"

#ifdef TURBINE_ENABLE
  int16_t servoCount = 0;
  int16_t TurbineSpeed = 0;
  int16_t TurbineValue = 0;
  int16_t count2 =0;
  int16_t increment = 450;
  
void Turbine_init(void){
  pinMode(PB11,OUTPUT);
  //Timer2.setPeriod(10);
  //Timer2.attachInterrupt(TIMER_CH1,ISR_TIMER2);
}
void ISR_Turbine(void){

  int16_t temp = TurbineSpeed > 100?100:TurbineSpeed;
  temp = TurbineSpeed < 0?0:TurbineSpeed;
  
   temp = map(TurbineSpeed,0,100,MIN_TURBINE,MAX_TURBINE);
  
  servoCount++;
  count2++;
  
  if(count2 > increment){
    if(TurbineValue < temp) TurbineValue+=1;
    else if(TurbineValue > temp) TurbineValue-=1;
    count2=0;
  }
  
  if(servoCount == 200) {
    servoCount = 0;
    digitalWrite(PB11,HIGH);
  }
      if(servoCount > TurbineValue) digitalWrite(PB11,LOW);
}

#endif

