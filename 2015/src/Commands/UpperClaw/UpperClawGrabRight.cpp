#include "UpperClawGrabRight.h"

UpperClawGrabRight::UpperClawGrabRight()
{

}

// Called just before this Command runs the first time
void UpperClawGrabRight::Initialize()
{
	Robot::lowerClaw->grabRight();
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
