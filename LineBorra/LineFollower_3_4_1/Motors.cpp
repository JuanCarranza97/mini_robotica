#include "Motors.h"

 void Motors_init(void){
  pinMode(LEFT_MOTOR_PWM,PWM);
  pinMode(RIGHT_MOTOR_PWM,PWM);
  pinMode(LEFT_MOTOR_IN1,OUTPUT);
  pinMode(LEFT_MOTOR_IN2,OUTPUT);
  pinMode(RIGHT_MOTOR_IN1,OUTPUT);
  pinMode(RIGHT_MOTOR_IN2,OUTPUT);
  
  pwmWrite(LEFT_MOTOR_PWM,0);
  pwmWrite(RIGHT_MOTOR_PWM,0);
 }
 
 void SetLeftMotor(int16_t _left){
  _left = _left>1000?1000:_left;
  _left = _left<-1000?-1000:_left;
  
   if(_left == 0)
     {
       digitalWrite(LEFT_MOTOR_IN1,LOW);
       digitalWrite(LEFT_MOTOR_IN2,LOW);
       pwmWrite(LEFT_MOTOR_PWM,0);
     }
    else if(_left > 0)
     {
      digitalWrite(LEFT_MOTOR_IN1,LOW);
      digitalWrite(LEFT_MOTOR_IN2,HIGH);
      pwmWrite(LEFT_MOTOR_PWM,map(_left,0,1000,0,65535));
     }
  else{
      digitalWrite(LEFT_MOTOR_IN1,HIGH);
      digitalWrite(LEFT_MOTOR_IN2,LOW);
      pwmWrite(LEFT_MOTOR_PWM,map(_left,0,-1000,0,65535));
   }
 }
  void SetRightMotor(int16_t _right){
  _right = _right>1000?1000:_right;
  _right = _right<-1000?-1000:_right;
  
    if(_right== 0)
   {
    digitalWrite(RIGHT_MOTOR_IN1,LOW);
    digitalWrite(RIGHT_MOTOR_IN2,LOW);
    pwmWrite(RIGHT_MOTOR_PWM,0);
   }
  else if(_right > 0)
   {
    digitalWrite(RIGHT_MOTOR_IN1,LOW);
    digitalWrite(RIGHT_MOTOR_IN2,HIGH);
    pwmWrite(RIGHT_MOTOR_PWM,map(_right,0,1000,0,65535));
   }
  else{
    digitalWrite(RIGHT_MOTOR_IN1,HIGH);
    digitalWrite(RIGHT_MOTOR_IN2,LOW);
    pwmWrite(RIGHT_MOTOR_PWM,map(_right,0,-1000,0,65535));
   }
  }
  
 void SetMotors(int16_t _left,int16_t _right){
   SetLeftMotor(_left);
   SetRightMotor(_right);
 }
