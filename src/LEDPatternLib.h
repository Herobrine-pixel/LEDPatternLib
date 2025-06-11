#ifndef LED_PATTERN_LIB_H
#define LED_PATTERN_LIB_H

#include <Arduino.h>

class LEDPatternLib {
  public:
    LEDPatternLib(uint8_t pin);
    void begin();
    void setBrightness(uint8_t brightness);
    void blink(uint16_t delay_ms = 500);
    void rainbowCycle();
    void knightRider();

  private:
    uint8_t _pin;
    uint8_t _brightness;
    void _setColor(uint8_t r, uint8_t g, uint8_t b);
};

#endif
