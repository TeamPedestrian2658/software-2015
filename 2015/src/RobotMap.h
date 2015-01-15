#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

class RobotMap {
public:
	static SendableChooser *autoChooser;

	static Talon *driveLeft;
	static Talon *driveRight;

	static Solenoid *shifterLeft;
	static Solenoid *shifterRight;

	static void init();
};
#endif
