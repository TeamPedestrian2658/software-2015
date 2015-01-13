#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* operatorStick;
	Joystick* driverStick;
public:
	OI();
 
	Joystick* getDriverStick();
	Joystick* getOperatorStick();
};

#endif
