#ifndef LED_PATTERN_LIB_H
#define LED_PATTERN_LIB_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LEDPatternLib {
public:
  LEDPatternLib(uint8_t pin, uint16_t numPixels);
  LEDPatternLib(uint8_t pin);

  void begin();
  void setBrightness(uint8_t brightness);

  void blink(uint32_t color = 0xFFFFFF, uint16_t delay_ms = 300);
  void rainbowCycle(uint8_t wait = 20);
  void knightRider(uint32_t color = 0xFF0000, uint8_t speed = 50);

private:
  uint8_t _pin;
  uint8_t _brightness;
  bool _isNeoPixel;

  Adafruit_NeoPixel* _strip = nullptr;
  uint16_t _numPixels = 0;
};

#endif
