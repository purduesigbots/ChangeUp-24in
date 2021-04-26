#include "main.h"
#include "pros/adi.hpp"

namespace sensors {

#define FLYWHEEL_THRESHOLD 2775
#define EJECT_THRESHOLD 2600
#define BLUE 150
#define RED 25

ADIAnalogIn flywheel_sensor('b');
ADIAnalogIn eject_sensor1('h');
ADIAnalogIn eject_sensor2('e');
ADIUltrasonic ultrasonic('c', 'd');
Optical color(5);

void init() {
	color.set_led_pwm(100);
}

bool flywheelDetect() {
	return (flywheel_sensor.get_value() < FLYWHEEL_THRESHOLD);
}

bool ejectDetect() {
	return (eject_sensor1.get_value() < EJECT_THRESHOLD ||
	        eject_sensor2.get_value() < EJECT_THRESHOLD);
}

bool colorDetect(bool invert) {
	if ((selector::auton < 0 && !invert) || (selector::auton > 0 && invert))
		return (color.get_hue() <= RED) ? true : false;
	else
		return (color.get_hue() >= BLUE) ? true : false;
}

double getUltrasonicDist() {
	return ultrasonic.get_value() / 10 / 2.54;
}

} // namespace sensors
