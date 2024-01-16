# Indoor Air Quality Monitoring System with MQ135 and Raspberry Pi Pico W

This project implements an Indoor Air Quality Monitoring System using the Raspberry Pi Pico W and the MQ135 air quality sensor. The system measures the air quality and displays it on an OLED screen, providing visual indications based on predefined thresholds.

## Hardware Requirements

- Raspberry Pi Pico W
- MQ135 Air Quality Sensor
- OLED Display (SSD1306)
- Jumper wires
- Resistor for MQ135 heater

## Software Requirements

- Arduino IDE with Raspberry Pi Pico support
- Required Arduino libraries:
  - MQ135 Library

## Wiring Instructions

1. Connect the MQ135 sensor to the Raspberry Pi Pico W following the datasheet and pinout.
2. Connect the OLED display to the Raspberry Pi Pico W.
3. Add a resistor for the MQ135 sensor heater.

## Arduino IDE Setup

1. Install the required libraries through the Arduino Library Manager.
2. Select "Raspberry Pi Pico" as the board in Arduino IDE.
3. Set up the correct port for your Raspberry Pi Pico.
4. Open the `IndoorAirQualityMonitor.ino` sketch in Arduino IDE.

## Configuration

Adjust the following parameters in the `IndoorAirQualityMonitor.ino` sketch if needed:

- **MQ135 Sensor Calibration:** If necessary, calibrate the sensor values based on your specific environment.

## Usage

1. Upload the sketch to your Raspberry Pi Pico.
2. Open the Serial Monitor to view air quality readings and debug information.
3. Observe the OLED display for real-time air quality information.
4. Customize the LED and buzzer thresholds based on your preferences.
