#include "main.h"

namespace ejector {

okapi::MotorGroup motors = {-1, 2};

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
	else if (master.get_digital(DIGITAL_L2)) // outtake
		speed = -100;
	else
		speed = 0;

	move(speed);
} // namespace ejector

} // namespace ejector
