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
	_grabber->Set(_constants->clawStates.upperClawGrab);
	SmartDashboard::PutString("Upper Claw", "CLOSED");
}

void UpperClaw::release() {
	_grabber->Set(!_constants->clawStates.upperClawGrab);
	SmartDashboard::PutString("Upper Claw", "OPEN");
}

void UpperClaw::brakeOn() {
	_brake->Set(_constants->clawStates.upperClawBrakeOn);
	SmartDashboard::PutString("Upper Claw Brake", "ENGAGED");
}

void UpperClaw::brakeOff() {
	_brake->Set(!_constants->clawStates.upperClawBrakeOn);
	SmartDashboard::PutString("Upper Claw Brake", "DISENGAGED");
}

bool UpperClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.upperClawGrab);
}

bool UpperClaw::isBrakeOn() {
	return (_brake->Get() == _constants->clawStates.upperClawBrakeOn);
}
