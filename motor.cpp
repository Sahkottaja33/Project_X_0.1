#include <Arduino.h>
#include "motor.h"

void motorInit() {
  // FEEDER
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  // BAT
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);


  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
  
  feederStop();
  batStop();
}

//FEEDER

void feederStop() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
}

void feederForward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, FEEDER_SPEED);
}

void feederBackward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, FEEDER_SPEED);
}

void feedBall() {
  feederForward();
  delay(FEED_TIME);       // säätövara
  feederStop();
}

void batStop() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
}

void loadSpring() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, MOTOR_SPEED);

  delay(LOAD_TIME); // kuinka kauan jousen viritykseen kuluu
  batStop();
}

void returnMotor() {
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, MOTOR_SPEED);

  delay(RETURN_TIME); // palautuminen
  batStop();
}
