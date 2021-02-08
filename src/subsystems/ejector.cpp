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
	static bool eject;

	if (sensors::colorDetect())
		eject = true;
	else if (sensors::ejectDetect())
		eject = false;

	if (master.get_digital(DIGITAL_L2)) {
		speed = -100;
	} else if (eject) {
		speed = -100;
	} else if (master.get_digital(DIGITAL_L1)) {
		speed = 100;
	} else if (master.get_digital(DIGITAL_R1) && !sensors::flywheelDetect()) {
		speed = 50;
	} else {
		speed = 0;
	}

	move(speed);
}

} // namespace ejector
