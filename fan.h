#ifndef FAN_H
#define FAN_H
#include <Arduino.h>

#define FAN_PIN 18 // kytkentä?

void fanInit();
void setFan(bool state);
void pulseFan(int duration); // funktio pallon laukaisuun

#endif
