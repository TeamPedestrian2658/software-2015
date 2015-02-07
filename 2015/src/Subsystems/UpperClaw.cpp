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
	_grabber->Set(_constants->clawStates.upperClawGrab);
}

void UpperClaw::release() {
	_grabber->Set(!_constants->clawStates.upperClawGrab);
}

void UpperClaw::brakeOn() {
	_brake->Set(_constants->clawStates.upperClawBrakeOn);
}

void UpperClaw::brakeOff() {
	_brake->Set(!_constants->clawStates.upperClawBrakeOn);
}

bool UpperClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.upperClawGrab);
}

bool UpperClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.upperClawBrakeOn);
}
