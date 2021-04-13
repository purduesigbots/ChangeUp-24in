#include "main.h"

namespace sensors {

#define FLYWHEEL_THRESHOLD 2775
#define EJECT_THRESHOLD 2785
#define BLUE 150
#define RED 25

ADIAnalogIn flywheel_sensor('b');
ADIAnalogIn eject_sensor('h');
Optical color(5);

void init() {
	color.set_led_pwm(100);
}

bool flywheelDetect() {
	return (flywheel_sensor.get_value() < FLYWHEEL_THRESHOLD);
}

bool ejectDetect() {
	return (eject_sensor.get_value() < EJECT_THRESHOLD);
}

bool colorDetect(bool invert) {
	if ((selector::auton < 0 && !invert) || (selector::auton > 0 && invert))
		return (color.get_hue() <= RED) ? true : false;
	else
		return (color.get_hue() >= BLUE) ? true : false;
}

} // namespace sensors
