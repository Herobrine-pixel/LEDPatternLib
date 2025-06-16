#include "LEDPatternLib.h"

LEDPatternLib::LEDPatternLib(uint8_t pin) : _pin(pin) {}

void LEDPatternLib::begin() {
  pinMode(_pin, OUTPUT);
}

void LEDPatternLib::blink(unsigned long delay_ms) {
  digitalWrite(_pin, HIGH);
  delay(delay_ms);
  digitalWrite(_pin, LOW);
  delay(delay_ms);
}

void LEDPatternLib::rainbowCycle(uint8_t wait) {
  for (int j = 0; j < 256; j++) {
    analogWrite(_pin, (sin(j * 3.14 / 128) + 1) * 127);
    delay(wait);
  }
}

void LEDPatternLib::knightRider(uint8_t speed) {
  for (int i = 0; i < 255; i += 5) {
    analogWrite(_pin, i);
    delay(speed);
  }
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(_pin, i);
    delay(speed);
  }
}

void LEDPatternLib::colorWipe(uint32_t color, int delay_ms) {
  digitalWrite(_pin, HIGH);
  delay(delay_ms);
  digitalWrite(_pin, LOW);
  delay(delay_ms);
}

uint32_t LEDPatternLib::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return ((255 - WheelPos * 3) << 16) | (0 << 8) | (WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return (0 << 16) | (WheelPos * 3 << 8) | (255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return (WheelPos * 3 << 16) | (255 - WheelPos * 3 << 8) | 0;
}

void LEDPatternLib::showColor(uint32_t color) {
  digitalWrite(_pin, HIGH);
}