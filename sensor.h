#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

#define SENSOR_TRESHOLD 500 // esim, voi olla muutakin

void sensor_init(int pin);
bool sensor_ballDetected();

#endif
