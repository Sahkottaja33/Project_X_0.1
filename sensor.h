#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

#define SENSOR_TRESHOLD 500 // esim, voi olla muutakin
#define SENSOR_PIN 1     // kytkentä?

void sensor_init();
bool sensor_ballDetected();

#endif
