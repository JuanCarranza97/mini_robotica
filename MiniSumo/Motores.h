#ifndef MOTORES_H
#define MOTORES_H
  #include <Arduino.h>

  #define IN1     9
  #define IN2    10
  #define IN3     6
  #define IN4     5

  void motorsInit(void);
  void setLeftMotor(int x);
  void setrightMotor(int x);  
  void setMotors(int a,int b);
#endif
