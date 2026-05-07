/** PÄÄOHJELMA
  * Tämä tiedosto hoitaa Bluetooth-yhteyden, komentojen vastaanoton
  * ja laitteen toimintalogiikan.
  */

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "motor.h" 
#include "solenoid.h"
#include "fan.h"
#include "sensor.h"

// Bluetooth-komennot
#define CMD_ON     0x01 // Moottorin palautus
#define CMD_OFF    0x02 // Pallon lataus
#define CMD_LEFT   0x03 // Latausmoottori eteenpäin
#define CMD_RIGHT  0x04 // Latausmoottori taaksepäin
#define CMD_FIRE   0x05 // Tuuletin + solenoidi
#define CMD_LOAD   0x06 // Jousen(mailan) viritys

BLEServer* server;
BLECharacteristic* commandChar;

// BLE-palvelimen tilan seuranta (yhteys ____)
class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    Serial.println("iPhone connected!");
  }
  void onDisconnect(BLEServer* pServer) {
    Serial.println("iPhone disconnected!");
    BLEDevice::startAdvertising();
  }
};

// Bluetooth-komentojen käsittely
class CommandCallback : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *characteristic) {
    std::string value = characteristic->getValue();
    if (value.length() == 0) return;

    uint8_t cmd = value[0]; // Ensimmäinen tavu komennoksi

    switch (cmd) {

      case CMD_ON:
        Serial.println("CMD: ON");
        returnMotor();
        break;

      case CMD_OFF:
        Serial.println("CMD: OFF");
        feedBall();
        break;

      case CMD_LEFT:
        feederForward();
        delay(500);
        feederStop();
        Serial.println("CMD: LEFT");
        break;

      case CMD_RIGHT:
        feederBackward();
        delay(500);
        feederStop();
        Serial.println("CMD: RIGHT");
        break;

      case CMD_FIRE:
        Serial.println("CMD: Fire");
        pulseFan(10000);
        setSolenoid(true);   // päälle
        delay(200);
        setSolenoid(false);  // pois
        break;

      case CMD_LOAD:
        Serial.println("CMD: LOAD");
        loadSpring();
        break;

      default:
        Serial.print("CMD: Unknown (");
        Serial.print(cmd);
        Serial.println(")");
        break;
    } // <-- tämä sulkee switchin oikein

  } // <-- tämä sulkee onWrite-funktion

}; // <-- tämä sulkee classin


void setup() {
  delay(300);
  Serial.begin(115200);
  Serial.println("BLE starting...");

  // Alijärjestelmien alustus
  fanInit();
  motorInit();
  solenoidInit();

  // Bluetooth-asetukset
  BLEDevice::init("ESP32-S3 Controller");
  delay(200);

  server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  BLEService *service = server->createService("00001234-0000-1000-8000-00805f9b34fb");

  commandChar = service->createCharacteristic(
    "0000abcd-0000-1000-8000-00805f9b34fb",
    BLECharacteristic::PROPERTY_WRITE
  );
  commandChar->setCallbacks(new CommandCallback());

  service->start();

  BLEAdvertising *adv = BLEDevice::getAdvertising();
  adv->setScanResponse(true);

  BLEDevice::startAdvertising();

  Serial.println("BLE ready. Waiting for iPhone...");
}

void loop() {
  if (sensor_ballDetected()){
    delay(50);          // säätövara lyöntihetkeen

    setSolenoid(true);  // vapautetaan jousi
    delay(150);
    setSolenoid(false); // estetään solenoidin kuumeneminen

    delay(500);
    // <-- mailan viritysfunktio tähän

    delay(3000);         // riippuu kuinka kauan mailan virityksessä kestää
  }
  delay(50);
}
