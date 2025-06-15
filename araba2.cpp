// Deneyap Kart IDE | Mobil Robotu Bluetooth Bağlantısı

#include "BluetoothSerial.h"

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7
int hiz =255;
char veri;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("DeneyapKart");
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorRE, OUTPUT);
  pinMode(motorLE, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    veri=(char)SerialBT.read();
    
    switch(veri) {
      case 'W':
        digitalWrite(motorR1, HIGH);
        digitalWrite(motorR2, LOW);
        digitalWrite(motorRE, hiz);
        digitalWrite(motorL1, HIGH);
        digitalWrite(motorL2, LOW);
        digitalWrite(motorLE, hiz);
        break;
      
      case 'S':
        digitalWrite(motorR1, LOW);
        digitalWrite(motorR2, HIGH);
        digitalWrite(motorRE, hiz);
        digitalWrite(motorL1, LOW);
        digitalWrite(motorL2, HIGH);
        digitalWrite(motorLE, hiz);
        break;

      case 'A':
        digitalWrite(motorR1, LOW);
        digitalWrite(motorR2, HIGH);
        digitalWrite(motorRE, hiz);
        digitalWrite(motorL1, HIGH);
        digitalWrite(motorL2, LOW);
        digitalWrite(motorLE, hiz);
        break;

      case 'D':
        digitalWrite(motorR1, HIGH);
        digitalWrite(motorR2, LOW);
        digitalWrite(motorRE, hiz);
        digitalWrite(motorL1, LOW);
        digitalWrite(motorL2, HIGH);
        digitalWrite(motorLE, hiz);
        break;

      if (hiz>0) {
        hiz=hiz-1;
        break;
      }

      case '0':
        digitalWrite(motorR1, HIGH);
        digitalWrite(motorR2, LOW);
        digitalWrite(motorRE, 0);
        digitalWrite(motorL1, HIGH);
        digitalWrite(motorL2, LOW);
        digitalWrite(motorLE, 0);
        break;

      if (hiz<255) {
        hiz=hiz+1;
        break;
      }
    }
  }
}