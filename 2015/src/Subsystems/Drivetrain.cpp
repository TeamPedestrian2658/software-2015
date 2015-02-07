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
	updatePIDCoefficients();

	_shifter = RobotMap::driveShifter;

	_chooser = RobotMap::driveChooser;
	_chooser->AddDefault("Tank", new bool(true));
	_chooser->AddObject("Arcade", new bool(false));
	SmartDashboard::PutData("Drive Mode", _chooser);

	_encoderVelocityMode = true;
	setEncoderMode(_encoderVelocityMode);
	SmartDashboard::PutString("Encoder Mode", "VELOCITY");

	enableEnhancedDriving(true);
	SmartDashboard::PutString("Enhanced Driving", "ENABLED");

	_slowEnabled = false;
	SmartDashboard::PutString("Slow Mode", "DISABLED");

	shiftLow();
	SmartDashboard::PutString("Gear", "LOW");
}
    
void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::shiftHigh() {
	_shifter->Set(_constants->shifterStates.highGear);
	_highGear = _constants->shifterStates.highGear;
	updatePIDCoefficients();
	_constants->reducePressure(_constants->pneumaticConstants.shifterActuationLoss);
	SmartDashboard::PutString("Gear", "HIGH");
}

void Drivetrain::shiftLow() {
	_shifter->Set(_constants->shifterStates.lowGear);
	_highGear = _constants->shifterStates.lowGear;
	updatePIDCoefficients();
	_constants->reducePressure(_constants->pneumaticConstants.shifterActuationLoss);
	SmartDashboard::PutString("Gear", "LOW");
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

void Drivetrain::enableEnhancedDriving(bool enable) {
	_enhanceEnabled = enable;
	if (enable) {
		_controllerLeft->Enable();
		_controllerRight->Enable();
		SmartDashboard::PutString("Enhanced Driving", "ENABLED");
	} else {
		_controllerLeft->Disable();
		_controllerRight->Disable();
		SmartDashboard::PutString("Enhanced Driving", "DISABLED");
	}
}

bool Drivetrain::enhanceEnabled() {
	return _enhanceEnabled;
}

void Drivetrain::enableSlow(bool enable) {
	_slowEnabled = enable;
	if (_slowEnabled) {
		SmartDashboard::PutString("Slow Mode", "ENABLED");
	} else {
		SmartDashboard::PutString("Slow Mode", "DISABLED");
	}
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
