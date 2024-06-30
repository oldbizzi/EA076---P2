#include "I2C.h"
#include "RpmInformation.h"
#include <Arduino.h>
#include <Wire.h>

I2C::I2C(int porta, int endereco, int display3, int display2, int display1, int display0) {
  this->porta = porta;
  this->endereco = endereco;
  this->displayAtivo = 1;
  this->displays[3] = display3;
  this->displays[2] = display2;
  this->displays[1] = display1;
  this->displays[0] = display0;

};

void I2C::escreverDisplay(RpmInformation rpmInfo) {

  displayAtivo++;

  if (displayAtivo > 4) {
    displayAtivo = 1;
  }

  int valorTransmitido;
  switch (displayAtivo) {
    case 1:
      valorTransmitido = displays[3] + rpmInfo.getMilhar();
      break;
    case 2:
      valorTransmitido = displays[2] + rpmInfo.getCentena();
      break;
    case 3:
      valorTransmitido =  displays[1]+  rpmInfo.getDezena();
      break;
    case 4:
      valorTransmitido =  displays[0] + rpmInfo.getUnidade();
      break;
  }

  this->transmitir(valorTransmitido);
};

void I2C::transmitir(byte val) {

  Wire.beginTransmission(porta);
  Wire.write(val);
  Wire.endTransmission();
};