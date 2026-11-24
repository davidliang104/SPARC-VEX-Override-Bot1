#include "robot_config.hpp"

// ==========================================
// CONTROLLER
// ==========================================

pros::Controller controller(pros::E_CONTROLLER_MASTER);


// ==========================================
// DRIVE MOTORS
// ==========================================

// Replace ports and reversals with your wiring.
// Negative port numbers reverse motor direction.

pros::MotorGroup leftMotors(
	{-11, -12, 13},
	pros::MotorGearset::green
);

pros::MotorGroup rightMotors(
	{1, 2, -3},
	pros::MotorGearset::green
);


// ==========================================
// DRIVETRAIN
// ==========================================

// EXAMPLE VALUES: replace with actual measurements.

lemlib::Drivetrain drivetrain(
	&leftMotors,
	&rightMotors,
	13.375,                            // Track width (inches)
	lemlib::Omniwheel::NEW_4,   // Wheel diameter
	280,                           // Wheel RPM after gearing
	2                              // Horizontal drift
);


// ==========================================
// ODOMETRY
// ==========================================

// No IMU or tracking wheels installed yet.
// LemLib can use the drive motor encoders.

lemlib::OdomSensors sensors(
	nullptr, // Vertical tracking wheel 1
	nullptr, // Vertical tracking wheel 2
	nullptr, // Horizontal tracking wheel 1
	nullptr, // Horizontal tracking wheel 2
	nullptr  // Inertial sensor
);


// ==========================================
// PID CONTROLLERS
// ==========================================

// Initial example gains.
// These will need tuning on the actual robot.

lemlib::ControllerSettings lateralController(
	10,  // kP
	0,   // kI
	3,   // kD
	3,   // Anti-windup
	1,   // Small error range
	100, // Small error timeout
	3,   // Large error range
	500, // Large error timeout
	20   // Slew
);

lemlib::ControllerSettings angularController(
	2,   // kP
	0,   // kI
	10,  // kD
	3,   // Anti-windup
	1,   // Small error range
	100, // Small error timeout
	3,   // Large error range
	500, // Large error timeout
	0    // Slew
);


// ==========================================
// CHASSIS
// ==========================================

lemlib::Chassis chassis(
	drivetrain,
	lateralController,
	angularController,
	sensors
);


// ==========================================
// INITIALIZATION
// ==========================================

void setupRobot() {
	pros::lcd::initialize();

	chassis.calibrate();
}