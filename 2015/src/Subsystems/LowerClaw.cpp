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
	_grabber->Set(_constants->clawStates.lowerClawGrab);
}

void LowerClaw::release() {
	_grabber->Set(!_constants->clawStates.lowerClawGrab);
}

void LowerClaw::brakeOn() {
	_brake->Set(_constants->clawStates.lowerClawBrakeOn);
}

void LowerClaw::brakeOff() {
	_brake->Set(!_constants->clawStates.lowerClawBrakeOn);
}

bool LowerClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.lowerClawGrab);
}

bool LowerClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.lowerClawBrakeOn);
}
