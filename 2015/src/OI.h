#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Utilities/Constants.h"

class OI {
private:

	Constants *constants;

	Joystick *operatorStick;
	Joystick *driverStick;

	JoystickButton *driveShifter;
	JoystickButton *driveEnhance;
	JoystickButton *driveSlow;

	JoystickButton *compressorOn;
	JoystickButton *compressorOff;

	JoystickButton *lowerClawToggleGrab;
	JoystickButton *lowerClawToggleGrabLeft;
	JoystickButton *lowerClawToggleGrabRight;

	JoystickButton *upperClawToggleGrab;

	JoystickButton *toggleLiftAutomatic;

	JoystickButton *incrementItemCount;
	JoystickButton *decrementItemCount;
	JoystickButton *resetItemCount;

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
