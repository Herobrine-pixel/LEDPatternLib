#ifndef LEDPatternLib_h
#define LEDPatternLib_h

#include <Arduino.h>

class LEDPatternLib {
  public:
    LEDPatternLib(uint8_t pin);
    void begin();
    void blink(unsigned long delay_ms = 500);
    void rainbowCycle(uint8_t wait = 10);
    void knightRider(uint8_t speed = 50);
    void colorWipe(uint32_t color, int delay_ms = 50);

  private:
    uint8_t _pin;
    uint32_t Wheel(byte WheelPos);
    void showColor(uint32_t color);
};

#endif