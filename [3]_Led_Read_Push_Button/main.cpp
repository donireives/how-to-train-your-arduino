#include <Arduino.h>

const int buttonPin = 2;
const int ledPin =  13;

int buttonState = 0;
int ledState = LOW;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  ledState = (buttonState == HIGH) ? HIGH : LOW;
  digitalWrite(ledPin, ledState);

  delay(100);
}