# Detailed Connections

## Power and Ground

- Connect the Arduino Nano `5V` pin to the `VCC` pin of the LDR module and all four IR sensor modules.
- Connect every sensor `GND` pin to Arduino Nano `GND`.
- Connect every LED cathode to `GND` through its own current-limiting resistor.
- Use a common ground for the Arduino, sensors, and LED circuit.

## LDR Module

| LDR module pin | Arduino Nano |
| -------------- | ------------ |
| `VCC`          | `5V`         |
| `GND`          | `GND`        |
| `DO`           | `D7`         |

The sketch expects the LDR digital output to be `LOW` in darkness. Adjust the `isNight` condition if the module's comparator output is reversed.

## IR Sensors

| Sensor | `VCC` | `GND` | Digital output |
| ------ | ----- | ----- | -------------- |
| IR1    | `5V`  | `GND` | `D2`           |
| IR2    | `5V`  | `GND` | `D3`           |
| IR3    | `5V`  | `GND` | `D4`           |
| IR4    | `5V`  | `GND` | `D5`           |

The sketch expects an IR sensor output to be `LOW` when it detects a vehicle or object.

## LEDs

| LED  | Anode connection | Cathode connection | PWM pin |
| ---- | ---------------- | ------------------ | ------- |
| LED1 | Through resistor | `GND`              | `D6`    |
| LED2 | Through resistor | `GND`              | `D9`    |
| LED3 | Through resistor | `GND`              | `D10`   |
| LED4 | Through resistor | `GND`              | `D11`   |

Pins `D6`, `D9`, `D10`, and `D11` support PWM on the Arduino Nano. PWM values in the sketch are `60` for dim brightness and `255` for full brightness.

## Functional Mapping

- LDR determines whether the system is in daytime or nighttime mode.
- IR1 controls LED1.
- IR2 controls LED2.
- IR3 controls LED3.
- IR4 controls LED4.
- Daytime mode writes `0` to every LED.
- Nighttime mode writes either dim or full brightness to each LED independently.
