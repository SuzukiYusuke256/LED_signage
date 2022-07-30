// 
int ledNum = 13;
int interval = 500;

void setup(){
    pinMode(ledNum, OUTPUT);
}

void loop(){
    delay(interval);
    digitalWrite(ledNum,HIGH);
    delay(interval);
    digitalWrite(ledNum,LOW);
}