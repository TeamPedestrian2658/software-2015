#include "LowerClawReleaseLeft.h"

LowerClawReleaseLeft::LowerClawReleaseLeft()
{

}

// Called just before this Command runs the first time
void LowerClawReleaseLeft::Initialize()
{
	Robot::lowerClaw->releaseLeft();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void LowerClawReleaseLeft::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawReleaseLeft::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawReleaseLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawReleaseLeft::Interrupted()
{

}
