#include "Drivetrain.h"
#include "../RobotMap.h"

#include "../Commands/Drivetrain/DriveWithJoystick.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	_constants = RobotMap::constants;

	_talonLeft = RobotMap::driveTalonLeft;
	_talonRight = RobotMap::driveTalonRight;

	_encoderLeft = RobotMap::driveEncoderLeft;
	_encoderRight = RobotMap::driveEncoderRight;

	_controllerLeft = RobotMap::driveControllerLeft;
	_controllerRight = RobotMap::driveControllerRight;

	_shifter = RobotMap::driveShifter;

	_chooser = RobotMap::driveChooser;
	_chooser->AddDefault("Arcade", new bool(false));
	_chooser->AddObject("Tank", new bool(true));
	SmartDashboard::PutData("Drive Mode", _chooser);

	_rumbleChooser = RobotMap::driveRumbleChooser;
	_rumbleChooser->AddDefault("Rumble Off", new bool(false));
	_rumbleChooser->AddObject("Rumble On", new bool(true));
	SmartDashboard::PutData("Drive Rumble", _rumbleChooser);

	disableEnhancedDriving();

	disableSlow();

	shiftLow();

	if (_constants->debug) {
		SmartDashboard::PutNumber("Left Setpoint", 0);
		SmartDashboard::PutNumber("Right Setpoint", 0);
		SmartDashboard::PutNumber("Left Velocity", 0);
		SmartDashboard::PutNumber("Right Velocity", 0);
	}

	updatePIDCoefficients();
}
    
void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::shiftHigh() {
	_shifter->Set(_constants->shifterStates.highGear);
	_shifterState = _constants->shifterStates.highGear;
	updatePIDCoefficients();
	SmartDashboard::PutString("Gear", "HIGH");
}

void Drivetrain::shiftLow() {
	_shifter->Set(_constants->shifterStates.lowGear);
	_shifterState = _constants->shifterStates.lowGear;
	updatePIDCoefficients();
	SmartDashboard::PutString("Gear", "LOW");
}

bool Drivetrain::isHighGear() {
	return (_shifterState == _constants->shifterStates.highGear);
}

void Drivetrain::set(double leftVelocity, double rightVelocity) {
	_controllerLeft->SetSetpoint(leftVelocity);
	_controllerRight->SetSetpoint(rightVelocity);
	if (_constants->debug) {
		SmartDashboard::PutNumber("Left Setpoint", leftVelocity);
		SmartDashboard::PutNumber("Right Setpoint", rightVelocity);
	}
}

void Drivetrain::setRaw(double left, double right) {
	_talonLeft->Set(-left);
	_talonRight->Set(right);
}

bool Drivetrain::tankEnabled() {
	return *(bool*)_chooser->GetSelected();
}

bool Drivetrain::rumbleEnabled() {
	return *(bool*)_rumbleChooser->GetSelected();
}

void Drivetrain::enableEnhancedDriving() {
	_enhanceEnabled = true;
	_controllerLeft->Enable();
	_controllerRight->Enable();
	SmartDashboard::PutString("Enhanced Driving", "ENABLED");
}

void Drivetrain::disableEnhancedDriving() {
	_enhanceEnabled = false;
	_controllerLeft->Reset();
	_controllerRight->Reset();
	SmartDashboard::PutString("Enhanced Driving", "DISABLED");
}

bool Drivetrain::enhanceEnabled() {
	return _enhanceEnabled;
}

void Drivetrain::enableSlow() {
	_slowEnabled = true;
	SmartDashboard::PutString("Slow Mode", "ENABLED");
}

void Drivetrain::disableSlow() {
	_slowEnabled = false;
	SmartDashboard::PutString("Slow Mode", "DISABLED");
}

bool Drivetrain::slowEnabled() {
	return _slowEnabled;
}

void Drivetrain::updatePIDCoefficients() {
	_profile = _constants->getDriveProfile(_shifterState);
	_controllerLeft->SetPID(-_profile.p, -_profile.i, -_profile.d, -_profile.f);
	_controllerRight->SetPID(_profile.p, _profile.i, _profile.d, _profile.f);

	if (_constants->debug) {
		SmartDashboard::PutNumber("Left Drive P", _controllerLeft->GetP());
		SmartDashboard::PutNumber("Left Drive I", _controllerLeft->GetI());
		SmartDashboard::PutNumber("Left Drive D", _controllerLeft->GetD());
		SmartDashboard::PutNumber("Left Drive F", _controllerLeft->GetF());

		SmartDashboard::PutNumber("Right Drive P", _controllerRight->GetP());
		SmartDashboard::PutNumber("Right Drive I", _controllerRight->GetI());
		SmartDashboard::PutNumber("Right Drive D", _controllerRight->GetD());
		SmartDashboard::PutNumber("Right Drive F", _controllerRight->GetF());

	}
}

PIDProfile Drivetrain::getPIDCoefficients() {
	return _profile;
}
