#ifndef _CONFIG_H_
#define _CONFIG_H_

// Drivetrain configuration constants
namespace chassis {

// negative numbers mean reversed motor
#define LEFT_MOTORS -17, 18, -19
#define RIGHT_MOTORS 12, -13, 14
#define GEARSET 200 // rpm of chassis motors

#define DISTANCE_CONSTANT 46 // ticks per distance unit, the default is a inch
#define DEGREE_CONSTANT 6.3  // ticks per degree

// slew control (autonomous only)
#define ACCEL_STEP 2    // smaller number = more slew
#define DECCEL_STEP 200 // 200 = no slew
#define ARC_STEP 2      // acceleration for arcs
#define MIN_SPEED 15

// pid constants
#define LINEAR_KP .3
#define LINEAR_KD .5
#define TURN_KP .8
#define TURN_KD 3
#define ARC_KP .05
#define DIF_KP .3

// sensors
#define IMU_PORT 0               // port 0 for disabled
#define ENCODER_PORTS 0, 0, 0, 0 // port 0 for disabled

} // namespace chassis

// Auton selector configuration constants
namespace selector {

// Color of theme from 0-359(H part of HSV)
#define HUE 360

// Default auton numbers
#define DEFAULT 1

// Names of autonomi, up to 10
#define AUTONS "Front", "Back", "Do Nothing"

} // namespace selector

#endif
