#ifndef LCD_H
#define LCD_H

#include "RpmInformation.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
class LCD {
    public:
        LCD(int D4, int D5, int D6, int D7, int RS, int E);
        void decodificar(String comando);
        void escrever(RpmInformation rpmInformation);
    private:
        LiquidCrystal lcd;
};

#endif