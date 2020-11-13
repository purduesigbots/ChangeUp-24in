#ifndef _CONFIG_H_
#define _CONFIG_H_

// Drivetrain configuration constants
namespace chassis {

// negative numbers mean reversed motor
#define LEFT_MOTORS 1, 2
#define RIGHT_MOTORS -3, -4
#define GEARSET 200 // rpm of chassis motors

#define DISTANCE_CONSTANT 51 // ticks per distance unit, the default is a inch
#define DEGREE_CONSTANT 5.9  // ticks per degree

// chassis settling constants
#define SETTLE_COUNT 8
#define SETTLE_THRESHOLD_LINEAR 3
#define SETTLE_THRESHOLD_ANGULAR 1

// slew control (autonomous only)
#define ACCEL_STEP 8    // smaller number = more slew
#define DECCEL_STEP 200 // 200 = no slew
#define ARC_STEP 2      // acceleration for arcs
#define MIN_SPEED 15

// pid constants
#define LINEAR_KP .3
#define LINEAR_KD .5
#define TURN_KP 1
#define TURN_KD 2
#define ARC_KP .05
#define DIF_KP .5

// sensors
#define IMU_PORT 16           // port 0 for disabled
#define ENCODER_PORTS 0, 0, 0 // port 0 for disabled
#define EXPANDER_PORT 0

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
