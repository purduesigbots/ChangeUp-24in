#include "ARMS/chassis.h"
#include "macros.hpp"
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "pros/adi.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "subsystems/ejector.hpp"
#include "subsystems/indexer.hpp"
#include "subsystems/intake.hpp"
#include "subsystems/sensors.hpp"
#include "subsystems/wings.hpp"

void red() {

	// Store timestamp at beginning of auton for use in last section
	int start = millis();

	// Start Intake
	indexer::move(50);
	ejector::move(50);
	intake::move(100);
	wallhook::move(-5);

	// Move to intake 1st auton line ball
	chassis::move(50, 100);

	// Reverse, turn, and push red into middle goal
	chassis::move(-8, 40);
	runUntilFull();
	ejector::move(0);
	chassis::turnAbsolute(90);
	intake::move(0);
	wings::toggle();
	chassis::move(34, 70);

	// Turn and align with home row goal
	chassis::move(-5);
	wings::toggle();
	chassis::turnAbsolute(150);
	chassis::move(24, 50);
	chassis::turnAbsolute(180);
	intake::move(0);
	chassis::move(22, 50);

	// Score in home row
	score();

	// Move to intake 2nd ball
	chassis::move(-8, 60);
	intake::move(100);
	runUntilFull();
	chassis::turnAbsolute(-90);
	chassis::move(52, 60);

	// Align with corner goal
	chassis::turnAbsolute(-144, 70);

	// Score 3 in corner goal
	chassis::move(27, 35);
	runUntilFull();
	score(3);
	intake::move(0);
	delay(500);

	// Reverse and eject blue
	chassis::move(-30, 40);
	flywheel::move(-100);
	indexer::move(-100);
	intake::move(-70);
	delay(500);
	flywheel::move(0);
	indexer::move(0);
	intake::move(0);

	// Move to center
	chassis::turnAbsoluteAsync(89);
	delay(1500);
	chassis::waitUntilSettled();
	wallAlignTo(24);
	while ((millis() - start) <= 31000)
		delay(10);
	chassis::move(44.5, 50);
	intake::move(100);
	indexer::move(50);
	startFilter();
	chassis::turnAbsolute(-1);
	chassis::move(48, 40);
	chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

	// run cycle macro
	bool done = false;
	while ((millis() - start) <= 42500) {
		if (sensors::colorDetect(true) && !done) {
			endFilter();
			runUntilFull();
			done = true;
			ejector::move(-100);
			indexer::move(50);
			intake::move(100);
		}
		delay(10);
	}
	score(1);
	intake::move(0);
	ejector::move(0);

	// Reverse off of goal
	chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
	chassis::move(-7);
}
