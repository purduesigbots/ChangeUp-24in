#include "main.h"

void runUntilFull() {
	while (sensors::lineDetect()) {
		indexer::move(100);
	}
	indexer::move(0);
}

void score(int num) {
	int i = 0;
	while (i < num) {
		runUntilFull();
		while (sensors::lineDetect()) {
			ejector::move(100);
			indexer::move(100);
		}
		delay(500);
		ejector::move(0);
		indexer::move(0);
		i += 1;
	}
}
