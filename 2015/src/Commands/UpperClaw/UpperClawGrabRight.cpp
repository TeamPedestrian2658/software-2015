#include "UpperClawGrabRight.h"

UpperClawGrabRight::UpperClawGrabRight()
{

}

// Called just before this Command runs the first time
void UpperClawGrabRight::Initialize()
{
	Robot::lowerClaw->grabRight();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void UpperClawGrabRight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawGrabRight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawGrabRight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawGrabRight::Interrupted()
{

}
