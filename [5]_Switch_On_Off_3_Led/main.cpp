#include <Arduino.h>

const int pbuttonPin = 5;
const int pbuttonPin1 = 2;
const int relayPin1 = 10;
const int pbuttonPin2 = 3;
const int relayPin2 = 11;
const int pbuttonPin3 = 4;
const int relayPin3 = 12;

int val = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
bool i=false;
bool j=false;
bool k=false;

void setup() {
  pinMode(pbuttonPin, INPUT_PULLUP);
  pinMode(pbuttonPin1, INPUT_PULLUP);
  pinMode(relayPin1, OUTPUT);
  pinMode(pbuttonPin2, INPUT_PULLUP);
  pinMode(relayPin2, OUTPUT);
  pinMode(pbuttonPin3, INPUT_PULLUP);
  pinMode(relayPin3, OUTPUT);
}

void loop() {
  val = digitalRead(pbuttonPin);
  val1 = digitalRead(pbuttonPin1);
  val2 = digitalRead(pbuttonPin2);
  val3 = digitalRead(pbuttonPin3);

  if(val==LOW){
    i=!i;
    j=i;
    k=i;
    digitalWrite(relayPin1, i);
    digitalWrite(relayPin2, j);
    digitalWrite(relayPin3, k);
    delay(200);
  }

  if(val1==LOW){
    i=!i;
    digitalWrite(relayPin1, i);
    delay(200);
  }

  if(val2==LOW){
    j=!j;
    digitalWrite(relayPin2, j);
    delay(200);
  }

  if(val3==LOW){
    k=!k;
    digitalWrite(relayPin3, k);
    delay(200);
  }
}