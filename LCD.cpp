#include "LCD.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "RpmInformation.h"

LCD::LCD(int rs, int enable, int D4, int D5, int D6, int D7): lcd(rs, enable, D4, D5, D6, D7) {
  lcd.begin(16, 2);
}

void LCD::escrever(RpmInformation rpmInformation) {

  lcd.clear();

  String primeiraLinha = "ROTACAO:" + rpmInformation.stringifyRpm() + " RPM";
  lcd.setCursor(0, 0);
  lcd.print(primeiraLinha);
  
  lcd.setCursor(2, 1);
  lcd.print("(ESTIMATIVA)");
}


