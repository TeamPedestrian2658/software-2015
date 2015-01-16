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
public:
	OI();
 
	Joystick* getDriverStick();
	Joystick* getOperatorStick();
};

#endif
