#ifndef MOTOR_H
#define MOTOR_H

#define PWMA 4 // 5
#define PWMB 5 // 4
#define AIN1 7 // 6
#define AIN2 6 // 7
#define BIN1 15
#define BIN2 16
#define STBY 17 // 10
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

// Menee Project_X tiedostoon :)
//void loop() {
  //if (sensor_ballDetected()){
    //delay(50);          // säätövara lyöntihetkeen

    //setSolenoid(true);  // vapautetaan jousi
    //delay(150);
    //setSolenoid(false); // estetään solenoidin kuumeneminen

    //delay(500);
    //setSolenoid(true);  // aukaistaan solenoidi mailan virittämistä varten
    //delay(200);

    //loadSpring();       // viritetään jousi/maila

    //setSolenoid(false); // lukitaan maila paikalleen
    //delay(200);

    //returnMotor();      // vapautetaan moottori, jotta maila pääsee liikkumaan vapaasti

    //feedBall();         // ladataan uusi pallo
  //}
  //delay(50);
//}

#endif
