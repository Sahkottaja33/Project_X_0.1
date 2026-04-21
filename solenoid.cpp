#include "solenoid.h"

void solenoidInit() {
    pinMode(SOL_PIN, OUTPUT);
    digitalWrite(SOL_PIN, LOW);  // solenoidi pois päältä alussa
}

void setSolenoid(bool state) {
    digitalWrite(SOL_PIN, state ? HIGH : LOW);
}
