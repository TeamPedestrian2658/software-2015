#include "UpperClaw.h"
#include "../RobotMap.h"

UpperClaw::UpperClaw() : Subsystem("UpperClaw") {
	_constants = RobotMap::constants;
	_grabber = RobotMap::upperClawGrabber;
	_brake = RobotMap::upperClawBrake;
}
    
void UpperClaw::InitDefaultCommand() {

}

void UpperClaw::grab() {
	if (!isClawClosed()) {
		_grabber->Set(_constants->clawStates.upperClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawGrabberActuationLoss);
	}
}

void UpperClaw::release() {
	if (isClawClosed()) {
		_grabber->Set(!_constants->clawStates.upperClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawGrabberActuationLoss);
	}
}

void UpperClaw::brakeOn() {
	if (!isBrakeOn()) {
		_brake->Set(_constants->clawStates.upperClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawBrakeActuationLoss);
	}
}

void UpperClaw::brakeOff() {
	if (isBrakeOn()) {
		_brake->Set(!_constants->clawStates.upperClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawBrakeActuationLoss);
	}
}

bool UpperClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.upperClawGrab);
}

bool UpperClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.upperClawBrakeOn);
}
