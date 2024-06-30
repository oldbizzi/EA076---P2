#ifndef RPMINFORMATION_H
#define RPMINFORMATION_H
#include <Arduino.h>
#include "Encoder.h"
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