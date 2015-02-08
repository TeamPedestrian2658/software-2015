#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "RobotMap.h"

#include "Commands/ShiftHigh.h"
#include "Commands/ShiftLow.h"
#include "Commands/ToggleEnhancedDriving.h"
#include "Commands/EnableSlow.h"
#include "Commands/DisableSlow.h"
#include "Commands/ToggleDolly.h"
#include "Commands/SetToteMover.h"
#include "Commands/UpperClawGrab.h"
#include "Commands/UpperClawRelease.h"
#include "Commands/LowerClawGrab.h"
#include "Commands/LowerClawRelease.h"

OI::OI() {

	constants = RobotMap::constants;

	operatorStick = new Joystick(constants->oiPorts.operatorPort);
	driverStick = new Joystick(constants->oiPorts.driverPort);

	driveShifter = new JoystickButton(driverStick, constants->driverButtons.shiftButton);
	driveShifter->WhenPressed(new ShiftHigh());
	driveShifter->WhenReleased(new ShiftLow());

	driveEnhance = new JoystickButton(driverStick, constants->driverButtons.toggleEnhancedDriveButton);
	driveEnhance->WhenPressed(new ToggleEnhancedDriving());

	driveSlow = new JoystickButton(driverStick, constants->driverButtons.slowButton);
	driveSlow->WhenPressed(new EnableSlow());
	driveSlow->WhenReleased(new DisableSlow());

	dollyToggle = new JoystickButton(operatorStick, constants->operatorButtons.toggleDollyButton);
	dollyToggle->WhenPressed(new ToggleDolly());

	toteMoverLeft = new JoystickButton(operatorStick, constants->operatorButtons.toteMoverLeftButton);
	toteMoverLeft->WhenPressed(new SetToteMover(constants->toteMoverStates.moveTotesLeft));
	toteMoverLeft->WhenReleased(new SetToteMover(constants->toteMoverStates.stop));

	toteMoverRight = new JoystickButton(operatorStick, constants->operatorButtons.toteMoverRightButton);
	toteMoverRight->WhenPressed(new SetToteMover(constants->toteMoverStates.moveTotesRight));
	toteMoverRight->WhenReleased(new SetToteMover(constants->toteMoverStates.stop));

	upperClawGrab = new JoystickButton(operatorStick, constants->operatorButtons.upperClawGrabButton);
	upperClawGrab->WhenPressed(new UpperClawGrab());

	upperClawRelease = new JoystickButton(operatorStick, constants->operatorButtons.upperClawReleaseButton);
	upperClawRelease->WhenPressed(new UpperClawRelease());

	lowerClawGrab = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawGrabButton);
	lowerClawGrab->WhenPressed(new LowerClawGrab());

	lowerClawRelease = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawReleaseButton);
	lowerClawRelease->WhenPressed(new LowerClawRelease());
}

Joystick* OI::getOperatorStick() {
	return operatorStick;
}

Joystick* OI::getDriverStick() {
	return driverStick;
}
