# LEDPatternLib

**LEDPatternLib** is a versatile and easy-to-use Arduino library for controlling various LED patterns on both built-in and external LEDs, including NeoPixel (WS2812) and DotStar (APA102) strips.

## ✨ Features

- Predefined LED patterns like:
  - Blink
  - Breathing
  - Rainbow Cycle
  - Knight Rider
  - Twinkle
  - Theater Chase
  - Color Wipe
- Supports built-in LED, NeoPixel, and DotStar strips
- Adjustable speed, brightness, and colors
- Uses non-blocking timing (no `delay()`)
- Beginner-friendly API

## 🧰 Hardware Requirements

- Arduino Uno, Nano, Mega, ESP32, etc.
- WS2812/APA102 LED strip or built-in LED

## 🔌 Wiring Example (for WS2812)

- **LED Strip DIN** → Arduino Pin 6 (default)
- **GND** → Arduino GND
- **VCC** → 5V (or external power supply)
- *Use a 470Ω resistor on DIN and 1000µF capacitor across VCC-GND for stability*

## 📦 Installation

1. Download the library as ZIP
2. Open Arduino IDE → Sketch → Include Library → Add .ZIP Library
3. Select `LEDPatternLib.zip`

## 🧪 Example

```cpp
#include <LEDPatternLib.h>

LEDPatternLib ledPatterns(6); // Pin 6 by default

void setup() {
  ledPatterns.begin();
  ledPatterns.setBrightness(100);
}

void loop() {
  ledPatterns.rainbowCycle();
}
```

## 🪪 License

MIT License – free to use, modify, and distribute.

## Developer 
Herobrine Pixel 2025

---
Happy blinking! 🎉
