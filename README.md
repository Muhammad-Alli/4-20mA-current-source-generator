# 4-20mA current source generator

This project implements a **portable 4–20 mA current generator** using an Arduino Uno and custom-built analogue circuitry designed to simulate analog current signals for industrial instrumentation testing. It is a battery operated hand-held device making it ideal for portable field applications such as simulating sensors (e.g. valves and transducers) in industrial process control systems.

---

## Features

- Output current range: **4–20 mA**
- **Push-button interface** for discrete and fine current selection
- Display of **setpoint** and **measured current** via 2x16 LCD
- Arduino Uno–controlled signal processing and display
- PWM + low-pass filter as DAC substitute
- **Voltage doubler circuit** to supply analog driver circuits (18 V)
- Compact hand-held device that is battery-powered (9V)

---

## Components Used

The current source consists of:

- Power Supply Unit (9V battery + Voltage Doubler)
- Arduino Uno (PWM, ADC)
- Low-pass Filter (PWM → DC)
- 4–20 mA Driver Circuit (Op-Amp + Transistor)
- Feedback Circuit (Op-Amp Amplifier)
- 2x16 LCD display
- Push-button interface (Coarse & Fine adjustment)

| Component            | Quantity | Description                             |
|----------------------|----------|-----------------------------------------|
| Arduino Uno          | 1        | Microcontroller                         |
| 2x16 LCD             | 1        | Display current values                  |
| LM324 Op-Amp IC      | 1        | Driver & Feedback amplifier             |
| 2N2102 Transistor    | 1        | Current driver                          |
| ICL7660              | 1        | Voltage doubler IC                      |
| Resistors, Capacitors| Various  | For filtering, gain setting, etc.       |
| Push Buttons         | 4        | For selecting setpoint current          |
| 9V Battery           | 1        | Power source                            |

---

## How It Works

1. **PWM Generation**: The Arduino outputs PWM signals based on button input.
2. **Digital to Analog Conversion**: PWM passes through a low-pass filter to generate a DC voltage.
3. **Voltage-to-Current Conversion**: The filtered voltage is input to the driver circuit, which converts it to a corresponding current (4–20 mA).
4. **Feedback**: A feedback signal is generated using an op-amp and sent to the Arduino ADC for measurement.
5. **Display**: Setpoint and measured current values are displayed on the LCD in real time.

---

## Firmware Summary

Written in Arduino C++, the firmware allows:

- Coarse adjustment (4 mA, 12 mA, 20 mA)
- Fine tuning (±0.1 mA)
- Real-time ADC feedback monitoring
- PWM output scaling from 1 V to 5 V
- LCD updates for set and measured current

---

## Performance

- Output current range achieved: **~3.9 mA to 19.4 mA**
- Accuracy limited by resistor tolerance, PWM filtering, and analog noise.
- Future improvements could include precision op-amps and digital DAC for better linearity.

---

## References

Detailed references and explanations are available in the included report (/Docs/4-20mA Current Source_Project Report.pdf).
