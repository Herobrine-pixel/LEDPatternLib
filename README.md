# LEDPatternLib

**Author:** Herobrine Pixel  
**License:** MIT  
**Version:** 1.0.1 

---

## 🌈 LEDPatternLib — Versatile LED Pattern Library (NeoPixel Edition)

`LEDPatternLib` is a lightweight, modular Arduino library for displaying various LED animations such as **blink**, **rainbow**, and **Knight Rider** patterns. This version is built specifically for **NeoPixel (WS2812)** LEDs using the [Adafruit NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel).

---

## 🔌 Features
- Support for NeoPixel WS2812/APA102
- Built-in LED blinking
- Predefined effects: blink, rainbow, knight rider
- Adjustable brightness
- Works with Arduino and PlatformIO
  
---

## 🔌 Wiring Instructions

### 🧾 Requirements
- Arduino Uno, Nano, Mega, ESP32, etc.
- NeoPixel Strip (WS2812 or compatible)
- 470Ω resistor (recommended for signal line)
- 1000 µF capacitor (recommended across VCC-GND)
- External 5V power supply (if powering many LEDs)

### 🪛 Circuit Connections

### Built-in LED
- No wiring needed if using pin 13 (on most Arduino boards).

| NeoPixel Pin | Connect To Arduino |
|--------------|--------------------|
| **GND**      | GND                |
| **VCC (5V)** | 5V (or external)   |
| **DIN**      | Digital Pin (e.g., D6) via 470Ω resistor |

💡 **Important:**  
For more than 8–10 LEDs, use an **external 5V power supply** and **common ground** between Arduino and power supply.

---

## 📦 Installation

### Arduino IDE:
1. Go to **Sketch > Include Library > Add .ZIP Library…**
2. Select the downloaded `LEDPatternLib.zip` file
3. Install the **Adafruit NeoPixel** library:  
   Go to **Tools > Manage Libraries**, search for **Adafruit NeoPixel**, and install it.

---
## Example Usage
```cpp
#include <LEDPatternLib.h>
LEDPatternLib led(6, 8); // For NeoPixel
// LEDPatternLib led(13); // For built-in LED

void setup() {
  led.begin();
  led.setBrightness(150);
}

void loop() {
  led.blink(0x00FF00, 500);
  led.knightRider(0xFF0000, 50);
  led.rainbowCycle(10);
}
```

---

## 🧠 API Reference

### Constructor:
```cpp
LEDPatternLib(uint8_t pin, uint16_t numPixels);
```

### Methods:
- `void begin();`  
  Initializes the LED strip.

- `void setBrightness(uint8_t brightness);`  
  Set brightness (0–255).

- `void blink(uint32_t color, uint16_t delay_ms = 500);`  
  Blink with a solid color.

- `void rainbowCycle(uint8_t wait = 20);`  
  Rainbow animation.

- `void knightRider(uint32_t color = 0xFF0000, uint8_t speed = 50);`  
  Knight Rider-style bouncing LED.

---

## 🧪 Tested On

- Arduino Uno ✅  
- ESP32 DevKit v1 ✅  
- WS2812B LED Strip ✅

---

## 📖 License

Copyright (c) 2025 Herobrine Sah

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.



---

## 🔗 Repository

GitHub: [https://github.com/Herobrine-pixel/LEDPatternLib](https://github.com/Herobrine-pixel/LEDPatternLib)
