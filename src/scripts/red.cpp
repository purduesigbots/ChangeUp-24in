#include "ARMS/chassis.h"
#include "macros.hpp"
#include "main.h"

void red() {
	// Start Intake
	intake::move(100);

	// Move to intake 1st auton line ball
	chassis::fast(40);
	chassis::move(14, 65);

	// Backup and align with 2nd auton line ball
	chassis::move(-19, 50);
	chassis::turn(-47, 90);

	// Move to intake 2nd ball
	chassis::move(24, 65);
	delay(100);
	runUntilFull();

	// Align corner goal
	chassis::move(-30, 65);
	chassis::turn(-84, 70);
	intake::move(0);
	chassis::move(42, 65);
	chassis::voltage(600, 60);
	score();
	chassis::move(-42, 65);
	chassis::turn(-85, 70);

	// Move to intake ball in front of goal
	intake::move(100);
	runUntilFull();
	chassis::move(40, 50);
	delay(1000);
	intake::move(0);
	// Score first 2 balls
	chassis::moveAsync(40, 15);
	score();
	intake::move(100);
	delay(1000);
	score();
	delay(1000);
	intake::move(0);
	score();
	chassis::move(-60, 20);
	/*
	  // Reverse to let balls drop down
	  chassis::move(-8, 30);
	  delay(100);
	  intake::move(100);
	  indexer::move(100);
	  delay(600);

	  // Score 3rd ball
	  chassis::moveAsync(12, 20);
	  delay(300);
	  intake::move(0);
	  score();
	  delay(500);

	  // Back away from goal
	  chassis::move(-20, 50);
	  intake::move(80);
	  delay(200);

	  // Outtake opponent's ball
	  intake::move(-100);
	  ejector::move(-100);
	  indexer::move(-100);
	  delay(200);
	  intake::move(0);
	  ejector::move(0);
	  indexer::move(0);
	  delay(100);

	  // Align with middle goal
	  chassis::turn(178, 50);
	  chassis::move(50, 80);
	    */
}
