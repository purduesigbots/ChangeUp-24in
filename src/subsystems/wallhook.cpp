#include "main.h"

namespace wallhook {

okapi::MotorGroup motors = {1};

void init() {
	motors.setGearing(okapi::AbstractMotor::gearset::red);
	motors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motors.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
}

void move(int speed) {
	motors.moveVoltage(speed * 120);
}

void opcontrol() {
	static int speed;

	if (master.get_digital(DIGITAL_Y))
		speed = 100;
	else if (master.get_digital(DIGITAL_X))
		speed = -100;
	else if (speed > 0)
		speed = 25;
	else
		speed = -10;

	move(speed);
}

} // namespace wallhook
