#include "main.h"

void skills() {

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
