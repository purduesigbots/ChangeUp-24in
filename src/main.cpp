#include "main.h"
#include "ARMS/chassis.h"
#include "subsystems/sensors.hpp"

pros::Controller master(CONTROLLER_MASTER);

void initialize() {
	// autonomous selector library
	selector::init(360, 1);
	wings::init();

	chassis::init({-17, 18, -19}, {12, -13, 14}, // motors
	              200,                           // gearset
	              50.5, 1,                       // TPU
	              10,                            // setle time
	              1, 1,                          // linear/angular thresholds
	              8, 2,                          // regular/arc slew
	              16,                            // imu port
	              {0, 0, 0},                     // encoder ports
	              0,                             // expander port
	              10                             // joystick threshold
	);

	// Ziegler-Nichols method PID tuning

	pid::init(false,         // debug output
	          .15, 0, 1.5,   // linear constants
	          4, 0.0013, 45, // angular contants
	          4, 0, 0,       // linear point constants
	          50, 0, 0,      // angular point constants
	          .05,           // arc kp
	          1.2,           // dif kp
	          1              // min error
	);

	sensors::init();
	intake::init();
	indexer::init();
	ejector::init();
	flywheel::init();
}

void disabled() {
}

void competition_initialize() {
}

void autonomous() {
	switch (selector::auton) {
	case -1:
		blue();
		break;
	case 1:
		red();
		break;
	case 0:
		skills();
		break;
	}
}

void opcontrol() {
	while (true) {
		// button to start autonomous for testing
		if (master.get_digital(DIGITAL_RIGHT) && !competition::is_connected())
			autonomous();

		// intake
		intake::opcontrol();

		// ejector
		ejector::opcontrol();

		// flywheel
		flywheel::opcontrol();

		// indexer
		indexer::opcontrol();

		// transmission
		transmission::opcontrol();

		// wings
		wings::opcontrol();

		// wallhook
		wallhook::opcontrol();

		// chassis
		chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                master.get_analog(ANALOG_RIGHT_X) * (double)100 / 127);

		delay(20);
		// printf("%lf\n", sensors::getUltrasonicDist());
	}
}
