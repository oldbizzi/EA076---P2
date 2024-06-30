#include <Arduino.h>
#include "Motor.h"
#include "RpmInformation.h"
#ifndef PROCESSADOR_H
#define PROCESSADOR_H

class Processador {
    public:
        Processador(int dummy);
        String processarComando(String comando, Motor motor, RpmInformation rpm);
};

#endif