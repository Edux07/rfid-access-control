#ifndef RFID_READER_H
#define RFID_READER_H

#include <Arduino.h>
#include <MFRC522.h>

class RFIDReader {
public:
    RFIDReader(byte ssPin, byte rstPin);

    void begin();
    bool isCardAvailable();
    String readUID();
    byte getVersion();

private:
    MFRC522 mfrc522;
};

#endif