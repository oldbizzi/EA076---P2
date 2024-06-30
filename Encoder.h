#ifndef ENCODER_H
#define ENCODER_H

class Encoder {
    
    public:
        Encoder(int pino);
        void setContador(int temp);
        int getContador();
        void incrementaContador();
        void configuraInterrupcoes();
        int getAmostragem();
        int getTimer();
        void resetaTimer();
        void incrementaTimer();
    private:
        int pino;
        int contadorInterrupcao;
        int amostragem;
        int timer;
};

#endif