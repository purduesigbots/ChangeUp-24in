#ifndef _WALLHOOK_H_
#define _WALLHOOK_H_

#include "okapi/api.hpp"

namespace wallhook {

extern okapi::MotorGroup motors;
extern int speed;
void init();
void move(int speed);

} // namespace wallhook

#endif
