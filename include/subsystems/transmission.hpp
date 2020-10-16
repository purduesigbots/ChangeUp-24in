#ifndef _TRANSMISSION_H_
#define _TRANSMISSION_H_

#include "okapi/api.hpp"

namespace transmission {

    extern pros::ADIDigitalOut piston;
    void change();
    void opcontrol();

}

#endif