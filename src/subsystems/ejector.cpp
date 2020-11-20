#include "main.h"

namespace ejector {

okapi::MotorGroup motor = {2};

void init() {
	motor.setGearing(okapi::AbstractMotor::gearset::green);
	motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motor.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
}

void move(int speed) {
	motor.moveVoltage(speed * 120);
}

void opcontrol() {
	static int speed;
	if (master.get_digital(DIGITAL_L2) || sensors::colorDetect()) // outtake
		speed = -100;
	else if (master.get_digital(DIGITAL_L1)) // score
		speed = 100;
	else if (master.get_digital(DIGITAL_R1) && !sensors::lineDetect()) {
		speed = 50;
	} else
		speed = 0;

	move(speed);
} // namespace ejector

} // namespace ejector
