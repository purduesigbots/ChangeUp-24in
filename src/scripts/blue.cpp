#include "macros.hpp"
#include "main.h"

void blue() {
	// chassis::turnAbsoluteAsync(90);
	int current = 1;
	bool active = false;
	double increments[3] = {.01, .1, 1};
	int index = 0;
	while (1) {
		// get current pid values
		double pids[3] = {pid::angularKP, pid::angularKI, pid::angularKD};

		// activation logic
		if (active) {
			chassis::turnAbsoluteAsync(0);
		} else {
			chassis::tank(0, 0);
		}
		if (master.get_digital_new_press(DIGITAL_LEFT))
			active = !active;

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
		if (master.get_digital_new_press(DIGITAL_UP))
			pids[current] += increments[index];
		if (master.get_digital_new_press(DIGITAL_DOWN))
			pids[current] -= increments[index];

		// debug
		printf("KP: %.2f, KI: %.2f, KD: %.2f, cur: %d, inc:%.2f, ang:%.2f\n",
		       pids[0], pids[1], pids[2], current + 1, increments[index],
		       chassis::angle());

		// asign vals
		pid::angularKP = pids[0];
		pid::angularKI = pids[1];
		pid::angularKD = pids[2];
		delay(50);
	}
}
