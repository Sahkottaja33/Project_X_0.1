#include "sensor.h"

void sensor_init(){
	pinMode(SENSOR_PIN, INPUT);
}

bool sensor_ballDetected(){
	return analogRead(SENSOR_PIN) < SENSOR_TRESHOLD; // palauttaa true, jos paluuarvo alittaa kynnyksen
}

int sensor_getRawValue(){
	return analogRead(SENSOR_PIN); // mahdollinen debuggaus serial monitorilla, kynnyksen tarkastus
}
