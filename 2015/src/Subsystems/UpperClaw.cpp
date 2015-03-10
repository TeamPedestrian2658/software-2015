#include "UpperClaw.h"
#include "../RobotMap.h"

UpperClaw::UpperClaw() : Subsystem("UpperClaw") {
	_constants = RobotMap::constants;
	_grabber = RobotMap::upperClawGrabber;
	SmartDashboard::PutString("Upper Claw", "OPEN");
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

bool UpperClaw::isClawClosed() {
	return (_grabber->Get() == _constants->clawStates.upperClawGrab);
}
