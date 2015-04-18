#include "UpperClaw.h"
#include "../RobotMap.h"

UpperClaw::UpperClaw() : Subsystem("UpperClaw") {
	_constants = RobotMap::constants;
	_grabber = RobotMap::upperClawGrabber;
	_clawState = _grabber->Get();
	SmartDashboard::PutString("Upper Claw", "OPEN");
}
    
void UpperClaw::InitDefaultCommand() {

}

void UpperClaw::grab() {
	_grabber->Set(_constants->clawStates.upperClawGrab);
	_clawState = _constants->clawStates.upperClawGrab;
	SmartDashboard::PutString("Upper Claw", "CLOSED");
}

void UpperClaw::release() {
	_grabber->Set(!_constants->clawStates.upperClawGrab);
	_clawState = !_constants->clawStates.upperClawGrab;
	SmartDashboard::PutString("Upper Claw", "OPEN");
}

bool UpperClaw::isClawClosed() {
	return (_clawState == _constants->clawStates.upperClawGrab);
}
