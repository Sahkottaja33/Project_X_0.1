#ifndef MOTOR_H
#define MOTOR_H

#define PWMA 5
#define PWMB 4
#define AIN1 6
#define AIN2 7
#define BIN1 15
#define BIN2 16
#define STBY 10
#define FEED_TIME 500
#define FEEDER_SPEED 200
#define LOAD_TIME 2500
#define RETURN_TIME 2500
#define MOTOR_SPEED 255


void motorInit();

// FEEDER
void feederStop();
void feederForward();  // entinen left
void feederBackward(); // entinen right
void feedBall();

// BAT
void batStop();
void loadSpring();
void returnMotor();

#endif
