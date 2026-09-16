# 💡 Smart Street Light System

An Arduino Nano based smart street lighting prototype that automatically controls individual LED brightness based on vehicle or object detection.

The system uses multiple IR sensors to detect movement and independently control four LEDs. When no vehicle or object is detected, the corresponding LED remains dim. When an object is detected, the corresponding LED switches to full brightness.

---

## 🎥 Project Demo

### Watch the system in action

[![Smart Street Light System Demo](images/working.png)](https://youtu.be/j2KZ5oQoFCw)

**▶ [Watch the full project demonstration on YouTube](https://youtu.be/j2KZ5oQoFCw)**

A copy of the original project demonstration video is also included in the repository:

`video/smart-street-light-demo.mp4`

---

## 🎯 Objective

The objective of this project is to demonstrate an automated street lighting system that can reduce unnecessary power consumption by controlling individual street lights based on vehicle or object detection.

Instead of keeping every light at full brightness continuously, the system keeps the lights at a lower brightness when there is no detected movement and increases the brightness of the corresponding light when an object is detected.

---

## ⚙️ How the System Works

The Arduino Nano acts as the main controller and processes the signals received from four IR sensors.

1. Four IR sensors continuously monitor their corresponding sections.
2. When no vehicle or object is detected, the corresponding LED operates at dim brightness.
3. When an IR sensor detects a vehicle or object, its corresponding LED switches to full brightness.
4. When the object is no longer detected, the LED returns to dim brightness.
5. Each IR sensor controls its corresponding LED independently.

### Example

```text
IR Sensor 1 detects vehicle
          ↓
Arduino Nano receives signal
          ↓
LED 1 → FULL BRIGHTNESS

IR Sensor 1 detects nothing
          ↓
LED 1 → DIM BRIGHTNESS
```
