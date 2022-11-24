/*

Module: Model4916_cPCA9574.h

Function:
    The Model4916 library: library for the PCA9574 I2C output buffer

Copyright:
    See accompanying LICENSE file for copyright and license information.

Author:
    Dhinesh Kumar Pitchai, MCCI Corporation   November 2022

*/

#ifndef _Model4916_cPCA9574_h_
# define _Model4916_cPCA9574_h_

#pragma once

#include <cstdint>
#include <Wire.h>

namespace McciModel4916 {

/****************************************************************************\
|
|   PCA9574 I2C output buffer
|
\****************************************************************************/

class cPCA9574
    {
public:
    // the default i2c address
    static constexpr std::uint8_t kI2cAddress [] = {
                                    0x20,
                                    0x21
                                    };

private:
    // the mask of bits in the PCA9574 output register that are active.
    static constexpr std::uint8_t kActiveBits = 0xFF;

    //*******************************************
    // Constructor, etc.
    //*******************************************
public:
    cPCA9574(TwoWire *pWire, uint8_t nIndex)
            : m_i2caddr(kI2cAddress[nIndex])
            , m_wire(pWire)
            , m_inversion(0)
            {};

    // neither copyable nor movable
    cPCA9574(const cPCA9574&) = delete;
    cPCA9574& operator=(const cPCA9574&) = delete;
    cPCA9574(const cPCA9574&&) = delete;
    cPCA9574& operator=(const cPCA9574&&) = delete;

    //*******************************************
    // The public methods
    //*******************************************
public:
    // initialize the PCA9574.
    bool begin();

    // stop using the PCA9574.
    void end();

    // set the output of the PCA9574 to value.
    bool set(std::uint8_t value);

    // modify the output of the PCA9574; use mask to enable writing of bits
    bool modify(std::uint8_t mask, std::uint8_t bits);

    // set the polarity of each output; 0 == normal, 1 == inverting.
    bool setPolarity(std::uint8_t mask)
        { this->m_inversion = (~mask) & kActiveBits; }

    // get the polarity of each output.
    std::uint8_t getPolarity() const
        { return this->m_inversion ^ kActiveBits; }

    // get the current (cached) value.
    std::uint8_t get() const
        { return this->m_value & kActiveBits; }

    // read the output register of the PCA9574. Takes into
    // account inversion, so result is conmensurate with
    // cPCA9574::get().
    bool read(std::uint8_t &value) const;

    //*******************************************
    // The instance data
    //*******************************************
private:
    // the i2c bus used to access the device.
    TwoWire *m_wire;
    // the i2c addresses.
    std::uint8_t m_i2caddr;
    // the most recent value.
    std::uint8_t m_value;
    // the inversion mask. For each bit, 0 ==> non-inverting.
    std::uint8_t m_inversion;
    };

} // namespace McciModel4916

#endif // _Model4916_cPCA9574_h_
