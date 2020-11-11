#include "main.h"

namespace wings {

ADIDigitalOut piston('g');

void toggle() {
	static bool currVal = false;
	currVal = !currVal;
	piston.set_value(currVal);
}

void opcontrol() {
	if (master.get_digital_new_press(DIGITAL_B))
		toggle();
}

} // namespace wings
