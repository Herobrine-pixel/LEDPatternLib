#include "LEDPatternLib.h"

LEDPatternLib::LEDPatternLib(uint8_t pin) : _pin(pin), _brightness(255) {}

void LEDPatternLib::begin() {
  pinMode(_pin, OUTPUT);
}

void LEDPatternLib::setBrightness(uint8_t brightness) {
  _brightness = brightness;
}

void LEDPatternLib::blink(uint16_t delay_ms) {
  digitalWrite(_pin, HIGH);
  delay(delay_ms);
  digitalWrite(_pin, LOW);
  delay(delay_ms);
}

void LEDPatternLib::rainbowCycle() {
  blink(100);
}

void LEDPatternLib::knightRider() {
  blink(50);
}
