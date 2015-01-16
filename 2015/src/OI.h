#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* operatorStick;
	Joystick* driverStick;

	JoystickButton* driveShifter;
public:
	OI();
 
	Joystick* getDriverStick();
	Joystick* getOperatorStick();
};

#endif
