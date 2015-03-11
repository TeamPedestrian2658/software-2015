#include "UpperClaw.h"
#include "../RobotMap.h"

UpperClaw::UpperClaw() : Subsystem("UpperClaw") {
	_constants = RobotMap::constants;
	_leftGrabber = RobotMap::upperClawLeftGrabber;
	_rightGrabber = RobotMap::upperClawRightGrabber;
	SmartDashboard::PutString("Upper Claw", "CLOSED");
}
    
void UpperClaw::InitDefaultCommand() {

}

void UpperClaw::grabLeft() {
	_leftGrabber->Set(_constants->clawStates.upperClawLeftGrab);
	if (isClawRightClosed()) {
		SmartDashboard::PutString("Upper Claw", "CLOSED");
	} else {
		SmartDashboard::PutString("Upper Claw", "LEFT");
	}
}

void UpperClaw::grabRight() {
	_rightGrabber->Set(_constants->clawStates.upperClawRightGrab);
	if (isClawLeftClosed()) {
		SmartDashboard::PutString("Upper Claw", "CLOSED");
	} else {
		SmartDashboard::PutString("Upper Claw", "RIGHT");
	}
}

void UpperClaw::grabBoth() {
	_leftGrabber->Set(_constants->clawStates.upperClawLeftGrab);
	_rightGrabber->Set(_constants->clawStates.upperClawRightGrab);
	SmartDashboard::PutString("Upper Claw", "CLOSED");
}

void UpperClaw::releaseLeft() {
	_leftGrabber->Set(!_constants->clawStates.upperClawLeftGrab);
	if (isClawRightClosed()) {
		SmartDashboard::PutString("Upper Claw", "RIGHT");
	} else {
		SmartDashboard::PutString("Upper Claw", "OPEN");
	}
}

void UpperClaw::releaseRight() {
	_rightGrabber->Set(!_constants->clawStates.upperClawRightGrab);
	if (isClawLeftClosed()) {
		SmartDashboard::PutString("Upper Claw", "LEFT");
	} else {
		SmartDashboard::PutString("Upper Claw", "OPEN");
	}
}

void UpperClaw::releaseBoth() {
	_leftGrabber->Set(!_constants->clawStates.upperClawLeftGrab);
	_rightGrabber->Set(!_constants->clawStates.upperClawRightGrab);
	SmartDashboard::PutString("Upper Claw", "OPEN");
}

bool UpperClaw::isClawLeftClosed() {
	return (_leftGrabber->Get() == _constants->clawStates.upperClawLeftGrab);
}

bool UpperClaw::isClawRightClosed() {
	return (_rightGrabber->Get() == _constants->clawStates.upperClawRightGrab);
}

bool UpperClaw::isClawClosed() {
	return (isClawLeftClosed() && isClawRightClosed());
}
