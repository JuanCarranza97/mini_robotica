#include "Motores.h"

void motorsInit(void){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void setLeftMotor(int x){
  if(x >= 0){
    analogWrite(IN1,map(x,0,100,0,255));
    analogWrite(IN2,0);
  }
  else{
    analogWrite(IN1,0);
    analogWrite(IN2,map(x,0,-100,0,255));
  }
}

void setRightMotor(int x){
  if(x >= 0){
    analogWrite(IN3,map(x,0,100,0,255));
    analogWrite(IN4,0);
  }
  else{
    analogWrite(IN3,0);
    analogWrite(IN4,map(x,0,-100,0,255));
  }
}

void setMotors(int a,int b){
  setLeftMotor(a);
  setRightMotor(b);
}

