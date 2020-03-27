#include "main.h"

namespace intake {

okapi::MotorGroup motors = {5, -6};

std::shared_ptr<okapi::AsyncPositionController<double, double>> controller =
    okapi::AsyncPosControllerBuilder().withMotor(motors).withGains({0.001, 0}).build();

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

	if (master.get_digital(DIGITAL_R1))
		speed = 100;
	else if (master.get_digital(DIGITAL_R2))
		speed = -100;
	else
		speed = 0;

	arcade(controller.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
	       controller.get_analog(ANALOG_LEFT_X) * (double)100 / 127);

	move(speed);
}

} // namespace intake
