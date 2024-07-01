#ifndef ENCODER_H
#define ENCODER_H

/**
 * Classe responsável pela manipulação das informações do encoder
 * Atributos:
 * pino: pino que ativa as interrupções
 * contadorInterrupcao: contador de pulsos do encoder, a cada interrupção soma-se um ao contador
 * amostragem: tempo entre cada amostragem do encoder para determinar a velocidade
 * timer: contador para temporizar a amostragem 
 */
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