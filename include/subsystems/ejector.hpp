#ifndef _EJECTOR_H_
#define _EJECTOR_H_

#include "okapi/api.hpp"

namespace ejector {

extern okapi::MotorGroup motor;
void init();
void move(int speed);
void opcontrol();

} // namespace ejector

#endif
