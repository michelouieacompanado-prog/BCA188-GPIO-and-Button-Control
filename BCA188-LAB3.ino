#include <Arduino.h>

const uint8_t BUTTON_PIN = 23;
const uint8_t LED1_PIN = 18;
const uint8_t LED2_PIN = 19; // Added second LED pin

void setup() {
  // Enables the internal pull-up resistor to prevent floating inputs
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Set expected initial outputs matching a "released" button state
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  // Rewritten as if/else structure and inverted logic
  if (buttonState == LOW) {
    // Button is PRESSED
    digitalWrite(LED1_PIN, LOW);   // LED 1 turns OFF
    digitalWrite(LED2_PIN, HIGH);  // LED 2 turns ON (opposite state)
  } else {
    // Button is RELEASED
    digitalWrite(LED1_PIN, HIGH);  // LED 1 turns ON
    digitalWrite(LED2_PIN, LOW);   // LED 2 turns OFF (opposite state)
  }
}
