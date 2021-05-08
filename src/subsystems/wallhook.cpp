#include "main.h"

namespace wallhook {

okapi::MotorGroup motors = {1};
int speed = 0;

void init() {
	motors.setGearing(okapi::AbstractMotor::gearset::red);
	motors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motors.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
}

void move(int speed) {
	wallhook::speed = speed;
	motors.moveVoltage(speed * 120);
}

} // namespace wallhook
