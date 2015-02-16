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

void Lift::setLowerHeightFromGround(double heightFromGround) {
	if (heightFromGround < (_constants->liftConstants.minHeight + _constants->liftConstants.bufferFromBottom)) {
		heightFromGround = (_constants->liftConstants.minHeight + _constants->liftConstants.bufferFromBottom);
	}

	if (heightFromGround > (_constants->liftConstants.maxHeight - _constants->liftConstants.bufferFromTop - _constants->liftConstants.bufferBetweenClaws - _constants->liftConstants.upperClawWidth)) {
		heightFromGround = (_constants->liftConstants.maxHeight - _constants->liftConstants.bufferFromTop - _constants->liftConstants.bufferBetweenClaws - _constants->liftConstants.upperClawWidth);
	}

	if (heightFromGround + _constants->liftConstants.lowerClawWidth + _constants->liftConstants.bufferBetweenClaws > getUpperHeightFromGround()) {
		setUpperHeightFromGround(heightFromGround + _constants->liftConstants.lowerClawWidth + _constants->liftConstants.bufferBetweenClaws);
	}

	_lowerLeftController->SetSetpoint(heightFromGround - _constants->liftConstants.heightFromGround);
}

void Lift::setUpperHeightFromGround(double heightFromGround) {

}

void Lift::setLowerRaw(double value) {
	_lowerLeftTalon->Set(-value);
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

double Lift::getLowerHeightFromGround() {
	return getLowerHeight() + _constants->liftConstants.heightFromGround;
}

double Lift::getLowerLeftHeightFromGround() {
	return getLowerLeftHeight() + _constants->liftConstants.heightFromGround;
}

double Lift::getLowerRightHeightFromGround() {
	return getLowerRightHeight() + _constants->liftConstants.heightFromGround;
}

double Lift::getUpperHeight() {
	return _upperEncoder->GetDistance() + _constants->liftConstants.lowerClawWidth;
}

double Lift::getUpperHeightFromGround() {
	return getUpperHeight() + _constants->liftConstants.heightFromGround;
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
