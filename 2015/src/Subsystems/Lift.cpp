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
}
    
void Lift::InitDefaultCommand() {

}

void Lift::enableLowerController() {
	_lowerLeftController->Enable();
	_lowerRightController->Enable();
}

void Lift::disableLowerController() {
	_lowerLeftController->Disable();
	_lowerRightController->Disable();
}

void Lift::enableUpperController() {
	_upperController->Enable();
}

void Lift::disableUpperController() {
	_upperController->Disable();
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

double Lift::getUpperHeight() {
	return _upperEncoder->GetDistance();
}

double Lift::getLowerRaw() {
	return (_lowerLeftTalon->Get() + _lowerRightTalon->Get()) / 2;
}

double Lift::getUpperRaw() {
	return _upperTalon->Get();
}
