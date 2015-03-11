#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "RobotMap.h"

#include "Commands/Drivetrain/ShiftHigh.h"
#include "Commands/Drivetrain/ShiftLow.h"
#include "Commands/Drivetrain/ToggleEnhancedDriving.h"
#include "Commands/Drivetrain/EnableSlow.h"
#include "Commands/Drivetrain/DisableSlow.h"
#include "Commands/UpperClaw/UpperClawGrab.h"
#include "Commands/UpperClaw/UpperClawRelease.h"
#include "Commands/LowerClaw/LowerClawGrabLeft.h"
#include "Commands/LowerClaw/LowerClawGrabRight.h"
#include "Commands/LowerClaw/LowerClawReleaseLeft.h"
#include "Commands/LowerClaw/LowerClawReleaseRight.h"
#include "Commands/Utilities/ResetLowerClawCount.h"
#include "Commands/Utilities/IncrementLowerClawCount.h"
#include "Commands/Utilities/DecrementLowerClawCount.h"
#include "Commands/Lift/DisableLowerLiftController.h"
#include "Commands/Lift/EnableLowerLiftController.h"
#include "Commands/Lift/DisableUpperLiftController.h"
#include "Commands/Lift/EnableUpperLiftController.h"

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

	lowerClawGrabLeft = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawGrabLeftButton);
	lowerClawGrabLeft->WhenPressed(new LowerClawGrabLeft());

	lowerClawGrabRight = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawGrabRightButton);
	lowerClawGrabRight->WhenPressed(new LowerClawGrabRight());

	lowerClawReleaseLeft = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawReleaseLeftButton);
	lowerClawReleaseLeft->WhenPressed(new LowerClawReleaseLeft());

	lowerClawReleaseRight = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawReleaseRightButton);
	lowerClawReleaseRight->WhenPressed(new LowerClawReleaseRight());

	resetLowerClawCount = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawItemCountResetButton);
	resetLowerClawCount->WhenPressed(new ResetLowerClawCount());

	incrementLowerClawCount = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawItemCountIncrementButton);
	incrementLowerClawCount->WhenPressed(new IncrementLowerClawCount());

	decrementLowerClawCount = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawItemCountDecrementButton);
	decrementLowerClawCount->WhenPressed(new DecrementLowerClawCount());

	disableLowerLiftAutomatic = new JoystickButton(operatorStick, constants->operatorButtons.lowerLiftAutomaticDisableButton);
	disableLowerLiftAutomatic->WhenPressed(new DisableLowerLiftController());
	disableLowerLiftAutomatic->WhenReleased(new EnableLowerLiftController());

	disableUpperLiftAutomatic = new JoystickButton(operatorStick, constants->operatorButtons.upperLiftAutomaticDisableButton);
	disableUpperLiftAutomatic->WhenPressed(new DisableUpperLiftController());
	disableUpperLiftAutomatic->WhenReleased(new EnableUpperLiftController());
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

double OI::getOperatorStickPOV() {
	return operatorStick->GetPOV();
}











