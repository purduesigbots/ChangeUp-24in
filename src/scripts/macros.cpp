#include "main.h"
#include "subsystems/sensors.hpp"

void runUntilFull() {
	while (!sensors::flywheelDetect()) {
		indexer::move(100);
	}
	indexer::move(0);
}

void score(int num) {
	int i = 0;
	bool detected = sensors::flywheelDetect();

	flywheel::move(100);
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
	delay(200);
	ejector::move(0);
	flywheel::move(0);
}
