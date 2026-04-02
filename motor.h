#ifndef MOTOR_H
#define MOTOR_H

#define PWMA 5
#define AIN1 6
#define AIN2 7
#define STBY 10

void motorInit();
void motorStop();
void motorLeft();
void motorRight();
void motorStepLeft();
void motorStepRight();

#endif
