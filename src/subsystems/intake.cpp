#include "main.h"

namespace intake {

okapi::MotorGroup motors = {7, -8};
int speed = 0;

void init() {
	motors.setGearing(okapi::AbstractMotor::gearset::green);
	motors.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	motors.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
}

void move(int speed) {
	intake::speed = speed;
	motors.moveVoltage(speed * 120);
}

} // namespace intake
