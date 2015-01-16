#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

class RobotMap {
public:
	static SendableChooser *autoChooser;

	static Talon *driveTalonLeft;
	static Talon *driveTalonRight;

	static Solenoid *driveShifterLeft;
	static Solenoid *driveShifterRight;

	static PIDEncoder *driveEncoderLeft;
	static PIDEncoder *driveEncoderRight;

	static PIDController *driveControllerLeft;
	static PIDController *driveControllerRight;

	static SendableChooser *driveChooser;

	static void init();
};
#endif
