#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "Utilities/Constants.h"

class RobotMap {
public:
	static Constants *constants;

	static SendableChooser *autoChooser;

	static Talon *driveTalonLeft;
	static Talon *driveTalonRight;

	static Solenoid *driveShifter;

	static Encoder *driveEncoderLeft;
	static Encoder *driveEncoderRight;

	static PIDController *driveControllerLeft;
	static PIDController *driveControllerRight;

	static SendableChooser *driveChooser;

	static void init();
};
#endif
