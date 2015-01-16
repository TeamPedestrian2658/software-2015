#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "Commands/ShiftHigh.h"
#include "Commands/ShiftLow.h"
#include "Commands/ToggleEnhancedDriving.h"
#include "Commands/EnableSlow.h"
#include "Commands/DisableSlow.h"

OI::OI() {
	operatorStick = new Joystick(1);
	driverStick = new Joystick(0);

	driveShifter = new JoystickButton(driverStick, 6);
	driveShifter->WhenPressed(new ShiftHigh());
	driveShifter->WhenReleased(new ShiftLow());

	driveEnhance = new JoystickButton(driverStick, 8);
	driveEnhance->WhenPressed(new ToggleEnhancedDriving());

	driveSlow = new JoystickButton(driverStick, 5);
	driveSlow->WhenPressed(new EnableSlow());
	driveSlow->WhenReleased(new DisableSlow());

}

Joystick* OI::getOperatorStick() {
	return operatorStick;
}

Joystick* OI::getDriverStick() {
	return driverStick;
}
