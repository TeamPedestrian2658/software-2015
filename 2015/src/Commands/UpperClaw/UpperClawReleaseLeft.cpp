#include "UpperClawReleaseLeft.h"

UpperClawReleaseLeft::UpperClawReleaseLeft()
{

}

// Called just before this Command runs the first time
void UpperClawReleaseLeft::Initialize()
{
	Robot::upperClaw->releaseLeft();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void UpperClawReleaseLeft::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawReleaseLeft::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawReleaseLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawReleaseLeft::Interrupted()
{

}
