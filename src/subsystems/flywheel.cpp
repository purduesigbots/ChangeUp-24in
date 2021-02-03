#include "main.h"

namespace flywheel {

okapi::MotorGroup motors = {3, -6};

void init() {
	motors.setGearing(okapi::AbstractMotor::gearset::green);
	motors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motors.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
}

void move(int speed) {
	motors.moveVoltage(speed * 120);
}

void opcontrol() {
	static int speed;
	if (master.get_digital(DIGITAL_L1)) // score
		speed = 100;
	else
		speed = 0;

	move(speed);
}

} // namespace flywheel
