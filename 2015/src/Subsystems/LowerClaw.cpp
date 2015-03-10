#include "LowerClaw.h"
#include "../RobotMap.h"
#include "../Commands/LowerClaw/LowerClawPOVManager.h"

LowerClaw::LowerClaw() : Subsystem("LowerClaw") {
	_constants = RobotMap::constants;
	_leftGrabber = RobotMap::lowerClawLeftGrabber;
	_rightGrabber = RobotMap::lowerClawRightGrabber;
	SmartDashboard::PutString("Lower Claw", "OPEN");
}
    
void LowerClaw::InitDefaultCommand() {
	SetDefaultCommand(new LowerClawPOVManager());
}

void LowerClaw::grabLeft() {
	_leftGrabber->Set(_constants->clawStates.lowerClawLeftGrab);
	if (isClawRightClosed()) {
		SmartDashboard::PutString("Lower Claw", "CLOSED");
	} else {
		SmartDashboard::PutString("Lower Claw", "LEFT");
	}
}

void LowerClaw::grabRight() {
	_rightGrabber->Set(_constants->clawStates.lowerClawRightGrab);
	if (isClawLeftClosed()) {
		SmartDashboard::PutString("Lower Claw", "CLOSED");
	} else {
		SmartDashboard::PutString("Lower Claw", "RIGHT");
	}
}

void LowerClaw::grabBoth() {
	_leftGrabber->Set(_constants->clawStates.lowerClawLeftGrab);
	_rightGrabber->Set(_constants->clawStates.lowerClawRightGrab);
	SmartDashboard::PutString("Lower Claw", "CLOSED");
}

void LowerClaw::releaseLeft() {
	_leftGrabber->Set(!_constants->clawStates.lowerClawLeftGrab);
	if (isClawRightClosed()) {
		SmartDashboard::PutString("Lower Claw", "RIGHT");
	} else {
		SmartDashboard::PutString("Lower Claw", "OPEN");
	}
}

void LowerClaw::releaseRight() {
	_rightGrabber->Set(!_constants->clawStates.lowerClawRightGrab);
	if (isClawLeftClosed()) {
		SmartDashboard::PutString("Lower Claw", "LEFT");
	} else {
		SmartDashboard::PutString("Lower Claw", "OPEN");
	}
}

void LowerClaw::releaseBoth() {
	_leftGrabber->Set(!_constants->clawStates.lowerClawLeftGrab);
	_rightGrabber->Set(!_constants->clawStates.lowerClawRightGrab);
	SmartDashboard::PutString("Lower Claw", "OPEN");
}

bool LowerClaw::isClawLeftClosed() {
	return (_leftGrabber->Get() == _constants->clawStates.lowerClawLeftGrab);
}

bool LowerClaw::isClawRightClosed() {
	return (_rightGrabber->Get() == _constants->clawStates.lowerClawRightGrab);
}

bool LowerClaw::isClawClosed() {
	return (isClawLeftClosed() && isClawRightClosed());
}
