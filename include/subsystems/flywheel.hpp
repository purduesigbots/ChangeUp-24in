#ifndef _FLYWHEEL_H_
#define _FLYWHEEL_H_

#include "okapi/api.hpp"

namespace flywheel {

extern okapi::MotorGroup motors;
void init();
void move(int speed);
void opcontrol();

} // namespace flywheel

#endif
