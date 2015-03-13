#include "LowerClaw.h"
#include "../RobotMap.h"

LowerClaw::LowerClaw() : Subsystem("LowerClaw") {
	_constants = RobotMap::constants;
	_leftGrabber = RobotMap::lowerClawLeftGrabber;
	_rightGrabber = RobotMap::lowerClawRightGrabber;
	_leftState = _leftGrabber->Get();
	_rightState = _rightGrabber->Get();
	SmartDashboard::PutString("Lower Claw", "OPEN");
}
    
void LowerClaw::InitDefaultCommand() {

}

void LowerClaw::grabLeft() {
	_leftGrabber->Set(_constants->clawStates.lowerClawLeftGrab);
	_leftState = _constants->clawStates.lowerClawLeftGrab;
	if (isClawRightClosed()) {
		SmartDashboard::PutString("Lower Claw", "CLOSED");
	} else {
		SmartDashboard::PutString("Lower Claw", "LEFT");
	}
}

void LowerClaw::grabRight() {
	_rightGrabber->Set(_constants->clawStates.lowerClawRightGrab);
	_rightState= _constants->clawStates.lowerClawRightGrab;
	if (isClawLeftClosed()) {
		SmartDashboard::PutString("Lower Claw", "CLOSED");
	} else {
		SmartDashboard::PutString("Lower Claw", "RIGHT");
	}
}

void LowerClaw::grabBoth() {
	_leftGrabber->Set(_constants->clawStates.lowerClawLeftGrab);
	_rightGrabber->Set(_constants->clawStates.lowerClawRightGrab);
	_leftState = _constants->clawStates.lowerClawLeftGrab;
	_rightState = _constants->clawStates.lowerClawRightGrab;
	SmartDashboard::PutString("Lower Claw", "CLOSED");
}

void LowerClaw::releaseLeft() {
	_leftGrabber->Set(!_constants->clawStates.lowerClawLeftGrab);
	_leftState = !_constants->clawStates.lowerClawLeftGrab;
	if (isClawRightClosed()) {
		SmartDashboard::PutString("Lower Claw", "RIGHT");
	} else {
		SmartDashboard::PutString("Lower Claw", "OPEN");
	}
}

void LowerClaw::releaseRight() {
	_rightGrabber->Set(!_constants->clawStates.lowerClawRightGrab);
	_rightState = !_constants->clawStates.lowerClawRightGrab;
	if (isClawLeftClosed()) {
		SmartDashboard::PutString("Lower Claw", "LEFT");
	} else {
		SmartDashboard::PutString("Lower Claw", "OPEN");
	}
}

void LowerClaw::releaseBoth() {
	_leftGrabber->Set(!_constants->clawStates.lowerClawLeftGrab);
	_rightGrabber->Set(!_constants->clawStates.lowerClawRightGrab);
	_leftState = !_constants->clawStates.lowerClawLeftGrab;
	_rightState = !_constants->clawStates.lowerClawRightGrab;
	SmartDashboard::PutString("Lower Claw", "OPEN");
}

bool LowerClaw::isClawLeftClosed() {
	return (_leftState == _constants->clawStates.lowerClawLeftGrab);
}

bool LowerClaw::isClawRightClosed() {
	return (_rightState == _constants->clawStates.lowerClawRightGrab);
}

bool LowerClaw::isClawClosed() {
	return (isClawLeftClosed() && isClawRightClosed());
}
