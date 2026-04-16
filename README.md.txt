# Project_X_0.1 – ESP32-S3 Motor Controller + BLE Gamepad UI

Tämä projekti sisältää ESP32-S3 -pohjaisen moottoriohjaimen sekä
Web Bluetooth -pohjaisen käyttöliittymän (gamepad.html), jonka avulla
moottoria voidaan ohjata suoraan puhelimesta tai tietokoneesta.

## 🔧 Laitteisto
- ESP32-S3 DevKit
- TB6612FNG moottoriohjain
- DC-moottori
- USB-C kaapeli ohjelmointiin

## 📁 Projektin rakenne

Project_X_0.1/
│
├── Project_X_0.1.ino      # Arduino-pääohjelma
├── motor.cpp              # Moottorin ohjauslogiikka
├── motor.h                # Moottorin määrittelyt
└── gamepad.html           # Web Bluetooth -käyttöliittymä

Koodi

## 🕹️ BLE Gamepad UI

`gamepad.html` on käyttöliittymä, joka toimii selaimessa ja yhdistyy
ESP32-S3:een Web Bluetoothin avulla.

Avaa käyttöliittymä näin:

1. Avaa VS Code
2. File → Open Folder → valitse projektikansio
3. Avaa `gamepad.html`
4. Klikkaa oikealla → **Open with Live Server**
5. Avaa Chrome lipulla:
chrome.exe --enable-experimental-web-platform-features

Koodi
6. Paina **Connect** ja valitse ESP32-S3

## 🔗 BLE UUID:t

Projekti käyttää seuraavia 128-bit UUID:ita:

- Service UUID: `00001234-0000-1000-8000-00805f9b34fb`
- Characteristic UUID: `0000abcd-0000-1000-8000-00805f9b34fb`

Nämä ovat sekä ESP32-koodissa että käyttöliittymässä.

## 🚀 Ohjelman kääntäminen

1. Avaa `Project_X_0.1.ino` Arduino IDE:ssä
2. Valitse:
- Board: **ESP32-S3 Dev Module**
- USB CDC On Boot: **Enabled**
3. Lataa koodi ESP32:lle

## 📡 Käyttö

- Connect → yhdistää BLE:llä
- PS-napit → lähettävät komentoja moottorille
- D-Pad → ohjaa suuntaa
- START → käynnistää moottorin