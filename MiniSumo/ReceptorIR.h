#ifndef ReceptorIR_H
#define ReceptorIT_H

   #include <Arduino.h>
   #include "IRremote.h"
   #include "GPIO.h"
   
   #define IR_PIN          2

   #define NUM_OF_ACTIONS  15
   

   /***********/
   #define  CHANNEL_ARRIBA     0x90
   #define  CHANNEL_ABAJO      0x890
   #define  VOLUMEN_ARRIBA     0x490
   #define  VOLUMEN_ABAJO      0xC90
   #define  M_BUTTON           0x70
   #define  TV_AV              0xA50
   #define  MUTE               0x290
   #define  TIMER_BUTTON       0x6D0
   #define  OK_BUTTON          0xA70
   #define  PIP_BUTTON         0xDB0
   #define  ONE_BUTTON         0x10
   #define  TWO_BUTTON         0x810
   #define  THREE_BUTTON       0x410
   #define  FOUR_BUTTON        0xC10
   #define  FIVE_BUTTON        0x210
   #define  SIX_BUTTON         0xA10
   #define  SEVEN_BUTTON       0x610
   #define  EIGHT_BUTTON       0xE10
   #define  NINE_BUTTON        0x110
   #define  RAYITAS_BUTTON     0x310
   #define  ZERO_BUTTON        0x910
   #define  RETURN_BUTTON      0xA70
   
   typedef void (*TerminalCallback)(void);

    typedef struct{
      const int value;
      TerminalCallback Callback;
      const char *HelpString;
    }datos;

    void receptorInit(void);
    void Receptor(void);
    void ReceptorActions(decode_results *results);

    void TerminalChannelArriba(void);
    void TerminalChannelAbajo(void);
    void TerminalVolumenArriba(void);
    void TerminalVolumenAbajo(void);
    void TerminalMButton(void);
    void TerminalOneButton(void);
    void TerminalTwoButton(void);
    void TerminalThreeButton(void);
    void TerminalFourButton(void);
    void TerminalFiveButton(void);
    void TerminalSixButton(void);
    void TerminalSevenButton(void);
    void TerminalEightButton(void);
    void TerminalNineButton(void);
    void TerminalZeroButton(void);
#endif
