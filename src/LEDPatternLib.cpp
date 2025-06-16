#include "LEDPatternLib.h"

LEDPatternLib::LEDPatternLib(uint8_t pin, uint16_t numPixels)
    : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _numPixels(numPixels) {}

void LEDPatternLib::begin() {
    _strip.begin();
    _strip.show();
    _strip.setBrightness(255);
}

void LEDPatternLib::setBrightness(uint8_t brightness) {
    _strip.setBrightness(brightness);
    _strip.show();
}

void LEDPatternLib::blink(uint32_t color, uint16_t delay_ms) {
    _strip.fill(color, 0, _numPixels);
    _strip.show();
    delay(delay_ms);
    _strip.clear();
    _strip.show();
    delay(delay_ms);
}

void LEDPatternLib::rainbowCycle(uint8_t wait) {
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
        for (int i = 0; i < _strip.numPixels(); i++) {
            int pixelHue = firstPixelHue + (i * 65536L / _strip.numPixels());
            _strip.setPixelColor(i, _strip.gamma32(_strip.ColorHSV(pixelHue)));
        }
        _strip.show();
        delay(wait);
    }
}

void LEDPatternLib::knightRider(uint32_t color, uint8_t speed) {
    for (int i = 0; i < _numPixels; i++) {
        _strip.clear();
        _strip.setPixelColor(i, color);
        _strip.show();
        delay(speed);
    }
    for (int i = _numPixels - 2; i > 0; i--) {
        _strip.clear();
        _strip.setPixelColor(i, color);
        _strip.show();
        delay(speed);
    }
}
