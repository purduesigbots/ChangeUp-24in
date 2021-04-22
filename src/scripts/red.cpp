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
	intake::move(100);

	// Move to intake 1st auton line ball
	chassis::move(48, 60);

	// Reverse, turn, and push red into middle goal
	chassis::move(-8, 40);
	runUntilFull();
	chassis::turnAbsolute(90);
	intake::move(0);
	wings::toggle();
	chassis::move(32, 70);
	wings::toggle();

	// Turn and align with home row goal
	chassis::move(-2);
	chassis::turnAbsolute(150);
	chassis::move(26, 50);
	chassis::turnAbsolute(180);
	intake::move(0);
	chassis::move(18, 50);

	// Score in home row
	score();

	// Move to intake 2nd ball
	chassis::move(-8, 60);
	intake::move(100);
	runUntilFull();
	chassis::turnAbsolute(-90);
	chassis::move(52, 60);

	// Align with corner goal
	chassis::turnAbsolute(-140, 70);

	// Score 3 in corner goal
	chassis::move(30, 50);
	score(3);
	intake::move(0);

	// Reverse and eject blue
	chassis::move(-40, 40);
	flywheel::move(-100);
	indexer::move(-100);
	intake::move(-70);
	delay(500);
	flywheel::move(0);
	indexer::move(0);
	intake::move(0);

	// Move to center
	chassis::turnAbsolute(90, 50);
	wallAlignTo(24);
	chassis::move(51, 50);
	intake::move(100);
	chassis::turnAbsolute(0);
	chassis::move(32);
	transmission::toggle();
	chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

	// Make sure center is red or neutral
	while (!sensors::colorDetect(true)) {
		indexer::move(100);
		ejector::move(-100);
		delay(10);
	}
	ejector::move(100);
	runUntilFull();
	score(1);

	// Delay until 1.5 s left in auton
	intake::move(0);
	indexer::move(0);
	ejector::move(0);
	while (millis() - start < 43500)
		delay(10);

	// Reverse off of goal
	chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
	transmission::toggle();
	chassis::move(-24);
}
