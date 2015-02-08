#include "UpperClaw.h"
#include "../RobotMap.h"

UpperClaw::UpperClaw() : Subsystem("UpperClaw") {
	_constants = RobotMap::constants;
	_grabber = RobotMap::upperClawGrabber;
	_brake = RobotMap::upperClawBrake;
	SmartDashboard::PutString("Upper Claw", "OPEN");
	SmartDashboard::PutString("Upper Claw Brake", "DISENGAGED");
}
    
void UpperClaw::InitDefaultCommand() {

}

void UpperClaw::grab() {
	if (!isClawClosed()) {
		_grabber->Set(_constants->clawStates.upperClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawGrabberActuationLoss);
		SmartDashboard::PutString("Upper Claw", "CLOSED");
	}
}

void UpperClaw::release() {
	if (isClawClosed()) {
		_grabber->Set(!_constants->clawStates.upperClawGrab);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawGrabberActuationLoss);
		SmartDashboard::PutString("Upper Claw", "OPEN");
	}
}

void UpperClaw::brakeOn() {
	if (!isBrakeOn()) {
		_brake->Set(_constants->clawStates.upperClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawBrakeActuationLoss);
		SmartDashboard::PutString("Upper Claw Brake", "ENGAGED");
	}
}

void UpperClaw::brakeOff() {
	if (isBrakeOn()) {
		_brake->Set(!_constants->clawStates.upperClawBrakeOn);
		_constants->reducePressure(_constants->pneumaticConstants.upperClawBrakeActuationLoss);
		SmartDashboard::PutString("Upper Claw Brake", "DISENGAGED");
	}
}

bool UpperClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.upperClawGrab);
}

bool UpperClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.upperClawBrakeOn);
}
