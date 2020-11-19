#include "ARMS/chassis.h"
#include "macros.hpp"
#include "main.h"

void red() {
	// Start Intake
	intake::move(100);

	// Move to intake 1st auton line ball
	// chassis::fast(40);
	chassis::move(54, 65);

	// Backup and align with 2nd auton line ball
	chassis::move(-19, 50);
	chassis::turn(-53);

	// Move to intake 2nd ball
	chassis::move(27, 65);
	delay(100);
	runUntilFull();

	// Align corner goal
	chassis::move(-30, 65);
	chassis::turn(-90);
	intake::move(0);
	chassis::move(42, 65);
	chassis::voltage(600, 60);
	score();
	chassis::move(-38, 65);
	chassis::turn(-90, 70);

	// Move to intake ball in front of goal
	intake::move(100);
	runUntilFull();
	chassis::move(40, 50);
	delay(1000);
	intake::move(0);
	// Score first 2 balls
	chassis::move(39, 15);
	intake::move(100);
	score();
	delay(1000);
	score();
	delay(1000);
	intake::move(0);
	score();
	chassis::move(-30, 40);
	intake::move(-60);
	indexer::move(-60);
	delay(400);
	intake::move(0);
	indexer::move(0);
	delay(100);
	intake::move(100);
	runUntilFull();
	intake::move(0);
	chassis::turnAbsolute(90);
	delay(300);
	chassis::move(-41, 80);
	chassis::turnAbsolute(0);
	delay(300);
	chassis::move(36, 60);
	score();

	intake::move(100);
	while (!sensors::colorDetect(true)) {
		ejector::move(-100);
		indexer::move(100);
		delay(10);
	}
	ejector::move(-100);
	indexer::move(100);
	intake::move(0);

	score();
}
