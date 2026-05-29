# Ultrasonic Distance Display

Real-time distance measurement using an HC-SR04 ultrasonic sensor displayed on a 16x2 I2C LCD. Classifies readings into proximity zones and handles out-of-range detection.

## Demo
> _vid_

## Hardware
| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 16x2 I2C LCD (PCF8574) | 1 |
| Jumper wires | ~8 |

## Wiring
| HC-SR04 | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | Pin 10 |
| ECHO | Pin 9 |

| LCD | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## How It Works
The HC-SR04 sends a 10µs ultrasonic pulse and measures the time for the echo to return. Using the speed of sound (343 m/s), the sketch converts the round-trip duration to centimeters and classifies it:

| Range | Label |
|---|---|
| 0 – 75 cm | NEAR |
| 76 – 200 cm | MID |
| 201 – 500 cm | FAR |
| > 500 cm | OUT OF RANGE |

## Dependencies
- [LiquidCrystal I2C](https://github.com/johnrickman/LiquidCrystal_I2C) by Frank de Brabander

## What I Learned
- HC-SR04 sensor interfacing and pulse timing
- I2C communication protocol
- Structuring Arduino C++ with reusable functions
- Handling sensor edge cases (out-of-range readings)
