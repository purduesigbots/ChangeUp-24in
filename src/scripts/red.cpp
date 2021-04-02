#include "ARMS/chassis.h"
#include "macros.hpp"
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "subsystems/indexer.hpp"
#include "subsystems/wings.hpp"

void red() {
	// Store timestamp at beginning of auton for use in last section
	int start = millis();

	// Start Intake
	intake::move(100);

	// Move to intake 1st auton line ball
	chassis::move(54, 60);

	// Reverse, turn, and push red into middle goal
	chassis::move(-8, 40);
	runUntilFull();
	chassis::turnAbsolute(90);
	wings::toggle();
	chassis::move(30, 60);
	wings::toggle();

	// Turn and align with home row goal
	chassis::move(-2);
	chassis::turnAbsolute(150);
	chassis::move(30, 50);
	chassis::turnAbsolute(180);
	intake::move(0);
	chassis::move(14, 50);

	// Score in home row
	score();

	// Move to intake 2nd ball
	chassis::move(-8, 60);
	intake::move(100);
	runUntilFull();
	chassis::turnAbsolute(-90);
	chassis::move(48, 60);

	// Align with corner goal
	chassis::turnAbsolute(-140);

	// Score 3 in corner goal
	chassis::move(28, 80);
	score(3);
	chassis::move(-20);

	/*
	  // Move and turn to align with middle home row
	  chassis::move(-30, 65);
	  chassis::turn(-90);
	  intake::move(0);

	  // Move to score first ball in home row
	  chassis::move(42, 65);
	  chassis::voltage(600, 60);
	  score();
	  delay(200);

	  // Move back and align with corner goal
	  chassis::move(-38, 65);
	  chassis::turn(-90, 70);

	  // Move balls down slightly to prevent infinite loop when indexing
	  flywheel::move(-20);
	  indexer::move(-20);
	  delay(300);
	  flywheel::move(0);
	  indexer::move(0);

	  // Index to prepare for scoring
	  intake::move(100);
	  runUntilFull();
	  indexer::move(20);

	  // Move to corner goal
	  chassis::move(40, 50);
	  delay(1000);
	  intake::move(0);

	  // Move to keep pressure on goal
	  chassis::move(39, 15);

	  // Score 3 balls
	  intake::move(100);
	  score();
	  delay(1000);
	  score();
	  delay(1000);
	  intake::move(0);
	  score();

	  // Back up and eject blue ball
	  chassis::move(-30, 40);
	  intake::move(-60);
	  indexer::move(-60);
	  delay(400);
	  intake::move(0);
	  indexer::move(0);
	  delay(100);

	  // Index red ball
	  intake::move(100);
	  runUntilFull();
	  intake::move(0);

	  // Turn and back up
	  chassis::turnAbsolute(90);
	  delay(300);
	  chassis::move(-41, 80);

	  // Turn and move to align with center goal
	  chassis::turnAbsolute(0);
	  delay(300);
	  chassis::move(37, 60);

	  // Set chassis brake mode to hold to prevent pushing
	  chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

	  // Score red ball
	  score();

	  // Auto sort out blue balls until red is intaked again
	  intake::move(100);
	  flywheel::move(60);
	  ejector::move(-100);
	  indexer::move(100);
	  while (!sensors::colorDetect(true)) {
	    delay(10);
	  }
	  ejector::move(0);
	  indexer::move(0);
	  intake::move(0);

	  // Score red ball again
	  score();

	  // Delay until 1.5 s left in auton
	  while (millis() - start < 43500)
	    delay(10);

	  // Set brake mode to coast and reverse to stop robot from touching center
	  goal chassis::setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
	  chassis::move(-36);
	  */
}
