#include "RFIDReader.h"
#include <SPI.h>

RFIDReader::RFIDReader(byte ssPin, byte rstPin)
  : mfrc522(ssPin, rstPin) {
}

void RFIDReader::begin() {
  SPI.begin();
  mfrc522.PCD_Init();
}

bool RFIDReader::isCardAvailable() {
  return mfrc522.PICC_IsNewCardPresent() &&
         mfrc522.PICC_ReadCardSerial();
}

String RFIDReader::readUID() {
  String uid = "";

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      uid += "0";
    }

    uid += String(mfrc522.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  mfrc522.PICC_HaltA();

  return uid;
}
byte RFIDReader::getVersion() {
    return mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
}