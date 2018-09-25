#include "ReceptorIR.h"

bool Sentido;
int Arranque = 0;
long long LastTime =0;

IRrecv irrecv(IR_PIN);
decode_results results;

datos Acciones[NUM_OF_ACTIONS]={{CHANNEL_ARRIBA,TerminalChannelArriba,"Canal Arriba"},
                  {CHANNEL_ABAJO,TerminalChannelAbajo,"Canal Abajo"},
                  {VOLUMEN_ARRIBA,TerminalVolumenArriba,"Volumen Arriba"},
                  {VOLUMEN_ABAJO,TerminalVolumenAbajo,"Volumen Abajo"},
                  {M_BUTTON,TerminalMButton,"Boton M"},
                  {ONE_BUTTON,TerminalOneButton,"1"},
                  {TWO_BUTTON,TerminalTwoButton,"2"},
                  {THREE_BUTTON,TerminalThreeButton,"3"},
                  {FOUR_BUTTON,TerminalFourButton,"4"},
                  {FIVE_BUTTON,TerminalFiveButton,"5"},
                  {SIX_BUTTON,TerminalSixButton,"6"},
                  {SEVEN_BUTTON,TerminalSevenButton,"7"},
                  {EIGHT_BUTTON,TerminalEightButton,"8"},
                  {NINE_BUTTON,TerminalNineButton,"9"},
                  {ZERO_BUTTON,TerminalZeroButton,"0"},
};

void receptorInit(void){
  irrecv.enableIRIn();
}

void ReceptorActions(decode_results *results) {
  int count = results->rawlen;
  
  if (results->decode_type == SONY) {
      int val = results->value;
       //Serial.println(val, HEX);
       for(int i = 0;i<NUM_OF_ACTIONS;i++){
        if(val == Acciones[i].value) {
          Acciones[i].Callback();
          digitalWrite(LED_2,HIGH);
          delay(100);
          digitalWrite(LED_2,LOW);
          break;
        }
       }
  }
}

void Receptor(void){
  if (irrecv.decode(&results)) {
    if (millis() - LastTime > 25) {
     ReceptorActions(&results);
    }
    LastTime = millis();      
    irrecv.resume(); 
  }
}

void TerminalChannelArriba(void){
  Serial.println("Canal Arriba");
}

void TerminalChannelAbajo(void){
  Serial.println("Canal Abajo");
}

void TerminalVolumenArriba(void){
  Serial.println("Volumen Arriba");
  Sentido = true;
}


void TerminalVolumenAbajo(void){
  Serial.println("Volumen Abajo");
  Sentido = false;
}

void TerminalMButton(void){
  Serial.println("Menu Button");
}

void TerminalOneButton(void){
   Serial.println("Arranque 1");
   Arranque = 1;
}

void TerminalTwoButton(void){
   Serial.println("Arriba 2");
   Arranque = 2;
}
void TerminalThreeButton(void){
   Serial.println("Arranque 3");
   Arranque = 3;
}
void TerminalFourButton(void){
   Serial.println("Arranque 4");
   Arranque = 4;
}
void TerminalFiveButton(void){
   Serial.println("Arranque 5");
   Arranque = 5;
}
void TerminalSixButton(void){
   Serial.println("Arranque 6");
   Arranque = 6;
}
void TerminalSevenButton(void){
   Serial.println("Arranque 7");
   Arranque = 7;
}
void TerminalEightButton(void){
   Serial.println("Arranque 8");
   Arranque = 8;
}
void TerminalNineButton(void){
   Serial.println("Arranque 9");
   Arranque  = 9;
}
void TerminalZeroButton(void){
   Serial.println("Arranque 0");
   Arranque = 0;
}

