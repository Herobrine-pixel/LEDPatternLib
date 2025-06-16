#include <LEDPatternLib.h>

LEDPatternLib led(6, 8); // NeoPixel on pin 6 with 8 LEDs

void setup() {
  led.begin();
  led.setBrightness(100);
}

void loop() {
  led.blink(0x0000FF, 300);
  led.knightRider(0xFF0000, 70);
  led.rainbowCycle(10);
}
