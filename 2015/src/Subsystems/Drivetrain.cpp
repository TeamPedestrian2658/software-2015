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
	_chooser->AddDefault("Tank", new bool(true));
	_chooser->AddObject("Arcade", new bool(false));
	SmartDashboard::PutData("Drive Mode", _chooser);

	_rumbleChooser = RobotMap::driveRumbleChooser;
	_rumbleChooser->AddDefault("Rumble On", new bool(true));
	_rumbleChooser->AddObject("Rumble Off", new bool(false));
	SmartDashboard::PutData("Drive Rumble", _rumbleChooser);

	_encoderVelocityMode = true;
	setEncoderMode(_encoderVelocityMode);
	SmartDashboard::PutString("Encoder Mode", "VELOCITY");

	enableEnhancedDriving();
	SmartDashboard::PutString("Enhanced Driving", "ENABLED");

	disableSlow();
	SmartDashboard::PutString("Slow Mode", "DISABLED");

	shiftLow();
	SmartDashboard::PutString("Gear", "LOW");

	updatePIDCoefficients();
}
    
void Drivetrain::InitDefaultCommand() {
	//SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::shiftHigh() {
	if (!isHighGear()) {
		_shifter->Set(_constants->shifterStates.highGear);
		_highGear = _constants->shifterStates.highGear;
		updatePIDCoefficients();
		_constants->reducePressure(_constants->pneumaticConstants.shifterActuationLoss);
		SmartDashboard::PutString("Gear", "HIGH");
	}
}

void Drivetrain::shiftLow() {
	if (isHighGear()) {
		_shifter->Set(_constants->shifterStates.lowGear);
		_highGear = _constants->shifterStates.lowGear;
		updatePIDCoefficients();
		_constants->reducePressure(_constants->pneumaticConstants.shifterActuationLoss);
		SmartDashboard::PutString("Gear", "LOW");
	}
}

bool Drivetrain::isHighGear() {
	return (_shifter->Get() == _constants->shifterStates.highGear);
}

void Drivetrain::set(double leftVelocity, double rightVelocity) {
	_controllerLeft->SetSetpoint(leftVelocity);
	_controllerRight->SetSetpoint(rightVelocity);

	SmartDashboard::PutNumber("Left Setpoint", leftVelocity);
	SmartDashboard::PutNumber("Right Setpoint", rightVelocity);
}

void Drivetrain::setRaw(double left, double right) {
	_talonLeft->Set(-left);
	_talonRight->Set(right);
}

void Drivetrain::setEncoderMode(bool velocity) {
	_encoderVelocityMode = velocity;
	if (velocity) {
		_encoderLeft->SetPIDSourceParameter(PIDSource::kRate);
		_encoderRight->SetPIDSourceParameter(PIDSource::kRate);
		SmartDashboard::PutString("Encoder Mode", "VELOCITY");
	} else {
		_encoderLeft->SetPIDSourceParameter(PIDSource::kDistance);
		_encoderRight->SetPIDSourceParameter(PIDSource::kDistance);
		SmartDashboard::PutString("Encoder Mode", "POSITION");
	}
}

bool Drivetrain::encoderVelocityMode() {
	return _encoderVelocityMode;
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
	PIDProfile profile = _constants->getDriveProfile(_highGear, _encoderVelocityMode, 0);
	_profile.p = profile.p;
	_profile.i = profile.i;
	_profile.d = profile.d;
	_profile.f = profile.f;
	_controllerLeft->SetPID(-_profile.p, -_profile.i, -_profile.d, -_profile.f);
	_controllerRight->SetPID(_profile.p, _profile.i, _profile.d, _profile.f);

	SmartDashboard::PutNumber("Left Drive P", _controllerLeft->GetP());
	SmartDashboard::PutNumber("Left Drive I", _controllerLeft->GetI());
	SmartDashboard::PutNumber("Left Drive D", _controllerLeft->GetD());
	SmartDashboard::PutNumber("Left Drive F", _controllerLeft->GetF());

	SmartDashboard::PutNumber("Right Drive P", _controllerRight->GetP());
	SmartDashboard::PutNumber("Right Drive I", _controllerRight->GetI());
	SmartDashboard::PutNumber("Right Drive D", _controllerRight->GetD());
	SmartDashboard::PutNumber("Right Drive F", _controllerRight->GetF());
}

PIDProfile Drivetrain::getPIDCoefficients() {
	return _profile;
}
