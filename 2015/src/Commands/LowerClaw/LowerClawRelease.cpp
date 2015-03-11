#include "LowerClawRelease.h"

LowerClawRelease::LowerClawRelease()
{

}

// Called just before this Command runs the first time
void LowerClawRelease::Initialize()
{
	Robot::lowerClaw->releaseBoth();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void LowerClawRelease::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawRelease::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawRelease::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawRelease::Interrupted()
{

}
