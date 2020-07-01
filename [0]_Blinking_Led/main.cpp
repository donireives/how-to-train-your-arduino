#include <Arduino.h>
#define onboard 13

void setup() {
  pinMode(onboard, OUTPUT);
}

void loop() {
  digitalWrite(onboard, HIGH);
  delay(500);
  digitalWrite(onboard, LOW);
  delay(500);
}