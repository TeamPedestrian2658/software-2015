#include "LowerClaw.h"
#include "../RobotMap.h"

LowerClaw::LowerClaw() : Subsystem("LowerClaw") {
	_constants = RobotMap::constants;
	_grabber = RobotMap::lowerClawGrabber;
	_brake = RobotMap::lowerClawBrake;
	SmartDashboard::PutString("Lower Claw", "OPEN");
	SmartDashboard::PutString("Lower Claw Brake", "DISENGAGED");
}
    
void LowerClaw::InitDefaultCommand() {

}

void LowerClaw::grab() {
	if (!isClawClosed()) {
		_grabber->Set(_constants->clawStates.lowerClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawGrabberActuationLoss);
		SmartDashboard::PutString("Lower Claw", "CLOSED");
	}
}

void LowerClaw::release() {
	if (isClawClosed()) {
		_grabber->Set(!_constants->clawStates.lowerClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawGrabberActuationLoss);
		SmartDashboard::PutString("Lower Claw", "CLOSED");
	}
}

void LowerClaw::brakeOn() {
	if (!isBrakeOn()) {
		_brake->Set(_constants->clawStates.lowerClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawBrakeActuationLoss);
		SmartDashboard::PutString("Lower Claw Brake", "ENGAGED");
	}
}

void LowerClaw::brakeOff() {
	if (isBrakeOn()) {
		_brake->Set(!_constants->clawStates.lowerClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.lowerClawBrakeActuationLoss);
		SmartDashboard::PutString("Lower Claw Brake", "DISENGAGED");
	}
}

bool LowerClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.lowerClawGrab);
}

bool LowerClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.lowerClawBrakeOn);
}
