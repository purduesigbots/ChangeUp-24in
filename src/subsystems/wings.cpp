#include "main.h"

namespace wings {

ADIDigitalOut piston1('g');
ADIDigitalOut piston2('h');

void toggle() {
	static bool currVal = false;
	currVal = !currVal;
	piston1.set_value(currVal);
	piston2.set_value(currVal);
}

void opcontrol() {
	if (master.get_digital_new_press(DIGITAL_B))
		toggle();
}

} // namespace wings
