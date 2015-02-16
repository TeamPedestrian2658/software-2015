#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Utilities/Constants.h"

class OI {
private:

	Constants *constants;

	Joystick* operatorStick;
	Joystick* driverStick;

	JoystickButton* driveShifter;
	JoystickButton* driveEnhance;
	JoystickButton* driveSlow;

	JoystickButton *lowerClawGrabLeft;
	JoystickButton *lowerClawGrabRight;
	JoystickButton *lowerClawReleaseLeft;
	JoystickButton *lowerClawReleaseRight;

	JoystickButton *lowerClawBrakeHold;
	JoystickButton *upperClawBrakeHold;

	JoystickButton *resetLowerClawCount;
	JoystickButton *incrementLowerClawCount;
	JoystickButton *decrementLowerClawCount;

	JoystickButton *disableLowerLiftAutomatic;
	JoystickButton *disableUpperLiftAutomatic;
public:
	OI();
 
	Joystick* getDriverStick();
	Joystick* getOperatorStick();

	double getDriverStickLeftX();
	double getDriverStickLeftY();
	double getDriverStickRightX();
	double getDriverStickRightY();

	double getOperatorStickLeftX();
	double getOperatorStickLeftY();
	double getOperatorStickRightX();
	double getOperatorStickRightY();
	double getOperatorStickPOV();
};

#endif
