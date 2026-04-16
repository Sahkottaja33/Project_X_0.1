#ifndef MOTOR_H
#define MOTOR_H

#define PWMA 5
#define PWMB 4
#define AIN1 6
#define AIN2 7
#define BIN1 15
#define BIN2 16
#define STBY 10


void motorInit();

//Motor 1 (Left, right)
void motorStop();
void motorLeft();
void motorRight();
void motorStepLeft();
void motorStepRight();

//Motor 2 (bat)
void motorStop2();
void motorLeft2();
void motorRight2();
void motorStepLeft2();
void motorStepRight2();
#endif
