[![MCHP](images/microchip.png)](https://www.microchip.com)

# TCE and WEX new features examples

This repository contains examples of MPLAB® Code Configurator (MCC) Melody source code for the new Timer Counter type E (TCE) and Waveform Extension (WEX) peripherals of the AVR<sup>®</sup> EB family of devices. There are five applications described in this document. Each application highlights new features of the two peripherals. Each application's functionality is explained.

* [<strong>PWM Signal Modulation Code Example:</strong>](PWM_Modulation) In this use case, the TCE and WEX are used to generate sinusoidal signals modulating Pulse-Width Modulation signals. At run time the sinewave can be modulated in frequency or amplitude.
* [<strong>Dead time and Fault Code Example:</strong>](WEX_DT_FAULT) This example shows how to use WEX and TCE to generate complementary signals with added dead time in hardware. This code example highlights the fault hardware handling feature, and the fault hardware filter.
* [<strong>Scaling Code Example:</strong>](TCE Scaling) In this example the TCE timer is initialized in Dual-Slope mode with initial values for the duty cycles of PWM signals. At runtime the values of duty cycles change depending on the value of Amplitude and Scale mode. This code example highlights the hardware scaling feature of TCE for duty cycle values.
* [<strong>High Resolution Code Example:</strong>](TCE_HighResolution) In this example the TCE is configure to generate four PWM signals with one peripheral clock cycle difference between the duty cycles of each PWM signal. The peripheral clock is configured to enable the High Resolution feature of TCE (up to 160 MHz).
* [<strong>Pattern Generation and Swap Code Example:</strong>](WEX_Pgm_Swap) This is a basic use case of the WEX peripheral to set a pattern for the output signals that changes periodically. This example shows how WEX can take control of output signals from TCE and generate patterns, and how the Swap feature works.

## Related Documentation

More details and code examples on the AVR16EB32 can be found at the following links:

- [AVR<sup>®</sup> EB Product Page](https://www.microchip.com/en-us/product/AVR16EB32)
- [AVR<sup>®</sup> EB Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=AVR16EB32)

## Software Used

- [MPLAB® X IDE v6.15 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- [AVR-Ex DFP-2.8.189 or newer Device Pack](https://packs.download.microchip.com/)
- [MPLAB® XC8 compiler v2.45](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC8)
- [MPLAB® Code Configurator (MCC) v5.3.7](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)
- [MPLAB® Code Configurator (MCC) Melody Core v2.6.2 or newer](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)

## Hardware Used

- [AVR<sup>®</sup> EB Curiosity Nano](https://www.microchip.com/en-us/product/AVR16EB32)

## Setup

The AVR16EB32 Curiosity Nano Development board is used as test platform.

<br><img src="images/AVR16EB32_Cnano_Board.png">