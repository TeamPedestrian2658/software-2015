#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lift/ControlLift.h"

Lift::Lift() : Subsystem("Lift") {
	_constants = RobotMap::constants;

	_leftTalon = RobotMap::liftTalonLeft;
	_rightTalon = RobotMap::liftTalonRight;

	_encoder = RobotMap::liftEncoder;

	_leftController = RobotMap::liftControllerLeft;
	_rightController = RobotMap::liftControllerRight;

	_levels = _constants->liftConstants.liftLevels;

	if (_constants->debug) {
		SmartDashboard::PutNumber("Lift Height", 0);
	}

	resetLevel();

	updatePIDCoefficients(false);

	disableAutomatic();
}
    
void Lift::InitDefaultCommand() {
	SetDefaultCommand(new ControlLift());
}

void Lift::enableLowerController() {
	_leftController->Enable();
	_rightController->Enable();
	_automatic = true;
	SmartDashboard::PutString("Lift Automatic", "ENABLED");
}

void Lift::disableLowerController() {
	_leftController->Disable();
	_rightController->Disable();
	_automatic = false;
	SmartDashboard::PutString("Lift Automatic", "DISABLED");
}

bool Lift::lowerControllerEnabled() {
	return _automatic;
}

void Lift::upOneLevel() {
	if (_level < _levels.size() - 1) {
		_level++;
	}
	_leftController->SetSetpoint(get<0>(_levels[_level]));
	_rightController->SetSetpoint(get<0>(_levels[_level]));
	SmartDashboard::PutString("Lift Level", get<2>(_levels[_level]));

	if (_constants->debug) {
		SmartDashboard::PutNumber("Lift Setpoint", get<0>(_levels[_level]));
	}
}

void Lift::downOneLevel() {
	if (_level > 0) {
		_level--;
	}
	_leftController->SetSetpoint(get<0>(_levels[_level]));
	_rightController->SetSetpoint(get<0>(_levels[_level]));
	SmartDashboard::PutString("Lift Level", get<2>(_levels[_level]));

	if (_constants->debug) {
		SmartDashboard::PutNumber("Lift Setpoint", get<0>(_levels[_level]));
	}
}

void Lift::resetLowerLevel() {
	_level = 0;
	_leftController->SetSetpoint(get<0>(_levels[_level]));
	_rightController->SetSetpoint(get<0>(_levels[_level]));
	SmartDashboard::PutString("Lift Level", get<2>(_levels[_level]));

	if (_constants->debug) {
		SmartDashboard::PutNumber("Lift Setpoint", get<0>(_levels[_level]));
	}
}

int Lift::getLevel() {
	return _level;
}

int Lift::getPossessionLevel() {
	return get<1>(_levels[_level]);
}

void Lift::setRaw(double value) {
	_leftTalon->Set(-value);
	_rightTalon->Set(value);
}

double Lift::getHeight() {
	return _encoder->GetDistance();
}

double Lift::getAverageRaw() {
	return (_leftTalon->Get() + _rightTalon->Get()) / 2;
}

double Lift::getLeftRaw() {
	return _leftTalon->Get();
}

double Lift::getRightRaw() {
	return _rightTalon->Get();
}

void Lift::updatePIDCoefficients(bool lowerClawClosed) {
	_profile = _constants->getLiftProfile(get<1>(_levels[_level]), lowerClawClosed);
	_leftController->SetPID(-_profile.p,
							-_profile.i,
							-_profile.d,
							-_profile.f);

	_rightController->SetPID(_profile.p,
							 _profile.i,
							 _profile.d,
							 _profile.f);

	if (_constants->debug) {
		SmartDashboard::PutNumber("Left P", _leftController->GetP());
		SmartDashboard::PutNumber("Left I", _leftController->GetI());
		SmartDashboard::PutNumber("Left D", _leftController->GetD());
		SmartDashboard::PutNumber("Left F", _leftController->GetF());

		SmartDashboard::PutNumber("Right P", _rightController->GetP());
		SmartDashboard::PutNumber("Right I", _rightController->GetI());
		SmartDashboard::PutNumber("Right D", _rightController->GetD());
		SmartDashboard::PutNumber("Right F", _rightController->GetF());
	}
}

PIDProfile Lift::getPIDCoefficients() {
	return _profile;
}
