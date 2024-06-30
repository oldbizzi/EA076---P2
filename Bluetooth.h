#include<SoftwareSerial.h>
#ifndef BLUETOOTH_H
#define BLUETOOTH_H

class Bluetooth {

    public: 
        Bluetooth(int rx, int tx);
        String read();
    private:
      SoftwareSerial bt;
};

#endif