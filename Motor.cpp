#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int pinA, int pinY, int pinPWM) {
  
  pinMode(pinA, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinPWM, OUTPUT);
  this->pinA = pinA;
  this->pinY = pinY;
  this->pinPWM = pinPWM;
  digitalWrite(pinA, LOW);
  digitalWrite(pinY, LOW);
};


void Motor::girar(int velocidade) {

  digitalWrite(pinA, HIGH);
  digitalWrite(pinY, LOW);
  analogWrite(pinPWM, velocidade);
};

void Motor::ventilador() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinY, LOW);
}

void Motor::exaustor() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinY, HIGH);
}

void Motor::parar() {
  digitalWrite(pinA, 0);
  digitalWrite(pinY, 0);
};

