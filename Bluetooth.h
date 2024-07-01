
#include "Motor.h"
#include "RpmInformation.h"
#include "Processador.h"
#include<SoftwareSerial.h>
#include<Arduino.h>
#ifndef BLUETOOTH_H
#define BLUETOOTH_H

/**
 * Classe responsável pela manipulação do módulo bluetooth e chamada do processamento dos comandos
 * Atributos:
 * bt: objeto para a leitura do canal aberto com o Bluetooth
 */
class Bluetooth {

    public: 
      Bluetooth(int tx, int rx);
      void read(Processador processador, RpmInformation rpm, Motor motor);
      void escrever(String mensagem);
    private:
      SoftwareSerial bt;
};

#endif