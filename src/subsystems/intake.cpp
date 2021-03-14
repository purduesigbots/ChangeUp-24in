#include "main.h"

namespace intake {

okapi::MotorGroup motors = {7, -8};

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

	if (master.get_digital(DIGITAL_R1)) // intake
		speed = 100;
	else if (master.get_digital(DIGITAL_R2)) // run intake motors out
		speed = -100;
	else
		speed = 0;

	move(speed);
}

} // namespace intake
