#include <Wire.h>
#include "RpmInformation.h"
#include "I2C.h"
#include "LCD.h"
#include "Motor.h"
#include "Encoder.h"
#include "Bluetooth.h"
#include "Processador.h"

#include <LiquidCrystal.h>
#define PCF8574_ADDRESS 0x20  // Altere conforme necessário
#define disp3 112
#define disp2 176
#define disp1 208
#define disp0 224

volatile unsigned int cont = 0;

I2C i2c(PCF8574_ADDRESS, 32, disp3, disp2, disp1, disp0);
LCD lcd(12, 11, 10, 9, 8, 7);
RpmInformation rpmInfo(0);
Motor motor(5, 6, 3);
Encoder encoder(2);
Bluetooth bt(0, 1);
Processador processador(100);

void setup() {

  Wire.begin();
  cli();  // Desabilita interrupcoes globais
  TCCR0A = 0x02;
  OCR0A = 124;
  TIMSK0 = 0x02;
  TCCR0B = 0x03;
  encoder.configuraInterrupcoes();
  sei();  // Habilita interrupcoes globais
  i2c.escreverDisplay(rpmInfo);
  lcd.escrever(rpmInfo);
}

void loop() {
  i2c.escreverDisplay(rpmInfo);
  processador.processarComando(bt.read(), motor, rpmInfo);
}

ISR(TIMER0_COMPA_vect) {
  
  cont++;

  encoder.incrementaTimer();
  
  if (cont >= 2000) {
    cont = 0;
  }

  if (encoder.getTimer() >= encoder.getAmostragem()) {
    // Calcula o rpm
    rpmInfo.setRpm(encoder);
    lcd.escrever(rpmInfo);
    encoder.setContador(0);
    encoder.resetaTimer();
  }
}

ISR(INT0_vect) {
  encoder.incrementaContador();
}
