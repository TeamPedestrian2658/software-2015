#include "UpperClawGrab.h"

UpperClawGrab::UpperClawGrab()
{
	Requires(Robot::upperClaw);
}

// Called just before this Command runs the first time
void UpperClawGrab::Initialize()
{
	Robot::upperClaw->grab();
}

// Called repeatedly when this Command is scheduled to run
void UpperClawGrab::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawGrab::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawGrab::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawGrab::Interrupted()
{

}
