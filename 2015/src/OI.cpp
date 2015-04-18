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
#include "Commands/Utilities/CompressorOn.h"
#include "Commands/Utilities/CompressorOff.h"
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

	incrementItemCount = new JoystickButton(driverStick, constants->driverButtons.incrementItemCountButton);
	incrementItemCount->WhenPressed(new IncrementTotalCount());

	decrementItemCount = new JoystickButton(driverStick, constants->driverButtons.decrementItemCountButton);
	decrementItemCount->WhenPressed(new DecrementTotalCount());

	resetItemCount = new JoystickButton(driverStick, constants->driverButtons.resetItemCountButton);
	resetItemCount->WhenPressed(new ResetTotalCount());

	compressorOn = new JoystickButton(driverStick, constants->driverButtons.compressorOnButton);
	compressorOn->WhenPressed(new CompressorOn());

	compressorOff = new JoystickButton(driverStick, constants->driverButtons.compressorOffButton);
	compressorOff->WhenPressed(new CompressorOff());

	lowerClawToggleGrab = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawToggleGrabButton);
	lowerClawToggleGrab->WhenPressed(new LowerClawToggleGrab());

	lowerClawToggleGrabLeft = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawToggleGrabLeftButton);
	lowerClawToggleGrabLeft->WhenPressed(new LowerClawToggleGrabLeft());

	lowerClawToggleGrabRight = new JoystickButton(operatorStick, constants->operatorButtons.lowerClawToggleGrabRightButton);
	lowerClawToggleGrabRight->WhenPressed(new LowerClawToggleGrabRight());

	upperClawToggleGrab = new JoystickButton(operatorStick, constants->operatorButtons.upperClawToggleGrabButton);
	upperClawToggleGrab->WhenPressed(new UpperClawToggleGrab());

	toggleLiftAutomatic = new JoystickButton(operatorStick, constants->operatorButtons.toggleLiftAutomaticButton);
	toggleLiftAutomatic->WhenPressed(new ToggleLowerLiftController());
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











