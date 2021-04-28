#include "ARMS/chassis.h"
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

		if (sensors::colorDetect()) {
			break;
		}
	}
	indexer::move(0);
	delay(200);
	ejector::move(0);
	flywheel::move(0);
}

void wallAlignTo(double target) {
	int c = 0;

	double prevError = 0;
	double totalError = 0;

	while (1) {
		double error = target - sensors::getUltrasonicDist();

		if (abs(error) < 5) {
			totalError += error;
		} else {
			totalError = 0;
		}

		if (error * prevError < 0) {
			totalError = 0;
		}

		double speed = error * 3 + (error - prevError) * 12 + totalError * 0.01;

		chassis::tank(speed, speed);

		if (abs(error) < 2) {
			c += 10;
			if (c > 300)
				break;
		} else {
			c = 0;
		}

		delay(10);

		prevError = error;
	}
}
