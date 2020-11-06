#include "main.h"

namespace transmission {

ADIDigitalOut piston('a');

void toggle() {
	static bool currVal = false;
	currVal = !currVal;
	piston.set_value(currVal);
}

void opcontrol() {
	if (master.get_digital_new_press(DIGITAL_A))
		toggle();
}

} // namespace transmission
