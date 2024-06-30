#include "RpmInformation.h"
#include "Encoder.h"
#include <Arduino.h>

RpmInformation::RpmInformation(int temp) {
}

// Setters
void RpmInformation::setRpm(Encoder encoder) {
    
    int segundos = 60;
    int interrupcoesPorVolta = 2;

    int voltas = encoder.getContador()/2;
    float tempoEntreAmostragem = float(encoder.getAmostragem() * 2)/float(2000);
    rpm = int(encoder.getContador() * segundos/(tempoEntreAmostragem));
    setMilhar();
    setCentena();
    setDezena();
    setUnidade();
}

void RpmInformation::setMilhar() {
    milhar = rpm / 1000;
}

void RpmInformation::setCentena() {
    centena = (rpm - milhar * 1000) / 100 ;
}

void RpmInformation::setDezena() {
    dezena = (rpm - (milhar * 1000) - (centena * 100) ) / 10 ;
}

void RpmInformation::setUnidade() {
    unidade = (rpm - (milhar * 1000) - (centena * 100) - (dezena * 10));
}

// Getters
int RpmInformation::getRpm() {
   return this->rpm;
}

int RpmInformation::getMilhar() {
   return milhar;
}

int RpmInformation::getCentena() {
   return centena;
}
int RpmInformation::getDezena() {
   return dezena;
}

int RpmInformation::getUnidade() {
   return unidade;
}

String RpmInformation::stringifyRpm() {
  String stringRpm = String(rpm);

  int dif = 4 - stringRpm.length();
  if (dif == 0) {
    return stringRpm;
  } else {
    String zeros;
    for (int i = 0; i < dif; ++i) {
      zeros += "0";
    }
    return zeros + stringRpm;
  }

}