#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "RobotMap.h"

#include "Commands/ShiftHigh.h"
#include "Commands/ShiftLow.h"
#include "Commands/ToggleEnhancedDriving.h"
#include "Commands/EnableSlow.h"
#include "Commands/DisableSlow.h"

OI::OI() {

	constants = RobotMap::constants;

	operatorStick = new Joystick(constants->oiPorts.operatorPort);
	driverStick = new Joystick(constants->oiPorts.driverPort);

	driveShifter = new JoystickButton(driverStick, constants->oiPorts.shiftButton);
	driveShifter->WhenPressed(new ShiftHigh());
	driveShifter->WhenReleased(new ShiftLow());

	driveEnhance = new JoystickButton(driverStick, constants->oiPorts.toggleEnhanceButton);
	driveEnhance->WhenPressed(new ToggleEnhancedDriving());

	driveSlow = new JoystickButton(driverStick, constants->oiPorts.slowButton);
	driveSlow->WhenPressed(new EnableSlow());
	driveSlow->WhenReleased(new DisableSlow());

}

Joystick* OI::getOperatorStick() {
	return operatorStick;
}

Joystick* OI::getDriverStick() {
	return driverStick;
}
