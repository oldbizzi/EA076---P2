#ifndef RPMINFORMATION_H
#define RPMINFORMATION_H
#include <Arduino.h>
#include "Encoder.h"

/**
 * Classe responsável pela manipuação dos valores de rpm
 * Atributos:
 * rpm: última leitura da velocidade do motor feita pelo encoder
 * milhar: número de milhares do rpm
 * centena: número de centenas do rpm
 * dezena: número de dezenas do rpm
 * unidade: número de unidades do rpm
 */
class RpmInformation {
  public:
    RpmInformation(int temp);
    void setRpm(Encoder encoder);
    void setMilhar();
    void setCentena();
    void setDezena();
    void setUnidade();

    int getRpm();
    int getMilhar();
    int getCentena();
    int getDezena();
    int getUnidade();
    String stringifyRpm();

    private:
        int rpm;
        int milhar;
        int centena;
        int dezena;
        int unidade;
};

#endif