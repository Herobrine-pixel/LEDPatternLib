#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <LEDPatternLib.h>

// Define LED pin and number of pixels
#define LED_PIN    6       // GPIO6
#define NUM_PIXELS 8       // Number of NeoPixels

// Create the pattern controller
LEDPatternLib pattern(LED_PIN, NUM_PIXELS);

void setup() {
  pattern.begin();
  pattern.setBrightness(100);  // Optional: Set LED brightness (0-255)
}

void loop() {
  pattern.blink(0x0000FF, 300);           // Blue blink
  pattern.knightRider(0xFF0000, 70);      // Red Knight Rider effect
  pattern.rainbowCycle(10);               // Full rainbow animation
}
