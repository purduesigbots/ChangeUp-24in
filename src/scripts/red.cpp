#include "main.h"
#include "pros/rtos.hpp"

void red() {
	// Start Intake
	intake::move(100);
	// Move with fast and slow movement
	chassis::fast(38, 55);
	chassis::move(23, 50);
	// Backup & Turn
	chassis::move(-20, 50);
	chassis::turn(-57);
	// Move to intake ball on center line
	chassis::move(20, 50);
}
