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

	// Move to intake 1st auton line ball
	chassis::move(48, 60);

	// Reverse, turn, and push red into middle goal
	chassis::move(-8, 40);
	runUntilFull();
	ejector::move(0);
	chassis::turnAbsolute(90);
	intake::move(0);
	wings::toggle();
	chassis::move(30, 70);
	wings::toggle();

	// Turn and align with home row goal
	chassis::move(-2);
	chassis::turnAbsolute(150);
	chassis::move(23, 50);
	chassis::turnAbsolute(180);
	intake::move(0);
	chassis::move(22, 50);

	// Score in home row
	score();

	// Move to intake 2nd ball
	chassis::move(-6, 60);
	intake::move(100);
	runUntilFull();
	chassis::turnAbsolute(-90);
	chassis::move(52, 60);

	// Align with corner goal
	chassis::turnAbsolute(-140, 70);

	// Score 3 in corner goal
	chassis::move(30, 50);
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
	chassis::turnAbsolute(90, 50);
	wallAlignTo(24);
	chassis::move(48, 50);
	intake::move(100);
	ejector::move(-100);
	indexer::move(50);
	chassis::turnAbsolute(2);
	chassis::move(48, 40);
	transmission::toggle();
	chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

	// Make sure center is red or neutral
	while (!sensors::colorDetect(true)) {
		ejector::move(-100);
		indexer::move(50);
		delay(10);
		if ((millis() - start) >= 43500) {
			ejector::move(0);
			indexer::move(0);
			intake::move(0);
			chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
			transmission::toggle();
			chassis::move(-18);
			return;
		}
	}
	indexer::move(100);
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
	chassis::move(-18);
}
