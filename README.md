# 💡 Smart Street Light System

An Arduino Nano based smart street lighting prototype that automatically controls individual LED brightness based on vehicle or object detection.

The system uses four IR sensors to detect movement and independently control four LEDs. When no object is detected, the corresponding LED remains dim. When an object is detected, the corresponding LED switches to full brightness.

---

## 🎥 Project Demo

[![Smart Street Light System Demo](images/working.png)](https://youtu.be/j2KZ5oQoFCw)

**▶ [Watch the Project Demo on YouTube](https://youtu.be/j2KZ5oQoFCw)**

A copy of the project video is also included in the repository:

`video/smart-street-light-demo.mp4`

---

## 🎯 Objective

The goal of this project is to demonstrate a smart street lighting system that can reduce unnecessary power consumption by increasing the brightness of individual lights only when vehicle or object movement is detected.

---

## ⚙️ How It Works

The Arduino Nano acts as the main controller.

1. Four IR sensors monitor their corresponding sections.
2. When no object is detected, the corresponding LED operates at dim brightness.
3. When an IR sensor detects an object, its corresponding LED switches to full brightness.
4. When the object is no longer detected, the LED returns to dim brightness.
5. Each sensor independently controls its corresponding LED.

```text
IR Sensor
    │
    ▼
Object Detected?
   /        \
 YES        NO
  │          │
  ▼          ▼
FULL        DIM
255          60
  │          │
  └────┬─────┘
       ▼
Corresponding LED
```
