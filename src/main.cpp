#include <Arduino.h>
#include <Servo.h>

int servoPin = 8;
Servo miservo;

void servoAttach(Servo &servo);
void moveServo(Servo &servo, int degrees);
void servoSequence(Servo &servo);

void setup() {
  servoAttach(miservo);
  servoSequence(miservo);

}

void loop() {
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
`}