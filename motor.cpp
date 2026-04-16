#include <Arduino.h>
#include "motor.h"

void motorInit() {
  //motor 1
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  //motor2
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);


  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
  
  motorStop();
  motorStop2();
}
//Motor 1

void motorStop() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
}

void motorLeft() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 200);
}

void motorRight() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 200);
}

void motorStepLeft() {
  motorLeft();
  delay(200);
  motorStop();
}

void motorStepRight() {
  motorRight();
  delay(200);
  motorStop();

//Motor 2
}
void motorStop2() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
}

void motorLeft2() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 200);
}

void motorRight2() {
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 200);
}

void motorStepLeft2() {
  motorLeft2();
  delay(500);
  motorStop2();
}

void motorStepRight2() {
  motorRight2();
  delay(500);
  motorStop2();
}