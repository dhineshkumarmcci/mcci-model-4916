/*

Module: Model4916_Gpio_Test.ino

Function:
    Simple test program for the Model 4916.

Copyright:
    See accompanying LICENSE file for copyright and license information.

Author:
    Dhinesh Kumar Pitchai, MCCI Corporation   November 2022

*/

#include <Arduino.h>
#include <Wire.h>
#include <Catena.h>
#include <Model4916_cPCA9574.h>
#include <Model4916_c4916Gpios.h>

extern McciCatena::Catena gCatena;
using namespace McciModel4916;


/****************************************************************************\
|
|   Variables.
|
\****************************************************************************/

using namespace McciCatena;

cPCA9574 i2cgpiopower    { &Wire, 0 };
c4916Gpios gpiopower     { &i2cgpiopower };

cPCA9574 i2cgpioenable    { &Wire, 1 };
c4916Gpios gpioenable     { &i2cgpioenable };

Catena gCatena;

/****************************************************************************\
|
|   Setup
|
\****************************************************************************/

void setup() {
    Wire.begin();
    Serial.begin(115200);
    while (! Serial)
        delay(1);
    Serial.println("\nModel4916_Gpio_Test");

    gCatena.begin();

    if (! gpiopower.begin())
        Serial.println("GPIO Power failed to initialize");

    if (! gpioenable.begin())
        Serial.println("GPIO Enable failed to initialize");
}

/****************************************************************************\
|
|   Loop
|
\****************************************************************************/

void loop() {
    gCatena.poll();

    // enable power to I2C Level shifter of GPS module.
    gpiopower.setVgps(true);

    // enable I2C communication of GPS module.
    gpiopower.enableGps(true);
}