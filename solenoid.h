#ifndef SOLENOID_H
#define SOLENOID_H

#include <Arduino.h>

#define SOL_PIN 17

void solenoidInit();
void setSolenoid(bool state);

#endif
