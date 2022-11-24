/*

Module: Model4916.h

Function:
    The Model4916 library

Copyright:
    See accompanying LICENSE file for copyright and license information.

Author:
    Dhinesh Kumar Pitchai, MCCI Corporation   November 2022

*/

#ifndef _Model4916_h_
# define _Model4916_h_

#pragma once

#include "Model4916_version.h"
#include <Catena_FSM.h>
#include <Catena_PollableInterface.h>

namespace McciModel4916 {

/****************************************************************************\
|
|   Catena 4916 object
|
\****************************************************************************/

class Model4916 : public McciCatena::cPollableObject
    {
    //*******************************************
    // Forward references, etc.
    //*******************************************
private:

    //*******************************************
    // Constructor, etc.
    //*******************************************
public:
    Model4916()
        {};

    // neither copyable nor movable
    Model4916(const Model4916&) = delete;
    Model4916& operator=(const Model4916&) = delete;
    Model4916(const Model4916&&) = delete;
    Model4916& operator=(const Model4916&&) = delete;

    //*******************************************
    // The public methods
    //*******************************************
public:
    // start the wing services.
    bool begin();

    // stop the sensor.
    void end();

    virtual void poll(void) override;
    void suspend();
    void resume();

    //*******************************************
    // Public contents
    //*******************************************
public:

    //*******************************************
    // Internal utilities
    //*******************************************
private:

    //*******************************************
    // The instance data
    //*******************************************
private:
    };  // class Model4916

} // namespace McciModel4916

extern McciModel4916::Model4916           gModel4916;

#endif // defined _Model4916_h_
