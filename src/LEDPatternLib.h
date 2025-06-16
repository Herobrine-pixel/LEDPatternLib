#ifndef LED_PATTERN_LIB_H
#define LED_PATTERN_LIB_H

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

class LEDPatternLib {
public:
    LEDPatternLib(uint8_t pin, uint16_t numPixels);
    void begin();
    void setBrightness(uint8_t brightness);
    void blink(uint32_t color, uint16_t delay_ms = 500);
    void rainbowCycle(uint8_t wait = 20);
    void knightRider(uint32_t color = 0xFF0000, uint8_t speed = 50);

private:
    Adafruit_NeoPixel _strip;
    uint16_t _numPixels;
};

#endif
