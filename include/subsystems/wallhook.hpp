#ifndef _WALLHOOK_H_
#define _WALLHOOK_H_

#include "okapi/api.hpp"

namespace wallhook {

extern okapi::MotorGroup motors;
void init();
void move(int speed);
void opcontrol();

} // namespace wallhook

#endif
