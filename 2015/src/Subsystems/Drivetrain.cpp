#include "Drivetrain.h"
#include "../RobotMap.h"

#include "../Commands/DriveWithJoystick.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	_talonLeft = RobotMap::driveTalonLeft;
	_talonRight = RobotMap::driveTalonRight;

	_encoderLeft = RobotMap::driveEncoderLeft;
	_encoderRight = RobotMap::driveEncoderRight;

	_controllerLeft = RobotMap::driveControllerLeft;
	_controllerRight = RobotMap::driveControllerRight;

	_shifterLeft = RobotMap::driveShifterLeft;
	_shifterRight = RobotMap::driveShifterRight;

	_chooser = RobotMap::driveChooser;
	_chooser->AddDefault("Tank", new bool(true));
	_chooser->AddObject("Arcade", new bool(false));
	SmartDashboard::PutData("Drive Mode", _chooser);

	_enhanceEnabled = true;
	_controllerLeft->Enable();
	_controllerRight->Enable();
	SmartDashboard::PutBoolean("Enhanced Driving", _enhanceEnabled);

	_slowEnabled = false;
	SmartDashboard::PutBoolean("Slow Mode", _slowEnabled);
}
    
void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::shiftHigh() {
	_shifterLeft->Set(true);
	_shifterRight->Set(true);
}

void Drivetrain::shiftLow() {
	_shifterLeft->Set(false);
	_shifterRight->Set(false);
}

void Drivetrain::set(double leftVelocity, double rightVelocity) {
	_controllerLeft->SetSetpoint(leftVelocity);
	_controllerRight->SetSetpoint(rightVelocity);
}

void Drivetrain::setRaw(double left, double right) {
	_talonLeft->Set(left);
	_talonRight->Set(right);
}

void Drivetrain::setEncoderMode(bool velocity) {
	_encoderLeft->setMode(velocity);
	_encoderRight->setMode(velocity);
}

bool Drivetrain::encoderMode() {
	return _encoderLeft->getMode();
}

bool Drivetrain::tankEnabled() {
	return _chooser->GetSelected();
}

void Drivetrain::enableEnhancedDriving(bool enable) {
	_enhanceEnabled = enable;
	SmartDashboard::PutBoolean("Enhanced Driving", _enhanceEnabled);
	if (enable) {
		_controllerLeft->Enable();
		_controllerRight->Enable();
	} else {
		_controllerLeft->Disable();
		_controllerRight->Disable();
	}
}

bool Drivetrain::enhanceEnabled() {
	return _enhanceEnabled;
}

void Drivetrain::enableSlow(bool enable) {
	_slowEnabled = enable;
	SmartDashboard::PutBoolean("Slow Mode", _slowEnabled);
}

bool Drivetrain::slowEnabled() {
	return _slowEnabled;
}
