#ifndef _INDEXER_H_
#define _INDEXER_H_

#include "okapi/api.hpp"

namespace indexer {

extern okapi::MotorGroup motors;
void init();
void move(int speed);
void opcontrol();
void runUntilFull();
void score(int num = 1);

} // namespace indexer

#endif
