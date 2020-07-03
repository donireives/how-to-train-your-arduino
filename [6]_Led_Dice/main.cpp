#include <Arduino.h>

/* 
this not my own, you can find this project on https://create.arduino.cc/projecthub/EvdS/led-dice-885cf1

 Arduino Dice :)
 This example shows how to simulate throwing a dice with 6 LEDs.
 The circuit:
 * 6 LEDs attached to consecutive digital pins (with 220 Ohm resistors)
 * Button switch connected to digital pin (see circuit on https://www.arduino.cc/en/Tutorial/Button)
 Created 5 Jan 2017
 By Esther van der Stappen
 This example code is in the public domain.
 */

#define DEBUG 0

int button = 12;
int pressed = 0;

int first = 2;
int second = 3;
int third = 4;
int fourth = 5;
int fifth = 6;
int sixth = 7;

void setup() {
  for (int i=first; i<=sixth; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(button, INPUT);
  randomSeed(analogRead(0));

  #ifdef DEBUG
    Serial.begin(9600);
  #endif
}

void buildUpTension() {
  for (int i=first; i<=sixth; i++) {
    if (i!=first) {
      digitalWrite(i-1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }
  for (int i=sixth; i>=first; i--) {
    if (i!=sixth) {
      digitalWrite(i+1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }
}

void showNumber(int number) {
  digitalWrite(first, HIGH);
  if (number >= 2) {
    digitalWrite(second, HIGH);
  }
  if (number >= 3) {
    digitalWrite(third, HIGH);    
  }
  if (number >= 4) {
    digitalWrite(fourth, HIGH);    
  }
  if (number >= 5) {
    digitalWrite(fifth, HIGH);    
  }
  if (number == 6) {
    digitalWrite(sixth, HIGH);    
  }
}

int throwDice() {
  int randNumber = random(1,7);
  #ifdef DEBUG
    Serial.println(randNumber);
  #endif
  return randNumber;
}

void setAllLEDs(int value) {
  for (int i=first; i<=sixth; i++) {
    digitalWrite(i, value);
  }
}

void loop() {
  pressed = digitalRead(button);
  if (pressed == HIGH) {
    setAllLEDs(LOW);
    buildUpTension();
    int thrownNumber = throwDice();
    showNumber(thrownNumber);
  } 

}