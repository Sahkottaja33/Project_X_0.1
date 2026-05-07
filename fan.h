#ifndef FAN_H
#define FAN_H
#include <Arduino.h>

#define FAN_PIN 21 // 18

void fanInit();
void setFan(bool state);
void pulseFan(int duration); // funktio pallon laukaisuun
 
#endif
