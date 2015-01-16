#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

OI::OI() {
	operatorStick = new Joystick(1);
	driverStick = new Joystick(0);
	
	driveShifter = new JoystickButton(driverStick, 0);
	driveShifter->WhenPressed(new ShiftHigh());
	driveShifter->WhenReleased(new ShiftLow());

	driveEnhance = new JoystickButton(driverStick, 1);
	driveEnhance->WhenPressed(new ToggleEnhancedDriving());

	driveSlow = new JoystickButton(driverStick, 2);
	driveSlow->WhenPressed(new EnableSlow());
	driveSlow->WhenReleased(new DisableSlow());

}

Joystick* OI::getOperatorStick() {
	return operatorStick;
}

Joystick* OI::getDriverStick() {
	return driverStick;
}
