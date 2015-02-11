#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "RobotMap.h"

#include "Commands/Drivetrain/ShiftHigh.h"
#include "Commands/Drivetrain/ShiftLow.h"
#include "Commands/Drivetrain/ToggleEnhancedDriving.h"
#include "Commands/Drivetrain/EnableSlow.h"
#include "Commands/Drivetrain/DisableSlow.h"
#include "Commands/Dolly/ToggleDolly.h"
#include "Commands/ToteMover/SetToteMover.h"
#include "Commands/UpperClaw/UpperClawGrab.h"
#include "Commands/UpperClaw/UpperClawRelease.h"
#include "Commands/LowerClaw/LowerClawGrab.h"
#include "Commands/LowerClaw/LowerClawRelease.h"

#include "Commands/Drivetrain/DriveSCurve.h"

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

double OI::getDriverStickLeftX() {
	return driverStick->GetRawAxis(constants->driverAxes.leftX);
}

double OI::getDriverStickLeftY() {
	return driverStick->GetRawAxis(constants->driverAxes.leftY);
}

double OI::getDriverStickRightX() {
	return driverStick->GetRawAxis(constants->driverAxes.rightX);
}

double OI::getDriverStickRightY() {
	return driverStick->GetRawAxis(constants->driverAxes.rightY);
}

double OI::getOperatorStickLeftX() {
	return operatorStick->GetRawAxis(constants->operatorAxes.leftX);
}

double OI::getOperatorStickLeftY() {
	return operatorStick->GetRawAxis(constants->operatorAxes.leftY);
}

double OI::getOperatorStickRightX() {
	return operatorStick->GetRawAxis(constants->operatorAxes.rightX);
}

double OI::getOperatorStickRightY() {
	return operatorStick->GetRawAxis(constants->operatorAxes.rightY);
}












