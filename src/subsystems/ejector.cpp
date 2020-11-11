#include "main.h"

namespace ejector {

#define BLUE 210
#define RED 25

okapi::MotorGroup motors = {-1, -2};
Optical color(5);

void init() {
	motors.setGearing(okapi::AbstractMotor::gearset::green);
	motors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motors.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
	color.set_led_pwm(100);
}

void move(int speed) {
	motors.moveVoltage(speed * 120);
}

bool colorDetect() {
	if (selector::auton > 0)
		return (color.get_hue() <= RED) ? true : false;
	else
		return (color.get_hue() >= BLUE) ? true : false;
}

void opcontrol() {
	static int speed;
	printf("Color Select Value = %d\n", colorDetect());
	if (master.get_digital(DIGITAL_L2) || colorDetect()) // outtake
		speed = -100;
	else if (master.get_digital(DIGITAL_L1)) // score
		speed = 100;
	else
		speed = 0;

	move(speed);
} // namespace ejector

} // namespace ejector
