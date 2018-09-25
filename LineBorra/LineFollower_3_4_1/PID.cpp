#include "PID.h"

PID_Controller::PID_Controller(){
  
}

void PID_Controller::Compute(float input){
  if((millis()-LastTime)>SampleTime){
    //UART_PORT.println("Kp = "+String(Kp)+", Ki = "+String(Ki)+", Kd = "+String(Kd)+", SetPoint = "+String(SetPoint)+", Samples = "+String(SampleTime));
    
    float Error = 7500-input;
    sumError += Error;
    P = (Error*(float(Kp)/Kp_Div));
    I = ((float(Ki)/Ki_Div)*(float(SampleTime)/1000.0)*sumError);
    D = ((float(Kd)/Kd_Div)*(Error-prevError)/(float(SampleTime)/1000.0));
 
      D = D > MaxD?MaxD:D;
      D = D < -MaxD?-MaxD:D;

      I = I > MaxI?MaxI:I;
      I = I < -MaxI?-MaxI:I;
   
    U = P+I+D;
    prevError = Error;
    //UART_PORT.println("input = "+String(input)+", U = "+String(U));
    LastTime = millis();
  }
 
}

void PID_Controller::reset(void){
  sumError = 0;
  prevError = 0;
}

void PID_Controller::Update(uint8_t x,int val){
  switch(x){
    case KP_CONFIG:
      Kp = val;
    break;

    case KI_CONFIG:
      Ki = val;
    break;

    case KD_CONFIG:
      Kd = val;
    break;    

    case SAMPLE_TIME_CONFIG:
      SampleTime = val;
    break;

    case SET_POINT:
      SetPoint = val;
      break;

    case MAXD_CONFIG:
        MaxD = val;
      break;

    case MAXI_CONFIG:
       MaxI = val;
      break;

    default:
    break;
  }
}

void PID_Controller::FirstADDR_EEPROM(uint16_t first){
  for(uint8_t i = 0;i<EEPROM_DATA;i++){
    EEPROM_ADDRS[i]=i+first;
  }
  LastADDR = EEPROM_DATA+first;
}

void PID_Controller::SaveEEPROM(void){
  for(int i = 0;i<EEPROM_DATA;i++){
    uint16_t val;
     switch(i){
       case KP_CONFIG:
          val=Kp;
          break;

       case KI_CONFIG:
          val = Ki;
          break;

       case KD_CONFIG:
          val = Kd;
          break;    

       case SAMPLE_TIME_CONFIG:
          val = SampleTime;
          break;

       case SET_POINT:
         val = SetPoint;
         break;

       case MAXD_CONFIG:
         val = MaxD;
         break;

       case MAXI_CONFIG:
         val = MaxI;
         break;

        default:
        break;
     }
     EEPROM.write(EEPROM_ADDRS[i],val);
  }
}

void PID_Controller::ReadEEPROM(void){
  for(uint8_t i = 0;i<EEPROM_DATA;i++){
      switch(i){
       case KP_CONFIG:
          Kp = EEPROM.read(EEPROM_ADDRS[i]);
          break;

       case KI_CONFIG:
          Ki = EEPROM.read(EEPROM_ADDRS[i]);
          break;

       case KD_CONFIG:
          Kd = EEPROM.read(EEPROM_ADDRS[i]);
          break;    

       case SAMPLE_TIME_CONFIG:
          SampleTime = EEPROM.read(EEPROM_ADDRS[i]);
          break;

       case SET_POINT:
         SetPoint = EEPROM.read(EEPROM_ADDRS[i]);
         break;

       case MAXD_CONFIG:
         MaxD = EEPROM.read(EEPROM_ADDRS[i]);
         break;

       case MAXI_CONFIG:
         MaxI = EEPROM.read(EEPROM_ADDRS[i]);
         break;

        default:
        break;
     }
  }
}

int  PID_Controller::GetValue(uint8_t x){
  switch(x){
       case KP_CONFIG:
          return(Kp);
          break;

       case KI_CONFIG:
          return(Ki);
          break;

       case KD_CONFIG:
          return(Kd);
          break;    

       case SAMPLE_TIME_CONFIG:
          return(SampleTime);
          break;

       case SET_POINT:
         return(SetPoint);
         break;

       case MAXD_CONFIG:
         return(MaxD);
         break;

       case MAXI_CONFIG:
         return(MaxI);
         break;

        default:
        break;
     }
}

