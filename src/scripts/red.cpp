#include "ARMS/chassis.h"
#include "macros.hpp"
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "pros/adi.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "subsystems/ejector.hpp"
#include "subsystems/flywheel.hpp"
#include "subsystems/indexer.hpp"
#include "subsystems/intake.hpp"
#include "subsystems/sensors.hpp"
#include "subsystems/wings.hpp"

void red1() {

	// Store timestamp at beginning of auton for use in last section
	int start = millis();
	chassis::resetAngle();

	// Start Intake
	indexer::move(40);
	ejector::move(50);
	intake::move(100);
	wallhook::move(-5);

	// Move to intake 1st auton line ball
	chassis::move(41, 100);

	// Intake 2nd line ball
	chassis::turnAbsolute(68);
	chassis::move(20, 50);

	// Turn and align with home row goal
	chassis::move(-10);
	chassis::turnAbsolute(130);
	chassis::move(42, 50);
	chassis::turnAbsolute(180);
	intake::move(100);
	chassis::move(21, 50);

	// Score in home row
	chassis::tank(30, 30);
	score(3);
	intake::move(0);
	flywheel::move(0);
	delay(500);

	// back out of middle goal
	chassis::move(-8, 60);

	// turn and eject blue
	runUntilFull();
	chassis::turnAbsolute(-90);
	indexer::move(100);
	ejector::move(-80);
	intake::move(100);
	delay(500);
	indexer::move(0);
	ejector::move(0);
	intake::move(0);

	// Align with corner goal
	chassis::move(51, 60);
	chassis::turnAbsolute(-144, 70);
	intake::move(100);

	// Score 3 in corner goal
	chassis::move(27, 35);
	chassis::tank(30, 30);
	runUntilFull();
	score(3);
	intake::move(0);
	delay(500);

	// Reverse and eject blue
	intake::move(-50);
	chassis::move(-20, 40);
	flywheel::move(-100);
	indexer::move(-100);
	intake::move(-70);
	delay(500);
	flywheel::move(0);
	indexer::move(0);
	intake::move(0);

	// Move to center
	chassis::turnAbsoluteAsync(84);
	delay(1500);
	chassis::waitUntilSettled();
	chassis::move(52, 50);

	// wait until 35 seconds
	int del = 35000 - (millis() - start);
	delay(del < 0 ? 0 : del);
	intake::move(100);
	indexer::move(50);
	ejector::move(-100);
	chassis::turnAbsolute(-1.5);
	chassis::move(55, 40);
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

void red2() {

	// Store timestamp at beginning of auton for use in last section
	int start = millis();
	chassis::resetAngle();

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
	intake::move(-20);
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

void redWall() {
	// Store timestamp at beginning of auton for use in last section
	int start = millis();
	chassis::resetAngle();

	// Start Intake
	indexer::move(40);
	ejector::move(50);
	intake::move(100);
	wallhook::move(-5);

	// Move to intake 1st auton line ball
	chassis::move(42, 100);

	// Intake 2nd line ball
	chassis::move(-8, 40);
	runUntilFull();
	indexer::move(50);
	ejector::move(0);
	chassis::turnAbsolute(58);
	chassis::move(24, 50);
	intake::move(0);

	// Turn and align with home row goal
	chassis::move(-10);
	chassis::turnAbsolute(130);
	chassis::move(38.5, 50);
	chassis::turnAbsolute(180);
	intake::move(100);
	chassis::move(21, 50);

	// Score in home row
	runUntilFull();
	score(3);
	intake::move(0);
	delay(500);

	// back out of middle goal
	chassis::turnAbsolute(180);
	chassis::move(-8, 60);
	chassis::turnAbsolute(180);

	// turn and eject blue
	runUntilFull();
	chassis::turnAbsolute(-65);
	indexer::move(-25);
	ejector::move(-25);
	intake::move(-75);
	delay(200);
	indexer::move(0);
	ejector::move(0);
	delay(200);
	intake::move(0);
	delay(500);
	chassis::turnAbsolute(-95);
	runUntilFull();

	// Align with corner goal
	chassis::move(47, 60);
	chassis::turnAbsolute(-144, 70);
	intake::move(100);

	// Score 3 in corner goal
	chassis::move(27, 35);
	chassis::tank(30, 30);
	runUntilFull();
	score(3);
	intake::move(0);
	delay(500);

	// Reverse and eject blue

	chassis::move(-15, 40);
	chassis::turnAbsolute(-60, 50);
	flywheel::move(-100);
	indexer::move(-100);
	intake::move(-70);
	delay(500);
	flywheel::move(0);
	indexer::move(0);
	intake::move(0);

	// Move to center
	chassis::turnAbsoluteAsync(89, 50);
	delay(1500);
	chassis::waitUntilSettled();
	// wallAlignTo(24);
	// delay(500);
	// chassis::move(44.5, 50);
	chassis::move(69.5 - sensors::getUltrasonicDist(), 50);

	// wait until 35 seconds
	// int del = 35000 - (millis() - start);
	// delay(del < 0 ? 0 : del);
	intake::move(100);
	indexer::move(50);
	ejector::move(-100);
	chassis::turnAbsolute(-1);
	chassis::move(48, 40);
	chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

	wallhook::move(100);
	delay(200);
	chassis::arcade(-100, 0);
	delay(500);
	chassis::arcade(100, 0);
	delay(200);
	wallhook::move(0);
	delay(150);
}
