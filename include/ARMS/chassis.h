#ifndef _CHASSIS_H_
#define _CHASSIS_H_

#include "ARMS/config.h"
#include "okapi/api.hpp"

namespace chassis {

extern bool useVelocity;

/**
 * Set the brake mode for all chassis motors
 */
void setBrakeMode(okapi::AbstractMotor::brakeMode b);

/**
 * Reset the internal motor encoders for all chassis motors
 */
void reset();

/**
 * Get the average position between the sides of the chassis
 */
double position(bool yDirection = false, bool forceEncoder = false);

/**
 * Get a boolean that is true if the chassis motors are in motion
 */
bool settled();

/**
 * Delay the program until the chassis motors come to rest
 */
void waitUntilSettled();

/**
 * Begin an asycronous chassis movement
 */
void moveAsync(double sp, int max = 100);

/**
 * Begin an asycronous turn movement
 */
void turnAsync(double sp, int max = 100);

/**
 * Begin an asycronous absolute turn movement (only works with IMU)
 */
void turnAbsoluteAsync(double sp, int max = 100);

/**
 * Begin an asycronous holonomic chassis movement
 */
void moveAsync(double distance, double angle, int max = 100);

/**
 * Perform a chassis movement and wait until settled
 */
void move(double sp, int max = 100);

/**
 * Perform a turn movement and wait until settled
 */
void turn(double sp, int max = 100);

/**
 * Perform an absolute turn movement and wait until settled (only works with
 * IMU)
 */
void turnAbsolute(double sp, int max = 100);

/**
 * Perform a holonomic movement and wait until settled
 */
void moveHolo(double distance, double angle, int max = 100);

/**
 * Move a distance at a set voltage with no PID
 */
void fast(double sp, int max = 100);

/**
 * Move for a duration at a set voltage with no PID
 */
void voltage(int t, int left_speed = 100, int right_speed = 0);

/**
 * Move for a duration at a set velocity using internal PID
 */
void velocity(int t, int max = 100);

/**
 * Move the robot in an arc with a set length, radius, and speed
 */
void arcLeft(int length, double rad, int max = 100, int type = 0);

/**
 * Move the robot in an arc with a set length, radius, and speed
 */
void arcRight(int length, double rad, int max = 100, int type = 0);

/**
 * Preform a forward S shaped movement with a set length, and speed
 */
void sLeft(int arc1, int mid, int arc2, int max = 100);

/**
 * Preform a forward S shaped movement with a set length, and speed
 */
void sRight(int arc1, int mid, int arc2, int max = 100);

/**
 * Preform a backward S shaped movement with a set length, and speed
 */
void _sLeft(int arc1, int mid, int arc2, int max = 100);

/**
 * Preform a backward S shaped movement with a set length, and speed
 */
void _sRight(int arc1, int mid, int arc2, int max = 100);

/**
 * Assign a voltage to each motor on a scale of -100 to 100
 */
void tank(int left, int right);

/**
 * Assign a voltage to each motor on a scale of -100 to 100
 */
void arcade(int vertical, int horizontal);

/**
 * Assign a voltage to each motor on a scale of -100 to 100
 */
void holonomic(int x, int y, int z);

/**
 * initialize the chassis
 */
void init(std::initializer_list<okapi::Motor> leftMotors = {LEFT_MOTORS},
          std::initializer_list<okapi::Motor> rightMotors = {RIGHT_MOTORS},
          int gearset = GEARSET, double distance_constant = DISTANCE_CONSTANT,
          double degree_constant = DEGREE_CONSTANT,
          double accel_step = ACCEL_STEP, double arc_step = ARC_STEP,
          double linearKP = LINEAR_KP, double linearKD = LINEAR_KD,
          double turnKP = TURN_KP, double turnKD = TURN_KD,
          double arcKP = ARC_KP, double difKP = DIF_KP, int imuPort = IMU_PORT,
          std::tuple<int, int, int> encoderPorts = {ENCODER_PORTS},
          int expanderPort = EXPANDER_PORT);

} // namespace chassis

#endif
