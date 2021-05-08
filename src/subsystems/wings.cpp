#include "main.h"

namespace wings {

ADIDigitalOut piston('g');
bool currVal = false;

void toggle() {
	currVal = !currVal;
	piston.set_value(currVal);
}

} // namespace wings
