#include "macros.hpp"
#include "main.h"

void red() {
	// Start Intake
	intake::move(100);

	// Move to intake 1st auton line ball
	chassis::fast(40);
	chassis::move(15, 65);

	// Backup and align with 2nd auton line ball
	chassis::move(-19, 50);
	chassis::turn(-47, 90);

	// Move to intake 2nd ball
	chassis::move(23, 65);
	delay(100);
	runUntilFull();

	// Align corner goal
	chassis::move(-30, 65);
	chassis::turn(-170, 70);
	delay(500);

	// Move to intake ball in front of goal
	chassis::move(28, 50);
	delay(100);

	// Score first 2 balls
	chassis::move(8, 80);
	chassis::moveAsync(10, 10);
	score();
	intake::move(0);

	// Reverse to let balls drop down
	chassis::move(-8, 30);
	delay(100);
	intake::move(100);
	indexer::move(100);
	delay(600);

	// Score 3rd ball
	chassis::move(12, 30);
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
}
