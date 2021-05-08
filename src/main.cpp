#include "main.h"

pros::Controller master(CONTROLLER_MASTER);

void initialize() {
	// autonomous selector library
	wings::toggle(); // start wings facing up
	sensors::init();
	intake::init();
	indexer::init();
	ejector::init();
	flywheel::init();

	selector::init(360, 1);

	chassis::init({-17, 18, -19}, {12, -13, 14}, // motors
	              200,                           // gearset
	              52, 1,                         // TPU
	              10,                            // setle time
	              1, 1,                          // linear/angular thresholds
	              8, 2,                          // regular/arc slew
	              16,                            // imu port
	              {0, 0, 0},                     // encoder ports
	              0,                             // expander port
	              10                             // joystick threshold
	);

	pid::init(false,         // debug output
	          .15, 0, 1.5,   // linear constants
	          4, 0.0013, 45, // angular contants
	          4, 0, 0,       // linear point constants
	          50, 0, 0,      // angular point constants
	          .05,           // arc kp
	          1.2,           // dif kp
	          1              // min error
	);
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

		// stop all subsystem motors
		intake::move(0);
		indexer::move(0);
		flywheel::move(0);

		// intake
		if (master.get_digital(DIGITAL_R1)) {
			intake::move(100);
			indexer::move(50);
			if (!sensors::flywheelDetect())
				ejector::move(50); // stop ejector when bot full
		}

		// outtake
		if (master.get_digital(DIGITAL_R2)) {
			intake::move(-100);
		}

		// score
		if (master.get_digital(DIGITAL_L1)) {
			indexer::move(100);
			flywheel::move(100);
			ejector::move(100);
		}

		// manual eject
		if (master.get_digital(DIGITAL_L2)) {
			indexer::move(50);
			ejector::move(-100);
		}

		// color sensor ejecting
		static int ejectCount = 0;
		if (sensors::colorDetect()) {
			ejectCount = 100; // eject time 100 ms
			indexer::move(50);
		}
		if (ejectCount > 0) {
			ejectCount -= 10; // amount of ms passed
			ejector::move(-100);
		}

		// run indexer backwards
		if (master.get_digital(DIGITAL_LEFT))
			indexer::move(-100);

		// run flywheel backwards
		if (master.get_digital(DIGITAL_UP))
			flywheel::move(-100);

		// wall hook
		if (master.get_digital(DIGITAL_Y))
			wallhook::move(100);
		else if (master.get_digital(DIGITAL_X))
			wallhook::move(-100);
		else if (wallhook::speed > 0)
			wallhook::move(25);
		else
			wallhook::move(-10);

		// transmission
		if (master.get_digital_new_press(DIGITAL_A))
			transmission::toggle();

		// wings
		if (master.get_digital_new_press(DIGITAL_B))
			wings::toggle();

		// chassis
		chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                master.get_analog(ANALOG_RIGHT_X) * (double)100 / 127);

		delay(20);
	}
}
