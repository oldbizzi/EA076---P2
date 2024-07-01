#ifndef MOTOR_H
#define MOTOR_H

/**
 * Classe responsável pela manipulação do motor pela ponte H
 * Atributos:
 * pinA e pinY: pinos conectados à ponte H, responsáveis pelo acionamento do motor
 * pinPWM: pino conectado ao enable da ponte H, utilizando para gerar um sinal de PWM alterando a velocidade de giro do motor
 */
class Motor {

    public:
        Motor(int pinA, int pinB, int pinPWM);
        void girar(int velocidade);
        void parar();
        void ventilador();
        void exaustor();
    private: 
        int pinA;
        int pinY;
        int pinPWM;
};

#endif

