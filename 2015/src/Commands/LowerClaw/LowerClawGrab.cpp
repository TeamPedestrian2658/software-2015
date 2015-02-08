#include "LowerClawGrab.h"

LowerClawGrab::LowerClawGrab()
{
	Requires(Robot::lowerClaw);
}

// Called just before this Command runs the first time
void LowerClawGrab::Initialize()
{
	Robot::lowerClaw->grab();
}

// Called repeatedly when this Command is scheduled to run
void LowerClawGrab::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawGrab::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawGrab::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawGrab::Interrupted()
{

}
