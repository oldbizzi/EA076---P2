#include "Bluetooth.h"
#include "Motor.h"
#include "RpmInformation.h"
#include "Processador.h"
#include<SoftwareSerial.h>
#include <Arduino.h>

Bluetooth::Bluetooth(int tx, int rx): bt(tx, rx) {
  bt.begin(9600);
}

void Bluetooth::read(Processador processador, RpmInformation rpmInfo, Motor motor) {

  if (bt.available() > 0) {
    
    String comando = bt.readStringUntil('\n');
    comando = comando.substring(0, comando.length() - 2);
    bt.println(comando);
    String resposta = processador.processarComando(comando, motor, rpmInfo);
    bt.println(resposta);
  }
}

void Bluetooth::escrever(String mensagem) {
  if(bt.available() > 0) {
    bt.println(mensagem);
  }
}