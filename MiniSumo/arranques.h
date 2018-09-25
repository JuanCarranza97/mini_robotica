#ifndef ARRANQUE1_H
#define ARRANQUE1_H
   #include <Arduino.h>
   #include "GPIO.h"
   #include "Motores.h"

   typedef void (*InicioCallback)(void);
   
   typedef struct{
      InicioCallback Callback;
      const char *HelpString;
    }inicios;

   void IniciosOrillas(int x);

   void inicioOrilla0(void);
   void inicioOrilla1(void);
   void inicioOrilla2(void);
#endif
