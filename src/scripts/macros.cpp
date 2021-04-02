#include "main.h"
#include "subsystems/sensors.hpp"

void runUntilFull() {
	int c = 0;
	while (!sensors::flywheelDetect()) {
		indexer::move(100);
		delay(10);
		c += 10;
		if (c > 2000) {
			break;
		}
	}
	indexer::move(0);
}

void score(int num) {
	int i = 0;
	bool detected = sensors::flywheelDetect();

	flywheel::move(80);
	ejector::move(100);
	indexer::move(100);

	while (i < num) {
		delay(10);
		if (sensors::flywheelDetect()) {
			if (!detected)
				detected = true;
		} else {
			if (detected) {
				detected = false;
				i += 1;
			}
		}
	}
	indexer::move(0);
	delay(100);
	ejector::move(0);
	flywheel::move(0);
}
