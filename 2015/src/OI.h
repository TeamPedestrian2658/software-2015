#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Commands/ShiftHigh.h"
#include "Commands/ShiftLow.h"
#include "Commands/ToggleEnhancedDriving.h"
#include "Commands/EnableSlow.h"
#include "Commands/DisableSlow.h"

class OI {
private:
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
