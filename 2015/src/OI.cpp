#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

OI::OI() {
	operatorStick = new Joystick(1);
	driverStick = new Joystick(0);
	
	driveShifter = new JoystickButton(driverStick, 0);
	driveShifter->WhenPressed(new ShiftHigh());
	driveShifter->WhenReleased(new ShiftLow());
}

Joystick* OI::getOperatorStick() {
	return operatorStick;
}

Joystick* OI::getDriverStick() {
	return driverStick;
}
