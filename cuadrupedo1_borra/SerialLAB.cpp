#include "SerialLaB.h"
uint16_t _sensors[NUM_SENSORS];

extern int Posicion;
extern PID_Controller lateralPID,turbinePID,centralPID;
extern int16_t MainSpeed;
extern int16_t Turbine;
extern int16_t increment;
extern int MinRan,MaxRan;

void SerialLabActions(void){
  if(UART_PORT.available()){
      char caracter;
      int Numbers[20];
      int bufferSize=0;

      UART_get(&caracter,&bufferSize,Numbers);

      switch(caracter){
        default:
         UART_PORT.println("--------LineSTM BORRA V2.0--------\n\n-------------Help Menu------------");
         UART_PORT.println("Set Left Motor: "+String(SET_LEFT_MOTOR)+"vel - L500");
         UART_PORT.println("Set Right Motor: "+String(SET_RIGHT_MOTOR)+"vel - R500");
        break;

        case SET_LEFT_MOTOR:
          SetLeftMotor(Numbers[0]);
            #ifdef UART_RESPONSE
              UART_PORT.println("Set Left Motor: "+String(Numbers[0]));
            #endif
        break;

        case SET_RIGHT_MOTOR:
         SetRightMotor(Numbers[0]);
            #ifdef UART_RESPONSE
              UART_PORT.println("Set Right Motor: "+String(Numbers[0]));
             #endif
        break;

        case QTR_SENSORS:       
                 MUX_get(_sensors);                
                  for(int i = 0;i<NUM_SENSORS;i++) {
                    UART_PORT.println(QTR_SENSORS+String(i)+","+String(_sensors[i]));              
                  }
        break;

        case TURBINE_INCREMENT:
             increment = Numbers[0];
        break;
        case MAP_QTR_SENSORS:
            GetMapValues(_sensors);
                 for(int i = 0;i<NUM_SENSORS;i++) {
                    UART_PORT.println(MAP_QTR_SENSORS+String(i)+","+String(_sensors[i]));              
                  }       
             break;

        case SHOW_CALIBRATED:
            ShowCalibratedValues();
            break;

        case CALIBRATE_SENSORS:
           delay(1500);
           LED1_ON;
           Line_calibrate(500000);
           LED1_OFF;
           ShowCalibratedValues();
           break;

        case SET_TURBINE:
            Turbine = Numbers[0];
          break;

        case SEND_POSITION:
             UART_PORT.println(SEND_POSITION+String(Posicion));
             break;

        case MAIN_SPEED:
             MainSpeed = Numbers[0];
        break;

        case MIN_RANG:
             MinRan = Numbers[0];
        break;

        case MAX_RANG:
             MaxRan = Numbers[0];
        break;
        
        case UPDATE_PID:
             switch(Numbers[0]){
              case LATERAL_PID:
                  lateralPID.Update(Numbers[1],Numbers[2]);
                break;

               case TURBINE_PID:
                  turbinePID.Update(Numbers[1],Numbers[2]);
               break;

               case CENTRAL_PID:
                   centralPID.Update(Numbers[1],Numbers[2]);
               break;

               default:
                 UART_PORT.println("PID no encontrado");
               break;
                 
             }
             break;

        case SAVE_EEPROM:
             SaveEEPROM();
             break;

        case READ_EEPROM:
             ReadEEPROM();
             break;

        case READ_VALUES:
             UART_PORT.println(MAIN_SPEED+String(MainSpeed));
             delay(1);
             UART_PORT.println(SET_TURBINE+String(Turbine));
             delay(1);
             UART_PORT.println(MIN_RANG+String(MinRan));
             delay(1);
             UART_PORT.println(MAX_RANG+String(MaxRan));
             delay(1);

               for(uint8_t i = 0;i<3;i++){
                switch(i){
                  case LATERAL_PID:
                       for(uint8_t j=0;j < EEPROM_DATA;j++){
                        UART_PORT.println(UPDATE_PID+String(i)+","+String(j)+","+String(lateralPID.GetValue(j)));
                        delay(1);
                       }
                       break;

                  case TURBINE_PID:
                       for(uint8_t j=0;j < EEPROM_DATA;j++){
                        UART_PORT.println(UPDATE_PID+String(i)+","+String(j)+","+String(turbinePID.GetValue(j)));
                        delay(1);
                       }
                       break;

                  case CENTRAL_PID:
                       for(uint8_t j=0;j < EEPROM_DATA;j++){
                        UART_PORT.println(UPDATE_PID+String(i)+","+String(j)+","+String(centralPID.GetValue(j)));
                        delay(1);
                       }
                       break;
                }
               }
             break;

             case SAVE_CALIBRATION_E:
                       SaveCalibration();
                       break;

            case READ_CALIBRATION_E:
                 ReadCalibration();
                 break;
      }
  }
}

