#include "ARMS/chassis.h"
#include "main.h"
#include "subsystems/sensors.hpp"

bool filtering = false;

void runUntilFull() {
	int c = 0;
	while (!sensors::flywheelDetect()) {
		indexer::move(100);
		delay(10);
		c += 10;
		if (c > 1000) {
			break;
		}
	}
	indexer::move(0);
}

void score(int num) {
	int c = 0;
	int i = 0;
	bool detected = sensors::flywheelDetect();

	flywheel::move(80);
	ejector::move(100);
	indexer::move(100);

	while (i < num && c < 1500) {
		delay(10);
		c += 10;
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
	delay(100);
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

		double speed = error * 3 + (error - prevError) * 14 + totalError * 0.03;

		int min = 5;
		if (abs(speed) < min) {
			if (speed < 0)
				speed = -min;
			else
				speed = min;
		}

		if (fabs(error) < .5) {
			if (fabs(error) < .5)
				speed = 0;
			c += 10;
			if (c > 300)
				break;
		} else {
			c = 0;
		}

		chassis::tank(speed, speed);

		delay(10);

		prevError = error;
	}
}

void filter() {
	bool eject = false;
	int c = 0;
	while (filtering) {
		if (sensors::colorDetect()) {
			c = 0;
			eject = true;
		}

		if (c > 100 && eject) {
			eject = false;
			c = 0;
		}

		if (eject) {
			ejector::move(-100);
			c += 10;
		} else {
			ejector::move(100);
		}

		delay(10);
	}
}

void startFilter() {
	filtering = true;
	Task filterTask(filter);
}

void endFilter() {
	filtering = false;
}
