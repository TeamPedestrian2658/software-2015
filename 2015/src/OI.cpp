#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

OI::OI() {
	operatorStick = new Joystick(1);
	
	driverStick = new Joystick(0);
}

Joystick* OI::getOperatorStick() {
	return operatorStick;
}

Joystick* OI::getDriverStick() {
	return driverStick;
}
