#include "macros.hpp"
#include "main.h"

void blue() {
	// chassis::turnAbsoluteAsync(90);
	int current = 1;
	double increments[3] = {.01, .1, 1};
	int index = 0;
	bool active;
	while (1) {
		// get current pid values
		double pids[3] = {pid::angularKP, pid::angularKI, pid::angularKD};

		// activation logic
		if (master.get_digital_new_press(DIGITAL_LEFT)) {
			if (!active) {
				chassis::turnAbsoluteAsync(0);
				active = true;
			} else {
				chassis::tank(0, 0);
				active = false;
			}
		}

		// selection logic
		if (master.get_digital_new_press(DIGITAL_RIGHT))
			current++;
		if (current > 2)
			current = 0;

		// index control
		if (master.get_digital_new_press(DIGITAL_A))
			index++;
		if (index > 2)
			index = 0;

		// increment
		double inc = increments[index];

		if (current == 1)
			inc /= 100;

		if (master.get_digital_new_press(DIGITAL_UP))
			pids[current] += inc;
		if (master.get_digital_new_press(DIGITAL_DOWN))
			pids[current] -= inc;

		// debug
		printf("KP: %.2f, KI: %.4f, KD: %.2f, cur: %d, inc:%.2f, ang:%.2f\n",
		       pids[0], pids[1], pids[2], current + 1, increments[index],
		       chassis::angle());

		// asign vals
		pid::angularKP = pids[0];
		pid::angularKI = pids[1];
		pid::angularKD = pids[2];
		delay(50);
	}
}
