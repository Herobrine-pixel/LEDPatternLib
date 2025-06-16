#include <LEDPatternLib.h>

// Use this for a NeoPixel strip
// LEDPatternLib led(6, 8);  // Pin 6, 8 NeoPixel LEDs

// Use this for a simple built-in LED
LEDPatternLib led(13);

void setup() {
  led.begin();
  led.setBrightness(150);
}

void loop() {
  // For NeoPixel:
  // led.rainbowCycle(10);
  // led.knightRider(0xFF0000, 70);
  
  // For built-in LED:
  led.blink(0xFFFFFF, 500);
}
