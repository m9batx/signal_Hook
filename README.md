<!-- markdownlint-disable MD041 MD034 -->
[![Arduino CLI build](https://github.com/nRF24/RF24/workflows/Arduino%20CLI%20build/badge.svg)](https://github.com/nRF24/RF24/actions?query=workflow%3A%22Arduino+CLI+build%22)
[![Linux build](https://github.com/nRF24/RF24/workflows/Linux%20build/badge.svg)](https://github.com/nRF24/RF24/actions?query=workflow%3A%22Linux+build%22)
[![PlatformIO build](https://github.com/nRF24/RF24/actions/workflows/build_platformIO.yml/badge.svg)](https://github.com/nRF24/RF24/actions/workflows/build_platformIO.yml)
[![RP2xxx build](https://github.com/nRF24/RF24/actions/workflows/build_rp2xxx.yml/badge.svg)](https://github.com/nRF24/RF24/actions/workflows/build_rp2xxx.yml)
[![Documentation Status](https://readthedocs.org/projects/rf24/badge/?version=latest)](https://rf24.readthedocs.io/en/latest/?badge=latest)

# RF Signal Sniffer

A simple RF signal sniffer project using an **Arduino Uno** and an **nRF24L01+**.
<img width="447" height="447" alt="images" src="https://github.com/user-attachments/assets/a4f7c64a-53df-41a6-8120-e6d3f8c5481f" />


The project is intended for experimenting with and analyzing RF signals using the nRF24L01+ module connected to an Arduino.

## Hardware

* Arduino Uno
* nRF24L01+ RF module
* Jumper wires
* Breadboard (optional)

## Software

* Arduino IDE
* RF24 library

## Setup

1. Connect the nRF24L01+ module to the Arduino Uno.
2. Install the **RF24** library in the Arduino IDE.
3. Open the Arduino sketch from this repository.
4. Select **Arduino Uno** as the target board.
5. Select the correct serial port.
6. Upload the sketch.
7. Open the Serial Monitor to view the captured RF information.

## Repository Structure

* `sketch_feb8a_1.ino` — Arduino sketch for the RF sniffer.
* `datasheets/` — Hardware datasheets and related documentation.
* `docs/` — RF24 documentation.
* `examples/` — Example RF24 programs.
* `pyRF24/` — Python-related RF24 components.
* `images/` — Project images.
* `utility/` — Supporting utilities.

## How It Works

The Arduino communicates with the nRF24L01+ module over SPI. The RF24 library is used to configure and communicate with the radio module.

<img width="668" height="449" alt="Screenshot 2025-04-08 053628" src="https://github.com/user-attachments/assets/2de170d0-1ae2-47e1-b7bb-7fd10a2c70fb" />


The sniffer can be used as a learning and experimentation platform for observing RF activity in the supported nRF24L01+ frequency range.

Flashing the "signal_Hook.ino" on the Arduino

## Reference

For additional RF24 documentation:

https://nRF24.github.io/RF24/

## License

This project is licensed under the **GPL-2.0 License**.

## Disclaimer

This project is intended for educational, research, and authorized RF experimentation only. Use it only with signals and devices that you are authorized to analyze.
