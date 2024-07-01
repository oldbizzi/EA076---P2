#include <Arduino.h>
#include "Motor.h"
#include "RpmInformation.h"
#ifndef PROCESSADOR_H
#define PROCESSADOR_H

/**
 * Classe responsável pela recepção dos comandos pela classe de bluetooth e chamada das rotinas respectivas à cada comando
 * Atributos:
 * pinA e pinY: pinos conectados à ponte H, responsáveis pelo acionamento do motor
 * pinPWM: pino conectado ao enable da ponte H, utilizando para gerar um sinal de PWM alterando a velocidade de giro do motor
 */
class Processador {
    public:
        Processador(int dummy);
        String processarComando(String comando, Motor motor, RpmInformation rpm);
};

#endif