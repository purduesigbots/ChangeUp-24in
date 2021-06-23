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

	// initialize autons
	const char* b[] = {"Main", "Old", ""};
	selector::init(50, 1, b);

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

	// Ziegler-Nichols method PID tuning

	pid::init(false,           // debug output
	          .15, 0, 1.5,     // linear constants
	          4.1, 0.0013, 41, // angular contants
	          4, 0, 0,         // linear point constants
	          50, 0, 0,        // angular point constants
	          .05,             // arc kp
	          1.2,             // dif kp
	          1                // min error
	);
}

void disabled() {
}

void competition_initialize() {
}

void autonomous() {
	switch (selector::auton) {
	case -1:
		blue1();
		break;
	case -2:
		blue2();
		break;
	case 1:
		red1();
		break;
	case 2:
		red2();
		break;
	case 3:
		redWall();
		break;
	case 0:
		skills();
		break;
	}
}

void opcontrol() {
	bool sorting = true;
	while (true) {
		// button to start autonomous for testing
		if (master.get_digital(DIGITAL_RIGHT) && !competition::is_connected())
			autonomous();

		// stop all subsystem motors
		intake::speed = 0;
		indexer::speed = 0;
		flywheel::speed = 0;
		ejector::speed = 0;

		// intake
		if (master.get_digital(DIGITAL_R1)) {
			intake::speed = 100;
			indexer::speed = 50;
			if (!sensors::flywheelDetect())
				ejector::speed = 50; // stop ejector when bot full
		}

		// outtake
		if (master.get_digital(DIGITAL_R2)) {
			intake::speed = -100;
		}

		// score
		if (master.get_digital(DIGITAL_L1)) {
			indexer::speed = 100;
			flywheel::speed = 100;
			ejector::speed = 100;
		}

		// manual eject
		if (master.get_digital(DIGITAL_L2)) {
			indexer::speed = 50;
			ejector::speed = -100;
		}

		// color sensor ejecting
		static int ejectCount = 0;
		if (sorting) {
			if (sensors::colorDetect()) {
				ejectCount = 200; // eject time 100 ms
				indexer::speed = 50;
			}
			if (ejectCount > 0) {
				ejectCount -= 10; // amount of ms passed
				ejector::speed = -100;
			}
		}

		// color sensor toggle
		if (master.get_digital_new_press(DIGITAL_DOWN))
			sorting = !sorting;

		// run indexer backwards
		if (master.get_digital(DIGITAL_LEFT))
			indexer::speed = -100;

		// run flywheel backwards
		if (master.get_digital(DIGITAL_UP))
			flywheel::speed = -100;

		// wall hook
		if (master.get_digital(DIGITAL_Y))
			wallhook::speed = 100;
		else if (master.get_digital(DIGITAL_X))
			wallhook::speed = -100;
		else if (wallhook::speed > 0)
			wallhook::speed = 25;
		else
			wallhook::speed = -10;

		// transmission
		if (master.get_digital_new_press(DIGITAL_A))
			transmission::toggle();

		// wings
		if (master.get_digital_new_press(DIGITAL_B))
			wings::toggle();

		// chassis
		chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                master.get_analog(ANALOG_RIGHT_X) * (double)100 / 127);

		// update each
		intake::move(intake::speed);
		indexer::move(indexer::speed);
		flywheel::move(flywheel::speed);
		ejector::move(ejector::speed);
		wallhook::move(wallhook::speed);

		delay(10);
	}
}
