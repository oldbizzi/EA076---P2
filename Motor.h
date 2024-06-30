#ifndef MOTOR_H
#define MOTOR_H

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

