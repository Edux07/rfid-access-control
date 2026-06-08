#include <Arduino.h>
#include <Servo.h>
#include "RFIDReader.h"

#define SS_PIN 53
#define RST_PIN 7

int servoPin = 8;
Servo miservo;

RFIDReader rfid(SS_PIN, RST_PIN);

void servoAttach(Servo &servo);
void moveServo(Servo &servo, int degrees);
void servoSequence(Servo &servo);

void setup() {
  Serial.begin(9600);

  servoAttach(miservo);
  servoSequence(miservo);

  rfid.begin();

  Serial.println("Iniciando lector RFID...");

  byte version = rfid.getVersion();

  Serial.print("Version RC522: 0x");
  Serial.println(version, HEX);

  if (version == 0x00 || version == 0xFF) {
    Serial.println("ERROR: No se detecta el RC522. Revisa cableado.");
  } else {
    Serial.println("RC522 detectado correctamente.");
  }

  Serial.println("RFID listo. Acerca una tarjeta...");
}

void loop() {
  if (rfid.isCardAvailable()) {
    String uid = rfid.readUID();

    Serial.print("UID detectado: ");
    Serial.println(uid);
  }
}

void servoAttach(Servo &servo) {
  servo.attach(servoPin);
}

void moveServo(Servo &servo, int degrees) {
  servo.write(degrees);
}

void servoSequence(Servo &servo){
  moveServo(miservo, 90);
  delay(2000);
  
  moveServo(miservo, 0);
  delay(2000);

  moveServo(miservo, 90);
  delay(2000);
}