#include "main.h"

void red() {
	// Start Intake
	intake::move(100);

	// Move to intake 1st auton line ball
	chassis::fast(40, 55);
	chassis::move(21, 65);

	// Backup and align with 2nd auton line ball
	chassis::move(-20, 50);
	chassis::turn(-68, 50);

	// Move to intake 2nd ball
	chassis::move(29, 65);
	delay(100);
	indexer::runUntilFull();

	// Align corner goal
	chassis::move(-30, 65);
	chassis::turn(-181, 35);
	delay(500);

	// Move to intake ball in front of goal
	chassis::fast(26, 50);
	delay(100);

	// Score first 2 balls
	chassis::fast(3, 50);
	indexer::score(2);
	intake::move(0);

	// Reverse to let balls drop down
	chassis::fast(-6, 30);
	delay(100);
	intake::move(100);

	// Score 3rd ball
	chassis::move(8, 30);
	delay(300);
	intake::move(0);
	indexer::score();
	delay(500);

	// Back away from goal
	chassis::move(-20, 50);
	intake::move(80);
	delay(200);

	// Outtake opponent's ball
	intake::move(-100);
	ejector::move(-100);
	indexer::move(-100);
	delay(400);
	intake::move(0);
	ejector::move(0);
	indexer::move(0);
	delay(100);

	// Align with middle goal
	chassis::turn(178, 50);
	chassis::move(50, 80);
}
