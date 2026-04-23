#indef FAN_H
#define FAN_H
#include <Arduino.h>

#define FAN_PIN ...

void fanInit();
void setFan(bool state);
void PulseFan(int duration); // funktio pallon laukaisuun

#endif
