#include "UpperClawToggleGrab.h"

UpperClawToggleGrab::UpperClawToggleGrab()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void UpperClawToggleGrab::Initialize()
{
	if (Robot::upperClaw->isClawClosed()) {
		Robot::upperClaw->release();
	} else {
		Robot::upperClaw->grab();
	}
}

// Called repeatedly when this Command is scheduled to run
void UpperClawToggleGrab::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawToggleGrab::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawToggleGrab::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawToggleGrab::Interrupted()
{

}
