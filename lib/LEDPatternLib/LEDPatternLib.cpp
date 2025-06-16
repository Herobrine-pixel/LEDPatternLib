#include "LEDPatternLib.h"

LEDPatternLib::LEDPatternLib(uint8_t pin, uint16_t numPixels)
  : _pin(pin), _brightness(255), _numPixels(numPixels), _isNeoPixel(true) {
  _strip = new Adafruit_NeoPixel(numPixels, pin, NEO_GRB + NEO_KHZ800);
}

LEDPatternLib::LEDPatternLib(uint8_t pin)
  : _pin(pin), _brightness(255), _isNeoPixel(false) {
}

void LEDPatternLib::begin() {
  if (_isNeoPixel && _strip) {
    _strip->begin();
    _strip->setBrightness(_brightness);
    _strip->show();
  } else {
    pinMode(_pin, OUTPUT);
  }
}

void LEDPatternLib::setBrightness(uint8_t brightness) {
  _brightness = brightness;
  if (_isNeoPixel && _strip) {
    _strip->setBrightness(brightness);
  }
}

void LEDPatternLib::blink(uint32_t color, uint16_t delay_ms) {
  if (_isNeoPixel && _strip) {
    for (uint16_t i = 0; i < _numPixels; i++) {
      _strip->setPixelColor(i, color);
    }
    _strip->show();
    delay(delay_ms);
    _strip->clear();
    _strip->show();
    delay(delay_ms);
  } else {
    digitalWrite(_pin, HIGH);
    delay(delay_ms);
    digitalWrite(_pin, LOW);
    delay(delay_ms);
  }
}

void LEDPatternLib::rainbowCycle(uint8_t wait) {
  if (!_isNeoPixel || !_strip) return;

  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (uint16_t i = 0; i < _numPixels; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / _numPixels);
      _strip->setPixelColor(i, _strip->gamma32(_strip->ColorHSV(pixelHue)));
    }
    _strip->show();
    delay(wait);
  }
}

void LEDPatternLib::knightRider(uint32_t color, uint8_t speed) {
  if (!_isNeoPixel || !_strip) return;

  for (int i = 0; i < _numPixels; i++) {
    _strip->clear();
    _strip->setPixelColor(i, color);
    _strip->show();
    delay(speed);
  }
  for (int i = _numPixels - 2; i > 0; i--) {
    _strip->clear();
    _strip->setPixelColor(i, color);
    _strip->show();
    delay(speed);
  }
}
