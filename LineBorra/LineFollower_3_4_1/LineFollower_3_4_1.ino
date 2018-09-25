#include "LineSTM.h"

extern bool state_turbine;
extern int16_t TurbineSpeed;
int16_t Turbine = 60;
extern int Posicion;
int16_t MainSpeed=200;
PID_Controller lateralPID,turbinePID,centralPID;
extern int16_t increment;
bool ViewPID = false;
bool turbineActive = false;
int Ticker[NUM_TICKERS];
int MinRan =4000,MaxRan = 11000;
uint8_t pos = 0;
bool Noventa=false;
int TurnTime = 10;

int MaxN = 200;
int MinN = -200;
extern int SensorsDetected;
extern int LastRect;
bool Tc=false;
int last = 0;
int lastIn ;
void setup() {
  // put your setup code here, to run once:
  LineSTM_init();
  LED1_ON;
  delay(1500);
  ReadCalibration();
  LED1_OFF;
  delay(1000);
  //LED1_ON;
  //(Line_calibrate(500000);
  //LED1_OFF;
  Timer3.setPeriod(1000);
  Timer3.attachInterrupt(TIMER_CH1,ISR_TIMER3);

    lateralPID.FirstADDR_EEPROM(10);
    lateralPID.ReadEEPROM();   
    //lateralPID.SetPoint = 7500;
    //lateralPID.Kp = 300;
    //lateralPID.Ki = 0;
    //lateralPID.Kd = 370;
    lateralPID.Kp_Div = 10000;
    lateralPID.Kd_Div = 100000;
    lateralPID.Ki_Div = 10000;
    //lateralPID.SampleTime = 10;
    //lateralPID.MaxD = 450;
    //lateralPID.MaxI = 400;
    //lateralPID.SaveEEPROM();

    centralPID.FirstADDR_EEPROM(lateralPID.LastADDR);
    centralPID.ReadEEPROM(); 
    //centralPID.SetPoint = 7500;
    //centralPID.Kp = 300;
    //centralPID.Ki = 0;
    //centralPID.Kd = 370;
    centralPID.Kp_Div = 10000;
    centralPID.Kd_Div = 100000;
    centralPID.Ki_Div = 1000000;
    //centralPID.SampleTime = 10;
    //centralPID.MaxD = 450;
    //centralPID.MaxI = 400;
    //centralPID.SaveEEPROM();
    
    turbinePID.FirstADDR_EEPROM(centralPID.LastADDR);
    turbinePID.ReadEEPROM();
    //turbinePID.SetPoint = 7500;
    //turbinePID.Kp = 0;
    //turbinePID.Kd = 90;
    //turbinePID.Ki = 0;
    turbinePID.Kp_Div = 10000;
    turbinePID.Kd_Div = 100000;
    turbinePID.Ki_Div = 10000;
    //turbinePID.SampleTime = 10;
    //turbinePID.MaxD = 70;
    //turbinePID.MaxI = 20;
    //turbinePID.SaveEEPROM();

    ReadEEPROM();
    lastIn = increment;
}

void loop() {
  SerialLabActions();
  BotonesMenu();

    lateralPID.Compute(float(Posicion));
    turbinePID.Compute(float(Posicion));
    centralPID.Compute(float(Posicion));
    
    if(Posicion < MinRan){
       //LED2_ON;
       //LED1_OFF;
       pos = 0;
    }
    else if(Posicion >= MinRan && Posicion <= MaxRan){
       //LED2_ON;
       //LED1_ON;
       pos = 1;
    }
    else{
       //LED2_OFF;
       //LED1_ON;
       pos = 2;
    }

    if(SensorsDetected >  5 ) {
      if(LastRect < 11) {  //Hacia la izquierda
        LED2_ON;
        LED1_OFF;
      }
      else{
        LED2_OFF;
        LED1_ON;
      }
     
    }
  
      if(INPUT_GO) {
          if(Tc == false){
            Ticker[2]=0;
            Tc = true;
            increment = 800;
          }

          if(Ticker[2] < 1000){
            increment = 800;
          }
          else{
            increment = lastIn;
          }
          if(turbinePID.U < 0 ) TurbineSpeed = Turbine -turbinePID.U;
          else                  TurbineSpeed = Turbine +turbinePID.U;
        
            if(ViewPID == 0) {
                if(pos != 1) {
                  if(Noventa== true && SensorsDetected >  5)    {
                      if(LastRect < 11)           {
                        SetMotors(-MinN,MaxN);
                        Ticker[1]=0;
                        while((Ticker[1] < TurnTime) && INPUT_GO);
                      }
                      else                       {
                        SetMotors(MaxN,-MinN);
                        Ticker[1]=0;
                        while((Ticker[1] < TurnTime) && INPUT_GO);
                      }
                  }
                  else {                  
                     SetMotors(MainSpeed-lateralPID.U,MainSpeed+ lateralPID.U);
                  }
                }
                else{
                  if(Noventa == true && SensorsDetected > 5)  {
                     if(LastRect < 11)          {
                      SetMotors(-MinN,MaxN);
                      Ticker[1]=0;
                      do{
                      }while((Ticker[1] < TurnTime));
                     }
                     else                        {
                      SetMotors(MaxN,-MinN);
                      Ticker[1]=0;
                      do{
                      }while((Ticker[1] < TurnTime));
                     }
                  }
                  else{
                     SetMotors(MainSpeed-centralPID.U,MainSpeed+ centralPID.U);
                  }
                }
            }
            else{         
              SetMotors(0,0);
            }  
            turbineActive = false;
        }
      else        {
          turbinePID.reset();
          lateralPID.reset();
          centralPID.reset();
          SetMotors(0,0);
          Tc = false;
          Ticker[2]=0;
          if(turbineActive){
             TurbineSpeed = Turbine;
          }
          else{
            TurbineSpeed = 0;
          }
      }  
}

void ISR_TIMER3(void){
  for(int i = 0;i< NUM_TICKERS;i++) Ticker[i]++;
 }
  
void BotonesMenu(void){
  if(PUSH2_PRESSED){
    ViewPID = !ViewPID;
      if(ViewPID) LED2_ON;
      else        LED2_OFF;
    while(PUSH2_PRESSED);
    delay(50);    
  }

  if(PUSH3_PRESSED){
    turbineActive = !turbineActive;
    while(PUSH3_PRESSED);
    delay(50);    
  }

  if(PUSH1_PRESSED){
    Noventa = !Noventa;
    if(Noventa) LED1_ON;
      else        LED1_OFF;
    while(PUSH1_PRESSED);
    delay(50);    
  }
}




