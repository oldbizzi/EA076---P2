
#include "Motor.h"
#include "RpmInformation.h"
#include "Processador.h"
#include<SoftwareSerial.h>
#include<Arduino.h>
#ifndef BLUETOOTH_H
#define BLUETOOTH_H

class Bluetooth {

    public: 
      Bluetooth(int tx, int rx);
      void read(Processador processador, RpmInformation rpm, Motor motor);
      void escrever(String mensagem);
    private:
      SoftwareSerial bt;
};

#endif