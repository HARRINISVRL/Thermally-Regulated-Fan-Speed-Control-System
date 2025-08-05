# 🔥 Smart Thermal Environment Regulator using Arduino

A modernized, feature-rich temperature-based fan speed controller that adapts to ambient conditions and ensures system safety with visual and audible feedback.
--
## 💡 Features

- 🌀 Adaptive fan speed control based on sensed temperature
- 📟 Real-time display on OLED (Temp, Fan status, Mode)
- 🔔 Buzzer alert at high temperature (>50°C)
- 🔘 Manual override via push button (max fan speed)
- 🌡️ Dual temperature sensing (DHT22 or analog)
- 💤 Sleep mode and low-power friendly design

## 🔧 Hardware Requirements

- Arduino Uno/Nano
- DHT22 / DHT11 Temperature Sensor (or NTC)
- 12V Fan (PWM controllable)
- SSD1306 OLED Display
- Buzzer
- Push Button
- 220 ohm resistors
- Power Supply (9V-12V)
- Breadboard & Jumper wires


## 📷 Schematic

Connect:
- `DHT22` to Pin 8
- `Fan PWM` to Pin 5
- `Buzzer` to Pin 6
- `Button` to Pin 7
- `OLED SDA/SCL` to A4/A5 (for Uno/Nano)

## 🚀 How it Works

- The Arduino reads temperature via DHT22 or analog input.
- Fan speed is adjusted via PWM based on the temperature range.
- An OLED displays the temperature, fan speed, and current mode.
- A button toggles manual override mode (forces fan ON at max).
- Buzzer alerts if temperature exceeds a critical threshold (50°C).

## 🧪 Applications

- Electronics cooling systems
- Server room fan automation
- Greenhouse or environmental control
- DIY PC case mod projects

## 📝 License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.


---

📫 Contact

For questions, collaboration, or feedback:

Open an issue on GitHub

Or contact the developer via email (rlharrini@gmail.com) or via LinkedIn (www.linkedin.com/in/harrinirl26)
---


