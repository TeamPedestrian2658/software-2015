#include "LowerClawGrabLeft.h"

LowerClawGrabLeft::LowerClawGrabLeft()
{

}

// Called just before this Command runs the first time
void LowerClawGrabLeft::Initialize()
{
	Robot::lowerClaw->grabLeft();
}

// Called repeatedly when this Command is scheduled to run
void LowerClawGrabLeft::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawGrabLeft::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawGrabLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawGrabLeft::Interrupted()
{

}
