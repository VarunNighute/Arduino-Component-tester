# Arduino-Component-tester
Project Overview

A versatile Arduino UNO-based component tester that can measure and identify a wide range of electronic components including resistors, capacitors, inductors, diodes, LEDs, BJTs, LDRs, and check circuit continuity.

The tester uses a 16x2 LCD display and two buttons for menu navigation, providing real-time readings and easy-to-read results. This project focuses on accurate measurement of component values using simple analog and digital techniques rather than complex instrumentation.

Features

Measures resistance, capacitance, and inductance.

Tests diodes and LEDs, identifying type and forward voltage.

Tests BJTs (NPN/PNP) and calculates hFE.

Checks continuity of circuits.

Measures LDR (Light Dependent Resistor) resistance.

Simple LCD menu interface with two-button control (Next and OK).

Real-time display of measurements on 16x2 LCD.

Working

Resistors: Uses a voltage divider with a known resistor to calculate unknown resistance.

Capacitors: Measures charging time to ~63% of supply voltage to calculate capacitance.

Inductors: Measures voltage rise time through a known resistor to calculate inductance.

Diodes/LEDs: Measures forward voltage drop to identify type.

BJTs: Applies base current, measures collector current, and calculates transistor type and hFE.

Continuity: Detects open or short circuits by measuring voltage across the test points.

LDRs: Measures voltage divider output to calculate light-dependent resistance.

Measurements are displayed directly on the LCD without requiring a computer or serial monitor, making this tester standalone and portable.

Hardware Used

Arduino UNO

16x2 LCD (with or without I2C)

Push buttons ×2 (Next, OK)

Resistors for reference and pull-ups

Breadboard and jumper wires

Components to test: resistors, capacitors, diodes, LEDs, transistors, LDRs

Optional:

Small resistors for accurate BJT current measurement

Usage

Connect the tester to the Arduino UNO and power it.

The LCD will display “Select Test:”.

Press the Next button to cycle through tests: Resistor → Inductor → Capacitor → Diode → LED → BJT → Continuity → LDR.

Press OK to start the selected test.

Read the measurement results directly on the LCD. For LDR tests, readings update continuously until Next is pressed.

Contributing

Open to suggestions, bug fixes, or adding new component tests (e.g., MOSFET testing).

Pull requests and issues are welcome.
