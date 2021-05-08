#include "main.h"

namespace transmission {

ADIDigitalOut piston('a');
bool currVal = false;

void toggle() {
	currVal = !currVal;
	piston.set_value(currVal);
}

} // namespace transmission
