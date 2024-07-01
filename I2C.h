#include "RPMInformation.h"
#include <Arduino.h>
#ifndef I2C_H
#define I2C_H

/**
 * Classe responsável pela comunicação I2C com os displays de 7 segmentos
 * Atributos:
 * porta e endereco: endereço de comunicação com o protocolo I2C
 * displays: valor em cada display a ser exibido
 */
class I2C {
    public:
      I2C(int porta, int endereco, int display3, int display2, int display1, int display0);
      void escreverDisplay(RpmInformation rpmInformation);

    private:
      void transmitir(byte valor);
      int displayAtivo;
      int porta;
      int endereco;
      int displays[4];
};

#endif