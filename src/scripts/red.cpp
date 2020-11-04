#include "main.h"

void red() {
	// Start Intake
	intake::move(100);
	// Move with fast and slow movement
	chassis::fast(38, 55);
	chassis::move(15, 40);
	// Backup & Turn
	chassis::move(-10, 50);
	chassis::turn(-35);
}
