#include "main.h"

namespace indexer {

okapi::MotorGroup motors = {-4, 9};
ADIAnalogIn line_sensor('b');

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
	static bool detected = false;

	if (master.get_digital_new_press(DIGITAL_R1))
		detected = false;

	if (master.get_digital(DIGITAL_L1)) // score ball
		speed = 100;
	else if (master.get_digital(DIGITAL_L2)) // outtake
		speed = 100;
	else if (master.get_digital(DIGITAL_R1)) { // run until dectected
		if (line_sensor.get_value() > 2850 && detected == false)
			speed = 50;
		else {
			detected = true;
			speed = 0;
		}
	} else
		speed = 0;

	move(speed);
}

} // namespace indexer
