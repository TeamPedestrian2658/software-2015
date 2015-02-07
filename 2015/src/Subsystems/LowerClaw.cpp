#include "LowerClaw.h"
#include "../RobotMap.h"

LowerClaw::LowerClaw() : Subsystem("LowerClaw") {
	_constants = RobotMap::constants;
	_grabber = RobotMap::lowerClawGrabber;
	_brake = RobotMap::lowerClawBrake;
}
    
void LowerClaw::InitDefaultCommand() {

}

void LowerClaw::grab() {
	if (!isClawClosed()) {
		_grabber->Set(_constants->clawStates.lowerClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawGrabberActuationLoss);
	}
}

void LowerClaw::release() {
	if (isClawClosed()) {
		_grabber->Set(!_constants->clawStates.lowerClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawGrabberActuationLoss);
	}
}

void LowerClaw::brakeOn() {
	if (!isBrakeOn()) {
		_brake->Set(_constants->clawStates.lowerClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawBrakeActuationLoss);
	}
}

void LowerClaw::brakeOff() {
	if (isBrakeOn()) {
		_brake->Set(!_constants->clawStates.lowerClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawBrakeActuationLoss);
	}
}

bool LowerClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.lowerClawGrab);
}

bool LowerClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.lowerClawBrakeOn);
}
