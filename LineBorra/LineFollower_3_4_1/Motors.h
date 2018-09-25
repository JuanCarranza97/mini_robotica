#ifndef Motors_H
#define Motors_H
 #include <Arduino.h>

 #define LEFT     0
 #define RIGHT    1
  
  //CONFIGURACION Y VARIABLES MOTORES
   #define LEFT_MOTOR_PWM      PA6    
   #define RIGHT_MOTOR_PWM     PA7    

   #define LEFT_MOTOR_IN1      PB9
   #define LEFT_MOTOR_IN2      PB0
   #define RIGHT_MOTOR_IN1     PB1
   #define RIGHT_MOTOR_IN2     PB10

   void Motors_init(void);
   void SetLeftMotor(int16_t _left);
   void SetRightMotor(int16_t _right);
   void SetMotors(int16_t _left,int16_t _right);
#endif
