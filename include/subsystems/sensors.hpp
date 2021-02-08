#ifndef _SENSORS_H_
#define _SENSORS_H_

namespace sensors {

void init();
bool colorDetect(bool invert = false);
bool flywheelDetect();
bool ejectDetect();

} // namespace sensors
#endif
