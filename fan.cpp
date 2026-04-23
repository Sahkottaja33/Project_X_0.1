#include "fan.h"

void fanInit(){
    pinMode(FAN_PIN, OUTPUT);
    digitalWrite(FAN_PIN, LOW);  // tuuletin aluksi pois päältä
}

void setFan(bool state){
    digitalWrite(FAN_PIN, state ? HIGH : LOW);
}

void pulseFan(int duration){
    digitalWrite(FAN_PIN, HIGH); // tuuletin päälle
    delay(duration);             // kesto
    digitalWrite(FAN_PIN, LOW);  // tuuletin pois päältä
}
