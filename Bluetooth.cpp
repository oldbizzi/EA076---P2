#include "Bluetooth.h"
#include <SoftwareSerial.h>
#include <Arduino.h>
Bluetooth::Bluetooth(int rx, int tx): bt(rx, tx){
  
  bt.begin(9600);
  Serial.begin(9600);
}

String Bluetooth::read() {
  //Check received a byte from bluetooth by software serial
  if (Serial.available()) {
    String comando = bt.readStringUntil('\n');
    Serial.print(comando); //Print the byte to hardware serial
    return comando;
  } else {
    return "";
  }
}