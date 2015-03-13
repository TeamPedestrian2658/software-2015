#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

#include "RobotMap.h"

#include "Commands/Drivetrain/ShiftHigh.h"
#include "Commands/Drivetrain/ShiftLow.h"
#include "Commands/Drivetrain/ToggleEnhancedDriving.h"
#include "Commands/Drivetrain/EnableSlow.h"
#include "Commands/Drivetrain/DisableSlow.h"
#include "Commands/Utilities/IncrementTotalCount.h"
#include "Commands/Utilities/DecrementTotalCount.h"
#include "Commands/Utilities/ResetTotalCount.h"
#include "Commands/LowerClaw/LowerClawToggleGrab.h"
#include "Commands/LowerClaw/LowerClawToggleGrabLeft.h"
#include "Commands/LowerClaw/LowerClawToggleGrabRight.h"
#include "Commands/UpperClaw/UpperClawToggleGrab.h"
#include "Commands/UpperClaw/UpperClawToggleGrabLeft.h"
#include "Commands/UpperClaw/UpperClawToggleGrabRight.h"
#include "Commands/Lift/ToggleLowerLiftController.h"
#include "Commands/Lift/ToggleUpperLiftController.h"

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

	incrementTotalItemCount = new JoystickButton(driverStick, constants->driverButtons.incrementTotalItemCountButton);
	incrementTotalItemCount->WhenPressed(new IncrementTotalCount());

	decrementTotalItemCount = new JoystickButton(driverStick, constants->driverButtons.decrementTotalItemCountButton);
	decrementTotalItemCount->WhenPressed(new DecrementTotalCount());

	resetTotalItemCount = new JoystickButton(driverStick, constants->driverButtons.resetTotalItemCountButton);
	resetTotalItemCount->WhenPressed(new ResetTotalCount());

	lowerClawToggleGrab = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawToggleGrabButton);
	lowerClawToggleGrab->WhenPressed(new LowerClawToggleGrab());

	lowerClawToggleGrabLeft = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawToggleGrabLeftButton);
	lowerClawToggleGrabLeft->WhenPressed(new LowerClawToggleGrabLeft());

	lowerClawToggleGrabRight = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawToggleGrabRightButton);
	lowerClawToggleGrabRight->WhenPressed(new LowerClawToggleGrabRight());

	upperClawToggleGrab = new JoystickButton(operatorStick, constants->operatorButtons.upperClawToggleGrabButton);
	upperClawToggleGrab->WhenPressed(new UpperClawToggleGrab());

	upperClawToggleGrabLeft = new JoystickButton(operatorStick, constants->operatorButtons.upperClawToggleGrabLeftButton);
	upperClawToggleGrabLeft->WhenPressed(new UpperClawToggleGrabLeft());

	upperClawToggleGrabRight = new JoystickButton(operatorStick, constants->operatorButtons.upperClawToggleGrabRightButton);
	upperClawToggleGrabRight->WhenPressed(new UpperClawToggleGrabRight());

	toggleLowerLiftAutomatic = new JoystickButton(operatorStick, constants->operatorButtons.toggleLowerLiftAutomaticButton);
	toggleLowerLiftAutomatic->WhenPressed(new ToggleLowerLiftController());

	toggleUpperLiftAutomatic = new JoystickButton(operatorStick, constants->operatorButtons.toggleUpperLiftAutomaticButton);
	toggleUpperLiftAutomatic->WhenPressed(new ToggleUpperLiftController());
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











