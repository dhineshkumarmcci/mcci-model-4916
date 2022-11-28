/*

Module: Model4916_c4916Gpios.h

Function:
    The Model4916 library: library for the PCA9574 I2C output buffer

Copyright:
    See accompanying LICENSE file for copyright and license information.

Author:
    Dhinesh Kumar Pitchai, MCCI Corporation   November 2022

*/

#ifndef _Model4916_c4916Gpios_h_
# define _Model4916_c4916Gpios_h_

#include <stdint.h>
#pragma once

#include <Model4916_cPCA9574.h>

namespace McciModel4916 {

/****************************************************************************\
|
|   The 4916 GPIO cluster -- I2C GPIOs plus
|
\****************************************************************************/

class c4916Gpios
    {
public:
    // the IO expander (0x40) to provide power (Vdd)
    enum class Power_t : std::uint8_t
        {
        kVdd_1      = 1 << 0,
        kVdd_Gps    = 1 << 1,
        kVdd_Tvoc   = 1 << 2,
        kVdd_Qwiic  = 1 << 3,
        kVdd_Spi    = 1 << 4,
        kVdd_Piera  = 1 << 5,
        };

    // the IO expander (0x42) to enable I2C Level Shifter
    enum class Enable_t : std::uint8_t
        {
        kEnable_Vdd1    = 1 << 0,
        kEnable_Tvoc    = 1 << 1,
        kEnable_Gps     = 1 << 2,
        kEnable_Piera   = 1 << 3,
        kEnable_Qwiic   = 1 << 4,
        };


private:

    //*******************************************
    // Constructor, etc.
    //*******************************************
public:
    c4916Gpios(cPCA9574 *pPCA9574) : m_gpio(pPCA9574) {};

    // neither copyable nor movable
    c4916Gpios(const c4916Gpios&) = delete;
    c4916Gpios& operator=(const c4916Gpios&) = delete;
    c4916Gpios(const c4916Gpios&&) = delete;
    c4916Gpios& operator=(const c4916Gpios&&) = delete;

    //*******************************************
    // The public methods
    //*******************************************
public:
    bool begin();
    void end();

    /*functions to provide power to modules*/

    bool setVdd1(bool fOn)  {
        return this->m_gpio->modify((uint8_t)Power_t::kVdd_1, fOn ? 0xFF : 0);
        }
    bool getVdd1() const   {
        return this->m_gpio->get() & (uint8_t)Power_t::kVdd_1;
        }

    bool setVgps(bool fOn) {
        return this->m_gpio->modify((uint8_t)Power_t::kVdd_Gps, fOn ? 0xFF : 0);
        }
    bool getVgps() const   {
        return this->m_gpio->get() & (uint8_t)Power_t::kVdd_Gps;
        }

    bool setVtvoc(bool fOn) {
        return this->m_gpio->modify((uint8_t)Power_t::kVdd_Tvoc, fOn ? 0xFF : 0);
        }
    bool getVtvoc() const   {
        return this->m_gpio->get() & (uint8_t)Power_t::kVdd_Tvoc;
        }

    bool setVqwiic(bool fOn) {
        return this->m_gpio->modify((uint8_t)Power_t::kVdd_Qwiic, fOn ? 0xFF : 0);
        }
    bool getVqwiic() const {
        return this->m_gpio->get() & (uint8_t)Power_t::kVdd_Qwiic;
        }

    bool setVSpi(bool fOn) {
        return this->m_gpio->modify((uint8_t)Power_t::kVdd_Spi, fOn ? 0xFF : 0);
        }
    bool getVSpi() const   {
        return this->m_gpio->get() & (uint8_t)Power_t::kVdd_Spi;
        }

    bool setVPiera(bool fOn) {
        return this->m_gpio->modify((uint8_t)Power_t::kVdd_Piera, fOn ? 0xFF : 0);
        }
    bool getVPiera() const {
        return this->m_gpio->get() & (uint8_t)Power_t::kVdd_Piera;
        }

    /*functions to enable I2C communication*/

    bool enableVdd1(bool fOn)  {
        return this->m_gpio->modify((uint8_t)Enable_t::kEnable_Vdd1, fOn ? 0xFF : 0);
        }

    bool enableGps(bool fOn) {
        return this->m_gpio->modify((uint8_t)Enable_t::kEnable_Gps, fOn ? 0xFF : 0);
        }

    bool enableTvoc(bool fOn) {
        return this->m_gpio->modify((uint8_t)Enable_t::kEnable_Tvoc, fOn ? 0xFF : 0);
        }

    bool enableQwiic(bool fOn) {
        return this->m_gpio->modify((uint8_t)Enable_t::kEnable_Qwiic, fOn ? 0xFF : 0);
        }

    bool enablePiera(bool fOn) {
        return this->m_gpio->modify((uint8_t)Enable_t::kEnable_Piera, fOn ? 0xFF : 0);
        }

private:
    cPCA9574 *m_gpio;
    };

} // namespace McciModel4916

#endif // _Model4916_c4916Gpios_h_
