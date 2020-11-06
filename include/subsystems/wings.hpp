#ifndef _WINGS_H_
#define _WINGS_H_

#include "okapi/api.hpp"

namespace wings {

    extern pros::ADIDigitalOut piston1;
    extern pros::ADIDigitalOut piston2;
    void toggle();
    void opcontrol();

}

#endif