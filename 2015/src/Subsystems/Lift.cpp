#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lift/ControlLift.h"

Lift::Lift() : Subsystem("Lift") {
	_constants = RobotMap::constants;

	_lowerLeftTalon = RobotMap::lowerLiftTalonLeft;
	_lowerRightTalon = RobotMap::lowerLiftTalonRight;
	_upperTalon = RobotMap::upperLiftTalon;

	_lowerLeftEncoder = RobotMap::lowerLiftEncoderLeft;
	_lowerRightEncoder = RobotMap::lowerLiftEncoderRight;
	_upperEncoder = RobotMap::upperLiftEncoder;

	_lowerLeftController = RobotMap::liftControllerLowerLeft;
	_lowerRightController = RobotMap::liftControllerLowerRight;
	_upperController = RobotMap::liftControllerUpper;

	_lowerLevels = _constants->liftConstants.lowerLiftLevels;
	_upperLevels = _constants->liftConstants.upperLiftLevels;

	updatePIDCoefficients();

	resetLowerLevel();
	resetUpperLevel();

	enableLowerController();
	enableUpperController();
}
    
void Lift::InitDefaultCommand() {
	SetDefaultCommand(new ControlLift());
}

void Lift::enableLowerController() {
	_lowerLeftController->Enable();
	_lowerRightController->Enable();
	_lowerAutomatic = true;
	SmartDashboard::PutString("Lower Controller", "ENABLED");
}

void Lift::disableLowerController() {
	_lowerLeftController->Disable();
	_lowerRightController->Disable();
	_lowerAutomatic = false;
	SmartDashboard::PutString("Lower Controller", "DISABLED");
}

bool Lift::lowerControllerEnabled() {
	return _lowerAutomatic;
}

void Lift::enableUpperController() {
	_upperController->Enable();
	_upperAutomatic = true;
	SmartDashboard::PutString("Upper Controller", "ENABLED");
}

void Lift::disableUpperController() {
	_upperController->Disable();
	_upperAutomatic = false;
	SmartDashboard::PutString("Upper Controller", "DISABLED");
}

bool Lift::upperControllerEnabled() {
	return _upperAutomatic;
}

void Lift::lowerUpOneLevel() {
	if (_lowerLevel < _lowerLevels.size() - 1) {
		_lowerLevel++;
	}
	while (get<0>(_lowerLevels[_lowerLevel]) > get<0>(_upperLevels[_upperLevel])) {
		upperUpOneLevel();
	}
	_lowerLeftController->SetSetpoint(get<0>(_lowerLevels[_lowerLevel]));
	_lowerRightController->SetSetpoint(get<0>(_lowerLevels[_lowerLevel]));
	SmartDashboard::PutNumber("Lower Setpoint", get<0>(_lowerLevels[_lowerLevel]));
	SmartDashboard::PutString("Lower Level", get<2>(_lowerLevels[_lowerLevel]));
}

void Lift::lowerDownOneLevel() {
	if (_lowerLevel > 0) {
		_lowerLevel--;
	}
	_lowerLeftController->SetSetpoint(get<0>(_lowerLevels[_lowerLevel]));
	_lowerRightController->SetSetpoint(get<0>(_lowerLevels[_lowerLevel]));
	SmartDashboard::PutNumber("Lower Setpoint", get<0>(_lowerLevels[_lowerLevel]));
	SmartDashboard::PutString("Lower Level", get<2>(_lowerLevels[_lowerLevel]));
}

void Lift::resetLowerLevel() {
	_lowerLevel = 0;
	_lowerLeftController->SetSetpoint(get<0>(_lowerLevels[_lowerLevel]));
	_lowerRightController->SetSetpoint(get<0>(_lowerLevels[_lowerLevel]));
	SmartDashboard::PutNumber("Lower Setpoint", get<0>(_lowerLevels[_lowerLevel]));
	SmartDashboard::PutString("Lower Level", get<2>(_lowerLevels[_lowerLevel]));
}

int Lift::getLowerLevel() {
	return _lowerLevel;
}

void Lift::upperUpOneLevel() {
	if (_upperLevel < _upperLevels.size() - 1) {
		_upperLevel++;
	}
	_upperController->SetSetpoint(get<0>(_upperLevels[_upperLevel]));
	SmartDashboard::PutNumber("Upper Setpoint", get<0>(_upperLevels[_upperLevel]));
	SmartDashboard::PutString("Upper Level", get<2>(_upperLevels[_upperLevel]));
}

void Lift::upperDownOneLevel() {
	if (_upperLevel > 0) {
		_upperLevel--;
	}
	while (get<0>(_upperLevels[_upperLevel]) < get<0>(_lowerLevels[_lowerLevel])) {
		lowerDownOneLevel();
	}
	_upperController->SetSetpoint(get<0>(_upperLevels[_upperLevel]));
	SmartDashboard::PutNumber("Upper Setpoint", get<0>(_upperLevels[_upperLevel]));
	SmartDashboard::PutString("Upper Level", get<2>(_upperLevels[_upperLevel]));
}

void Lift::resetUpperLevel() {
	_upperLevel = 0;
	_upperController->SetSetpoint(get<0>(_upperLevels[_upperLevel]));
	SmartDashboard::PutNumber("Upper Setpoint", get<0>(_upperLevels[_upperLevel]));
	SmartDashboard::PutString("Upper Level", get<2>(_upperLevels[_upperLevel]));
}

int Lift::getUpperLevel() {
	return _upperLevel;
}

int Lift::getLowerPossessionLevel() {
	return get<1>(_lowerLevels[_lowerLevel]);
}

int Lift::getUpperPossessionLevel() {
	return get<1>(_upperLevels[_upperLevel]);
}

void Lift::setLowerRaw(double value) {
	_lowerLeftTalon->Set(-value);
	_lowerRightTalon->Set(value);
}

void Lift::setUpperRaw(double value) {
	_upperTalon->Set(value);
}

double Lift::getLowerAverageHeight() {
	return (_lowerLeftEncoder->GetDistance() + _lowerRightEncoder->GetDistance()) / 2;
}

double Lift::getLowerLeftHeight() {
	return _lowerLeftEncoder->GetDistance();
}

double Lift::getLowerRightHeight() {
	return _lowerRightEncoder->GetDistance();
}

double Lift::getUpperHeight() {
	return _upperEncoder->GetDistance();
}

double Lift::getLowerAverageRaw() {
	return (_lowerLeftTalon->Get() + _lowerRightTalon->Get()) / 2;
}

double Lift::getLowerLeftRaw() {
	return _lowerLeftTalon->Get();
}

double Lift::getLowerRightRaw() {
	return _lowerRightTalon->Get();
}

double Lift::getUpperRaw() {
	return _upperTalon->Get();
}

void Lift::updatePIDCoefficients() {
	_lowerProfile = _constants->getLowerLiftProfile();
	_upperProfile = _constants->getUpperLiftProfile();

	_lowerLeftController->SetPID(-_lowerProfile.p,
								 -_lowerProfile.i,
								 -_lowerProfile.d,
								 -_lowerProfile.f);

	_lowerRightController->SetPID(_lowerProfile.p,
								  _lowerProfile.i,
								  _lowerProfile.d,
								  _lowerProfile.f);

	_upperController->SetPID(_upperProfile.p,
			   	   	   	   	 _upperProfile.i,
							 _upperProfile.d,
							 _upperProfile.f);
}

PIDProfile Lift::getLowerPIDCoefficients() {
	return _lowerProfile;
}

PIDProfile Lift::getUpperPIDCoefficients() {
	return _upperProfile;
}
