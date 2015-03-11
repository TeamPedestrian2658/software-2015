#include "UpperClawGrabLeft.h"

UpperClawGrabLeft::UpperClawGrabLeft()
{

}

// Called just before this Command runs the first time
void UpperClawGrabLeft::Initialize()
{
	Robot::upperClaw->grabLeft();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void UpperClawGrabLeft::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawGrabLeft::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawGrabLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawGrabLeft::Interrupted()
{

}
