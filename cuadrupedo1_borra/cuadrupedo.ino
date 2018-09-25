#include <Servo.h>

Servo CodoIzquierdoFrente,HombroIzquierdoFrente,CodoDerechoFrente,HombroDerechoFrente,CodoIzquierdoAtras,HombreIzquierdoAtras,CodoDerechoAtras,HombroDerechoAtras;

int HIF = 50,CIF = 0,HDF = 50,CDF = 0,HIA = 50,CIA = 0,HDA = 50,CDA = 0;

void setup() {
  Serial.begin(115200);  
  CodoIzquierdoFrente.attach(9);
  CodoIzquierdoFrente.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:

}

