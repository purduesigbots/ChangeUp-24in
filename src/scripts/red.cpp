#include "main.h"

void red() {
	// Start Intake
	intake::move(100);
	// Move with fast and slow movement
	chassis::fast(40, 55);
	chassis::move(21, 65);
	// Backup & Turn
	chassis::move(-20, 50);
	chassis::turn(-68, 50);
	// Move to intake ball on center line
	chassis::move(29, 65);
	delay(100);
	indexer::runUntilFull();
	chassis::move(-30, 65);
	chassis::turn(-181, 35);
	delay(500);
	chassis::fast(26, 50);
	delay(100);
	chassis::fast(3, 50);
	indexer::score(2);
	intake::move(0);
	chassis::fast(-6, 30);
	delay(100);
	intake::move(100);
	chassis::move(8, 30);
	delay(300);
	intake::move(0);
	indexer::score();
	delay(500);
	chassis::move(-20, 50);
	intake::move(80);
	delay(200);
	intake::move(-100);
	ejector::move(-100);
	indexer::move(-100);
	delay(400);
	intake::move(0);
	ejector::move(0);
	indexer::move(0);
	delay(100);
	chassis::turn(178, 50);
	chassis::move(50, 80);
}
