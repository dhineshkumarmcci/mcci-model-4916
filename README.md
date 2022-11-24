# MCCI-Catena-4916 library

This library provides Arduino support for the MCCI Catena&reg; Model 4916 Multi Gas Sensor.

<!-- markdownlint-disable MD033 -->
<!-- markdownlint-capture -->
<!-- markdownlint-disable -->
<!-- TOC depthFrom:2 updateOnSave:true -->

- [Introduction](#introduction)
- [Key classes](#key-classes)
	- [`cPCA9574` I2C GPIO controller](#cPCA9574-i2c-gpio-controller)
	- [`c4916Gpios` Catena 4916 GPIO Control](#c4916gpios-catena-4916-gpio-control)
- [Example Sketches](#example-sketches)
- [Additional material](#additional-material)
- [Meta](#meta)
	- [License](#license)
	- [Support Open Source Hardware and Software](#support-open-source-hardware-and-software)
	- [Trademarks](#trademarks)

<!-- /TOC -->
<!-- markdownlint-restore -->
<!-- Due to a bug in Markdown TOC, the table is formatted incorrectly if tab indentation is set other than 4. Due to another bug, this comment must be *after* the TOC entry. -->

## Introduction

The MCCI Model 4916 Multi Gas Sensor allows real-time monitoring of the air quality, paritcle micro, and various gases (O3, CO, CO2, NO2, SO2). Data can be stored in an SD card and also transmitted over LoRaWAN networks such as The Things Network or Helium.

The Catena 4916 adds the following functions in addition to monitoring gases.

- Environmental parameters, Temperature and Humidity.

- An SD-card slot similar to the Adalogger, but different in a couple of ways. First the SD-card is electrically buffered going to and from the system; it can't interfere with the SPI bus when you're not using it. Second, the SD-card slot has a dedicated power supply that is off by default.

- GPS module to track the location and get satellite time.

- MCCI Model 4906, Supercap board, which is connected as power-source.

## Key classes

### `cPCA9574` I2C GPIO controller

This class models the hardware of PCA9574 I2C GPIO expander. It has no knowledge of how the PCA9574 is wired up.

### `c4916Gpios` Catena 4916 GPIO Control

This class models the GPIOs of the Catena 4916. It understands the wiring and polarities so that clients can use method like `c4916Gpios::setVgps()` to turn on power to GPS module and also followed with method like `c4916Gpios::enableGps()` to enable the communication with the module.

## Example Sketches

The [`Model4916_Gpio_Test`](examples/Model4916_Gpio_Test/Model4916_Gpio_Test.ino) example sketch test basic feature of the Model 4916.

## Meta

### License

This repository is released under the [MIT](./LICENSE) license. Commercial licenses are also available from MCCI Corporation.

### Support Open Source Hardware and Software

MCCI invests time and resources providing this open source code, please support MCCI and open-source hardware by purchasing products from MCCI, Adafruit and other open-source hardware/software vendors!

For information about MCCI's products, please visit [store.mcci.com](https://store.mcci.com/).

### Trademarks

MCCI and MCCI Catena are registered trademarks of MCCI Corporation. LoRaWAN is a registered trademark of the LoRa Alliance. LoRa is a registered trademark of Semtech Corporation. All other marks are the property of their respective owners.
