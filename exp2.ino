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

// Contador para temporização
volatile unsigned int cont = 0;

// Classes para cada módulo do circuito
I2C i2c(PCF8574_ADDRESS, 32, disp3, disp2, disp1, disp0);
LCD lcd(12, 11, 10, 9, 8, 7);
RpmInformation rpmInfo(0);
Motor motor(5, 6, 3);
Encoder encoder(2);
Bluetooth bt(4, 13);
Processador processador(100);

void setup() {

  Wire.begin();

  // Configuração das interrupções
  cli();  
  TCCR0A = 0x02;
  OCR0A = 124;
  TIMSK0 = 0x02;
  TCCR0B = 0x03;
  encoder.configuraInterrupcoes();
  sei();  // Habilita interrupcoes globais

  // Escreve os valores iniciais nos displays
  i2c.escreverDisplay(rpmInfo);
  lcd.escrever(rpmInfo);
}

void loop() {
  // Escrita constante nos displays de 7 segmentos com o protocolo I2C
  i2c.escreverDisplay(rpmInfo);

  // Leitura do bluetooth e execução dos comandos enviados
  bt.read(processador, rpmInfo, motor);
}


// Método de interrupções
ISR(TIMER0_COMPA_vect) {

  // Acrescenta o contador
  cont++;

  // Incrementa o timer da leitura do encoder
  encoder.incrementaTimer();

  if (cont >= 2000) {
    cont = 0;
  }

  // Se o período de amostragem tiver passado...
  if (encoder.getTimer() >= encoder.getAmostragem()) {
    // Faz a leitura da velocidade e salva
    rpmInfo.setRpm(encoder);
    
    // Atualiza a velocidade no lcd
    lcd.escrever(rpmInfo);
    
    // Reseta o contador de pulsos do encoder e seu timer
    encoder.setContador(0);
    encoder.resetaTimer();
  }
}

// Método para interrupções do encoder, apenas incrementando o contador de pulsos
ISR(INT0_vect) {
  encoder.incrementaContador();
}
