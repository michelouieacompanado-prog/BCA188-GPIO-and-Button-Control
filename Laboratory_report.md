# Laboratory Report

**Title:** Laboratory Activity 3: GPIO and Button Control  
**Date:** September 29, 2026  
**Name:** Miche Louie B. Acompañado  
**Course/Section:** BCA188 - B186  

---

## 1. Objective

- To assemble a tactile push button and dual-LED status circuit.
- To configure microcontroller GPIO pins for digital input using `INPUT_PULLUP` and digital output.
- To rewrite conditional ternary expressions into an `if/else` control structure.
- To implement inverted output logic where two LEDs display strictly opposite states depending on physical button interaction.

---

## 2. Materials and Components

- 1x Microcontroller Board (e.g., ESP32)
- 1x Tactile Push Button
- 2x LEDs (Status Indicators)
- 2x 100Ω Resistors
- 1x Solderless Breadboard
- Male-to-Male Jumper Wires

---

## 3. Procedure

1. **Circuit Assembly:** 
   - Connected one terminal of the push button to GPIO 23 and the opposite terminal to GND.
   - Connected LED 1 Anode to GPIO 18 through a 100Ω resistor and the Cathode to GND.
   - Connected LED 2 Anode to GPIO 19 through a 100Ω resistor and the Cathode to GND.

2. **Program Implementation:** 
   - Wrote C++ code utilizing `pinMode(BUTTON_PIN, INPUT_PULLUP)` for input stabilization.
   - Replaced ternary operators with an `if/else` structure to control output states based on `digitalRead(BUTTON_PIN)`.

3. **Testing & Verification:** 
   - Applied power via USB and reset the board to confirm initial output states.
   - Verified that LED 1 lights up when the button is released, and LED 2 lights up when the button is pressed.
   - Confirmed input stability to ensure no floating signal occurred when the button was untouched.

---

## 4. Source Code

```cpp
#include <Arduino.h>

const uint8_t BUTTON_PIN = 23;
const uint8_t LED1_PIN = 18;
const uint8_t LED2_PIN = 19; 

void setup() {
  // Configures pin with internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Initial states upon startup / reset
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  // Active-LOW conditional evaluation
  if (buttonState == LOW) {
    // Button is PRESSED
    digitalWrite(LED1_PIN, LOW);   
    digitalWrite(LED2_PIN, HIGH);  
  } else {
    // Button is RELEASED
    digitalWrite(LED1_PIN, HIGH);  
    digitalWrite(LED2_PIN, LOW);   
  }
}
```

---

## 5. Circuit Photos and Diagram

* **Figure 1: Initial Released State (LED 1 ON, LED 2 OFF)**  
  *<img width="2048" height="1536" alt="Image" src="https://github.com/user-attachments/assets/3bbe1712-b0e5-4e2b-9b81-bb0750b92026" />*

* **Figure 2: Active Pressed State (LED 1 OFF, LED 2 ON)**  
  *<img width="2048" height="1536" alt="Image" src="https://github.com/user-attachments/assets/75a57bb7-d8e7-4fc0-8bb0-0b6dd90ec7a1" />*

* **Demonstration Video:**  
  *<video src="https://github.com/user-attachments/assets/0eb5e5fe-75af-48ea-86a7-757b7f97dc9d" controls width="50%"></video>*

---

## 6. Observations & Analysis

### Pressed / Released Observation Table

| Physical Button Action | GPIO 23 Logic State | LED 1 (Pin 18) | LED 2 (Pin 19) |
| :--- | :--- | :--- | :--- |
| **Released** (Initial) | HIGH | **ON** | OFF |
| **Pressed** | LOW | OFF | **ON** |

### Logic Explanation (Meaning of HIGH and LOW)

When a button pin is defined using `INPUT_PULLUP`, an internal resistor connects GPIO 23 to the microcontroller's positive voltage rail ($V_{DD}$).

- **HIGH (Logic 1):** When the button is **released**, the circuit path to ground is open. The internal resistor pulls the GPIO voltage up to $V_{DD}$, causing `digitalRead()` to read **HIGH**. This prevents the pin from "floating" (reading random environmental electrical noise).
- **LOW (Logic 0):** When the button is **pressed**, the switch closes, creating a direct connection between GPIO 23 and Ground ($0\text{V}$). Ground overpowers the internal resistor, pulling the voltage down and causing `digitalRead()` to read **LOW**.

---

## 7. Conclusion

The laboratory activity was successfully completed. The circuit and software operated as expected upon board reset: LED 1 illuminated by default when released, and LED 2 illuminated when the button was depressed. Using `INPUT_PULLUP` guaranteed reliable signal transitions without floating values, and the `if/else` logic accurately controlled the complementary output states of both LEDs.
