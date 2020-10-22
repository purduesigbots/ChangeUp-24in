#include "main.h"

namespace transmission {
    ADIDigitalOut piston ('a');

    void change() {
        static bool currVal = false;
        currVal = !currVal;
        piston.set_value(currVal);
    }

    void opcontrol() {
        if (master.get_digital_new_press(DIGITAL_A))
		    change();
        
    }
}