/*

Module: Model4916_c4916Gpios.cpp

Function:
    The Model4916 library: implementation for the Catena GPIOs

Copyright:
    See accompanying LICENSE file for copyright and license information.

Author:
    Dhinesh Kumar Pitchai, MCCI Corporation   November 2022

*/

#include "../Model4916_c4916Gpios.h"

using namespace McciModel4916;

bool c4916Gpios::begin()
    {
    bool fResult;

    this->m_gpio->setPolarity(this->m_gpio->getPolarity());

    fResult = this->m_gpio->begin();

    return fResult;
    }

void c4916Gpios::end()
    {
    this->m_gpio->end();
    }
