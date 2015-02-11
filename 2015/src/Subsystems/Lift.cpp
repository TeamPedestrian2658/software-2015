#include "Lift.h"
#include "../RobotMap.h"

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

	enableLowerController();
	enableUpperController();
}
    
void Lift::InitDefaultCommand() {

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

void Lift::enableUpperController() {
	_upperController->Enable();
	_upperAutomatic = true;
	SmartDashboard::PutString("Upper Controller", "ENABLED");
}

void Lift::disableUpperController() {
	_upperController->Disable();
	_lowerAutomatic = false;
	SmartDashboard::PutString("Upper Controller", "DISABLED");
}

void Lift::setLowerHeight(double height) {

}

void Lift::setUpperHeight(double height) {

}

void Lift::setLowerRaw(double value) {
	_lowerLeftTalon->Set(value);
	_lowerRightTalon->Set(value);
}

void Lift::setUpperRaw(double value) {
	_upperTalon->Set(value);
}

double Lift::getLowerHeight() {
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

double Lift::getLowerRaw() {
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
