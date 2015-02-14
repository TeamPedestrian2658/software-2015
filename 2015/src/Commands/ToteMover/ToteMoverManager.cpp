#include "ToteMoverManager.h"

ToteMoverManager::ToteMoverManager()
{
	_oi = Robot::oi;
	_constants = RobotMap::constants;
	Requires(Robot::toteMover);
}

// Called just before this Command runs the first time
void ToteMoverManager::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToteMoverManager::Execute()
{
	if (_oi->getOperatorStickPOV() == _constants->operatorButtons.toteMoverLeftPOV) {
		Robot::toteMover->moveTotesLeft();
	} else if (_oi->getOperatorStickPOV() == _constants->operatorButtons.toteMoverRightPOV) {
		Robot::toteMover->moveTotesRight();
	} else {
		Robot::toteMover->stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ToteMoverManager::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ToteMoverManager::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteMoverManager::Interrupted()
{

}
