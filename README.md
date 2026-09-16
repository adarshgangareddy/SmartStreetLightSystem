# Smart Street Light System

An Arduino Nano based street light controller that adjusts LED brightness according to ambient light and nearby vehicle or object detection.

## Objective

Reduce unnecessary energy use while keeping street lights available at night. The system switches all LEDs off during the day, keeps them dim at night, and increases an individual LED to full brightness when its associated IR sensor detects a vehicle or object.

## How the System Works

1. The LDR sensor module monitors the ambient light level.
2. During daytime, all four LEDs are switched off.
3. During nighttime, all four LEDs operate at a dim brightness.
4. When an IR sensor detects a vehicle or object, its corresponding LED changes to full brightness.
5. When detection ends, that LED returns to dim brightness.

The sketch assumes the LDR module reads `LOW` in darkness and that each IR sensor reads `LOW` when an object is detected. Sensor modules with opposite digital logic can be accommodated by inverting the corresponding conditions in the sketch.

## Components Used

- Arduino Nano
- 1 x LDR sensor module
- 4 x IR sensors
- 4 x LEDs
- 4 x suitable current-limiting resistors for the LEDs
- Breadboard and jumper wires
- USB cable for programming
- Suitable 5 V power source

## Pin Connections

| Component                 | Arduino Nano pin | Notes                             |
| ------------------------- | ---------------- | --------------------------------- |
| LDR sensor digital output | D7               | Ambient light input               |
| IR sensor 1 output        | D2               | Controls LED 1                    |
| IR sensor 2 output        | D3               | Controls LED 2                    |
| IR sensor 3 output        | D4               | Controls LED 3                    |
| IR sensor 4 output        | D5               | Controls LED 4                    |
| LED 1 anode               | D6               | PWM output, use a resistor        |
| LED 2 anode               | D9               | PWM output, use a resistor        |
| LED 3 anode               | D10              | PWM output, use a resistor        |
| LED 4 anode               | D11              | PWM output, use a resistor        |
| Sensor and LED grounds    | GND              | Common ground                     |
| Sensor VCC                | 5V               | Check module voltage requirements |

Connect each LED cathode to GND through its own current-limiting resistor. Do not connect an LED directly to an Arduino pin without a resistor.

## Working Logic

| Ambient condition | IR sensor state | LED state                     |
| ----------------- | --------------- | ----------------------------- |
| Daytime           | Any             | All LEDs OFF                  |
| Nighttime         | No detection    | Corresponding LED DIM         |
| Nighttime         | Detection       | Corresponding LED FULL BRIGHT |

The configured brightness values are:

- `DIM_BRIGHTNESS = 60`
- `FULL_BRIGHTNESS = 255`

## Circuit and Setup

Place the LDR module where it can sense general ambient light rather than the light from one LED. Position each IR sensor so it monitors the section of road represented by its matching LED. Connect all module grounds to the Arduino Nano GND, and connect the module VCC pins to the appropriate supply.

For a physical prototype, use a separate resistor for every LED. Confirm the sensor output polarity and adjust the `isNight` or detection condition in `src/smart_street_light.ino` if your modules use the opposite logic level.

## Project Video

[Watch Project Demo](video/smart-street-light-demo.mp4)

The video file is a placeholder until the project demonstration is added.

## Screenshots

- [Circuit connections](images/circuit-connections.jpg)
- [Prototype](images/prototype.jpg)
- [Working system](images/working.jpg)

The image files are placeholders until project photos are added.

## Upload the Code to Arduino Nano

1. Install the Arduino IDE.
2. Open `src/smart_street_light.ino`.
3. Connect the Arduino Nano with a USB cable.
4. Select **Tools > Board > Arduino AVR Boards > Arduino Nano**.
5. Select the correct port under **Tools > Port**.
6. If upload fails on an older Nano, select the matching processor under **Tools > Processor**, such as **ATmega328P (Old Bootloader)**.
7. Click **Upload**.
8. Disconnect USB power before changing the circuit wiring.

## Future Improvements

- Add a real-time clock or schedule-based control mode.
- Measure ambient light with an analog LDR input for smoother transitions.
- Add energy monitoring and battery or solar charging status.
- Use wireless monitoring for fault reporting and usage statistics.
- Add gradual brightness fading instead of immediate PWM changes.
- Protect the outdoor electronics with a weather-resistant enclosure.

## Author

**Project Author:** Add your name here

## License

Add a license appropriate for your project before publishing the repository.
