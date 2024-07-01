#ifndef LCD_H
#define LCD_H

#include "RpmInformation.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

/**
 * Classe responsável pela exbição das informações no lcd
 * Atributos:
 * porta e endereco: endereço de comunicação com o protocolo I2C
 * displays: valor em cada display a ser exibido
 */
class LCD {
    public:
        LCD(int D4, int D5, int D6, int D7, int RS, int E);
        void escrever(RpmInformation rpmInformation);
    private:
        LiquidCrystal lcd;
};

#endif