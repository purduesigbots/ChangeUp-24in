#include "main.h"

namespace ejector {

okapi::MotorGroup motor = {2};
int speed = 0;

void init() {
	motor.setGearing(okapi::AbstractMotor::gearset::green);
	motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motor.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
}

void move(int speed) {
	ejector::speed = speed;
	motor.moveVoltage(speed * 120);
}

} // namespace ejector
