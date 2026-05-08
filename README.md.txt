# Project_X_0.2 — ESP32‑S3 Pingpong machine

This project implements a control system for an ESP32‑S3 board that drives a DC motor, a solenoid launcher, a fan, and optional sensors.  
A custom **Web Bluetooth gamepad UI** provides wireless control directly from a browser on mobile or desktop.
---

## Hardware

- ESP32‑S3-Wroom Board
- TB6612FNG dual motor driver
- 2 DC geared motors (left/right movement)
- Small Solenoid (launch release mechanism)
- 2 TIP120 or MOSFET 
- Flyback diodes for inductive loads
- Micro-USB cable
- Resistors of varying sizes
- 9v batteries
- Breadboard and wires
- 

---
## Project structure
Project_X_0.2/
│
├── Project_X_0.1.ino        # Main firmware for ESP32-S3
│
├── motor.cpp                # Motor control logic (TB6612FNG)
├── motor.h                  # Motor control definitions
│
├── solenoid.cpp             # Solenoid driver logic
├── solenoid.h               # Solenoid definitions
│
├── fan.cpp                  # Fan control (PWM or digital)
├── fan.h                    # Fan control definitions
│
├── sensor.cpp               # Ball detection / sensor logic
├── sensor.h                 # Sensor definitions
│
├── index.html               #Web Bluetooth gamepad controller UI
├── manifest.json            # PWA manifest
├── service-worker.js        # PWA service worker
│
└── README.md                # Project documentation

---

## Web Bluetooth Gamepad UI (index.html)

The controller UI is implemented entirely in **index.html**.  
It includes:

- D‑pad (left/right)
- PlayStation‑style action buttons
- Start button
- BLE Connect button
- Keyboard bindings for desktop use
- PWA support (installable on mobile/desktop) (doestn't work on ios)

### Launching the UI

Web Bluetooth requires a special Chrome instance. The normal Chrome browser
(or PWA window) will not allow BLE access.

1. Open the project folder in VS Code  
2. Open `index.html`  
3. Right‑click → **Open with Live Server**  
4. Start an unrestricted Chrome instance with Web Bluetooth enabled. Powershell command chrome.exe --enable-experimental-web-platform-features
(This must be launched manually — BLE will not work in standard Chrome.)
5. Open the Live Server URL in this Chrome window  
6. Press **Connect** and select your ESP32‑S3 device


## BLE UUIDs

The ESP32 and the web UI communicate using the following UUIDs:

- **Service UUID:** `00001234-0000-1000-8000-00805f9b34fb`
- **Characteristic UUID:** `0000abcd-0000-1000-8000-00805f9b34fb`

These must match between the firmware and the HTML UI.

---

##  Building & Flashing

1. Open `Project_X_0.1.ino` in Arduino IDE  
2. Select the correct board settings:
   - **Board:** ESP32‑S3 Dev Module  
   - **USB CDC On Boot:** Enabled  
3. Connect the board via Micro-usb  
4. Upload the firmware

---

##  Usage

- **Connect** — establishes BLE connection  
- **D‑Pad** — motor direction control  
- **PS Buttons** — mapped to custom commands (load, fire, stop, etc.)  
- **START** — triggers the main action (motor or solenoid depending on configuration)  
  
---

##  Notes

- The solenoid driver requires a proper flyback diode and a pulldown resistor on the transistor gate/base.  
- All grounds (ESP32, motor driver, solenoid supply) must be shared.  

