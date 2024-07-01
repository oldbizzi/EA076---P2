#include <Arduino.h>
#include "Encoder.h"

// Construtor
Encoder::Encoder(int temp) {
  this->pino = temp;
}

// Configura as interrupões do encoder para o pino 2 e para borda de subida
void Encoder::configuraInterrupcoes() {
  pinMode(pino, INPUT);
  EIMSK |= (1 << INT0);
  EICRA |= (1 << ISC00) | (1 << ISC01);
  amostragem = 2000;
}

// getters e setters
int Encoder::getContador() {
  return this->contadorInterrupcao;
}

int Encoder::getAmostragem() {
  return this->amostragem;
}

void Encoder::setContador(int temp) {
  this->contadorInterrupcao = temp;
}

void Encoder::incrementaContador() {
  this->contadorInterrupcao = this->contadorInterrupcao + 1;
}

void Encoder::incrementaTimer() {
  this->timer = this->timer + 1;
}

void Encoder::resetaTimer() {
  this->timer = 0;
}

int Encoder::getTimer() {
  return this->timer;
}

