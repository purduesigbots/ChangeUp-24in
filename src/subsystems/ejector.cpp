#include "main.h"

namespace ejector {

#define EJECT_TIME 250 // in milliseconds

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
	static int count;

	// increase count with time
	if(count > 0)
		count -= 20;

	if (master.get_digital(DIGITAL_L2) || sensors::colorDetect()) {
		speed = -100;
		count = EJECT_TIME;
	}else if (count > 0) {
		speed = -100;
	}else if (master.get_digital(DIGITAL_L1)) {
		speed = 100;
	}else if (master.get_digital(DIGITAL_R1) && !sensors::lineDetect()) {
		speed = 50;
	} else {
		speed = 0;
	}

	move(speed);
}

} // namespace ejector
