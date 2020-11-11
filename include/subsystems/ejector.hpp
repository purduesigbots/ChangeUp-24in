#ifndef _EJECTOR_H_
#define _EJECTOR_H_

#include "okapi/api.hpp"

namespace ejector {

extern okapi::MotorGroup motors;
void init();
void move(int speed);
bool colorDetect();
void opcontrol();

} // namespace ejector

#endif
