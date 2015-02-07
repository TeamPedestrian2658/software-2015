#include "Drivetrain.h"
#include "../RobotMap.h"

#include "../Commands/DriveWithJoystick.h"

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
	_chooser->AddDefault("Tank", new int(0));
	_chooser->AddObject("Arcade", new int(1));
	SmartDashboard::PutData("Drive Mode", _chooser);

	_encoderVelocityMode = true;
	setEncoderMode(_encoderVelocityMode);
	SmartDashboard::PutBoolean("Encoder Velocity Mode", _encoderVelocityMode);

	enableEnhancedDriving(true);
	SmartDashboard::PutBoolean("Enhanced Driving", _enhanceEnabled);

	_slowEnabled = false;
	SmartDashboard::PutBoolean("Slow Mode", _slowEnabled);

	shiftLow();
	SmartDashboard::PutBoolean("High Gear", _highGear);
}
    
void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::shiftHigh() {
	_shifter->Set(_constants->shifterStates.highGear);
	_highGear = _constants->shifterStates.highGear;
	updatePIDCoefficients();
	_constants->reducePressure(_constants->pneumaticConstants.shifterActuationLoss);
	SmartDashboard::PutBoolean("High Gear", _constants->shifterStates.highGear);
}

void Drivetrain::shiftLow() {
	_shifter->Set(_constants->shifterStates.lowGear);
	_highGear = _constants->shifterStates.lowGear;
	updatePIDCoefficients();
	_constants->reducePressure(_constants->pneumaticConstants.shifterActuationLoss);
	SmartDashboard::PutBoolean("High Gear", _constants->shifterStates.lowGear);
}

bool Drivetrain::isHighGear() {
	return _highGear;
}

void Drivetrain::set(double leftVelocity, double rightVelocity) {
	_controllerLeft->SetSetpoint(leftVelocity);
	_controllerRight->SetSetpoint(rightVelocity);
}

void Drivetrain::setRaw(double left, double right) {
	_talonLeft->Set(-left);
	_talonRight->Set(right);
}

void Drivetrain::setEncoderMode(bool velocity) {
	_encoderVelocityMode = velocity;
	SmartDashboard::PutBoolean("Encoder Velocity Mode", _encoderVelocityMode);

	if (velocity) {
		_encoderLeft->SetPIDSourceParameter(PIDSource::kRate);
		_encoderRight->SetPIDSourceParameter(PIDSource::kRate);
	} else {
		_encoderLeft->SetPIDSourceParameter(PIDSource::kDistance);
		_encoderRight->SetPIDSourceParameter(PIDSource::kDistance);
	}
}

bool Drivetrain::encoderVelocityMode() {
	return _encoderVelocityMode;
}

bool Drivetrain::tankEnabled() {
	if (*(int*)_chooser->GetSelected() == 0) {
		return true;
	} else {
		return false;
	}
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

void Drivetrain::updatePIDCoefficients() {
	PIDProfile profile = _constants->getDriveProfile(_highGear, _encoderVelocityMode, 0);
	_profile.p = profile.p;
	_profile.i = profile.i;
	_profile.d = profile.d;
	_profile.f = profile.f;
	_controllerLeft->SetPID(-_profile.p, -_profile.i, -_profile.d, -_profile.f);
	_controllerRight->SetPID(_profile.p, _profile.i, _profile.d, _profile.f);

	SmartDashboard::PutNumber("Left Drive P", _controllerLeft->GetP());
	SmartDashboard::PutNumber("Left Drive I", _controllerLeft->GetP());
	SmartDashboard::PutNumber("Left Drive D", _controllerLeft->GetP());
	SmartDashboard::PutNumber("Left Drive F", _controllerLeft->GetP());

	SmartDashboard::PutNumber("Right Drive P", _controllerRight->GetP());
	SmartDashboard::PutNumber("Right Drive I", _controllerRight->GetI());
	SmartDashboard::PutNumber("Right Drive D", _controllerRight->GetD());
	SmartDashboard::PutNumber("Right Drive F", _controllerRight->GetF());
}

PIDProfile Drivetrain::getPIDCoefficients() {
	return _profile;
}
