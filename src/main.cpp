#include "main.h"
#include "ARMS/chassis.h"

pros::Controller master(CONTROLLER_MASTER);

void initialize() {
	// autonomous selector library
	selector::init();
	wings::init();

	chassis::init({-17, 18, -19}, {12, -13, 14}, // motors
	              200,                           // gearset
	              41.45, 1,                      // TPU
	              12,                            // setle time
	              6, 5,                          // linear/angular thresholds
	              2, 2,                          // regular/arc slew
	              16,                            // imu port
	              {0, 0, 0},                     // encoder ports
	              0,                             // expander port
	              10                             // joystick threshold
	);

	pid::init(false,   // debug output
	          .3, .5,  // linear constants
	          2.5, 20, // angular contants
	          4, 0,    // linear point constants
	          50, 0,   // angular point constants
	          .05,     // arc kp
	          .5,      // dif kp
	          1        // min error
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
		if (master.get_digital(DIGITAL_LEFT) && !competition::is_connected())
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

		// chassis
		chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                master.get_analog(ANALOG_RIGHT_X) * (double)100 / 127);

		delay(20);
	}
}
