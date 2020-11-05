#include "ARMS/chassis.h"
#include "main.h"
#include "pros/rtos.hpp"
#include "subsystems/ejector.hpp"

void red() {
	// Start Intake
	intake::move(100);
	// Move with fast and slow movement
	chassis::fast(38, 55);
	chassis::move(23, 65);
	// Backup & Turn
	chassis::move(-20, 50);
	chassis::turn(-65);
	// Move to intake ball on center line
	chassis::move(27, 65);
	delay(100);
	ejector::move(100);
	indexer::move(100);
	delay(300);
	ejector::move(0);
	indexer::move(0);
	chassis::move(-27, 65);
	chassis::turn(-186, 50);
	delay(400);
	chassis::fast(30, 50);
	delay(100);
	ejector::move(100);
	indexer::move(100);
	chassis::fast(6, 50);
	delay(1500);
	ejector::move(0);
	indexer::move(0);
	intake::move(0);
}
