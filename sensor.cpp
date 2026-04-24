#include "sensor.h"

static int _pin

void sensor_init(int pin){
	_pin = pin;              // sisäinen muuttuja
	_pinMode(_pin, INPUT);
}

bool sensor_ballDetected(){
	return analogRead(_pin) < SENSOR_TRESHOLD; // palauttaa true, jos paluuarvo alittaa kynnyksen
}

int sensor_getRawValue(){
	return analogRead(_pin); // mahdollinen debuggaus serial monitorilla
}
