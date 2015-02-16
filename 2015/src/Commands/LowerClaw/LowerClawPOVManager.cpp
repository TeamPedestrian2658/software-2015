#include "LowerClawPOVManager.h"

LowerClawPOVManager::LowerClawPOVManager()
{
	_lowerClaw = Robot::lowerClaw;
	_oi = Robot::oi;
}

// Called just before this Command runs the first time
void LowerClawPOVManager::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LowerClawPOVManager::Execute()
{
	if (_oi->getOperatorStickPOV() == 0) {
		_lowerClaw->grabBoth();
	} else if (_oi->getOperatorStickPOV() == 180) {
		_lowerClaw->releaseBoth();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawPOVManager::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LowerClawPOVManager::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawPOVManager::Interrupted()
{

}
