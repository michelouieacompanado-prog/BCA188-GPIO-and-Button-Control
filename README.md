# Laboratory Activity 3: GPIO and Button Control

## Overview
This repository contains the solution for **Laboratory Activity 3: GPIO and Button Control**. The project demonstrates digital input and output operation using a microcontroller. A tactile push button controls two status LEDs in an inverted configuration using an internal pull-up resistor (`INPUT_PULLUP`) and conditional `if/else` logic.

## Project Features
- **Pull-Up Resistor Configuration:** Pin 23 uses `INPUT_PULLUP` to maintain a stable `HIGH` state when the button is released.
- **Inverted LED Logic:** LED 1 is `HIGH` (ON) when released and `LOW` (OFF) when pressed. LED 2 displays the exact opposite state.
- **`if/else` Control:** Replaces conditional ternary expressions with explicit control logic.

## Hardware Components
- 1x Microcontroller Board (e.g., ESP32)
- 1x Tactile Push Button
- 2x LEDs
- 2x 100Ω Resistors (Current limiting)
- Breadboard and Jumper Wires

## Pin Wiring Connections

| Component | Component Pin | Microcontroller / Breadboard Connection |
| :--- | :--- | :--- |
| **Push Button** | Terminal 1 | **GPIO 23** |
| **Push Button** | Terminal 2 | **GND** |
| **LED 1** | Anode (+ long leg) | **GPIO 18** (via 100Ω Resistor) |
| **LED 1** | Cathode (- short leg) | **GND** |
| **LED 2** | Anode (+ long leg) | **GPIO 19** (via 100Ω Resistor) |
| **LED 2** | Cathode (- short leg) | **GND** |

## Source Code

```cpp
#include <Arduino.h>

const uint8_t BUTTON_PIN = 23;
const uint8_t LED1_PIN = 18;
const uint8_t LED2_PIN = 19;

void setup() {
  // Enables internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Set initial outputs matching "released" state
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  // Inverted logic with if/else structure
  if (buttonState == LOW) {
    // Button PRESSED
    digitalWrite(LED1_PIN, LOW);   // LED 1 turns OFF
    digitalWrite(LED2_PIN, HIGH);  // LED 2 turns ON
  } else {
    // Button RELEASED
    digitalWrite(LED1_PIN, HIGH);  // LED 1 turns ON
    digitalWrite(LED2_PIN, LOW);   // LED 2 turns OFF
  }
}
```

## Observation Summary

| Button State | Input Pin Logic | LED 1 (Pin 18) | LED 2 (Pin 19) |
| :--- | :--- | :--- | :--- |
| **Released** | HIGH | **ON** | OFF |
| **Pressed** | LOW | OFF | **ON** |

## Setup & Running Instructions
1. Wire the breadboard circuit according to the connection table.
2. Connect the microcontroller to your PC via USB.
3. Open the code in Arduino IDE or PlatformIO.
4. Select the target board and upload the sketch.
5. Verify initial LED state upon board reset and test the button press.
