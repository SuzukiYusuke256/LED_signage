//
#include "data.h"

// int ledNum = 13;
int interval = 250;

void setup(){
    pinMode(ledNum, OUTPUT);
}

void loop(){
    delay(interval);
    digitalWrite(pinNum[0],HIGH);
    delay(interval);
    digitalWrite(ledNum[0],LOW);
}