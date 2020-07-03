#include <Arduino.h>

const int pinS1 = 7;
const int pinLED = 8;
int sw = 0;

void setup() 
{ 
  pinMode(pinLED, OUTPUT);  
  pinMode(pinS1, INPUT);  
  digitalWrite(pinS1, HIGH);
  digitalWrite(pinLED, LOW);
}

void loop()
{
  if(digitalRead(pinS1)==0 && sw==0){
    digitalWrite(pinLED, HIGH); 
    sw=1; 
  }
  else if(digitalRead(pinS1)==0 && sw==1){ 
    digitalWrite(pinLED, LOW); 
    sw=0; 
  }
  delay(200);
}