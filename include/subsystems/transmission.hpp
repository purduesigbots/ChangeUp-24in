#ifndef _TRANSMISSION_H_
#define _TRANSMISSION_H_

#include "okapi/api.hpp"

namespace transmission {

extern pros::ADIDigitalOut piston;
void toggle();
void opcontrol();

} // namespace transmission

#endif
