#include "UpperClawReleaseRight.h"

UpperClawReleaseRight::UpperClawReleaseRight()
{

}

// Called just before this Command runs the first time
void UpperClawReleaseRight::Initialize()
{
	Robot::upperClaw->releaseRight();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void UpperClawReleaseRight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawReleaseRight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawReleaseRight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawReleaseRight::Interrupted()
{

}
