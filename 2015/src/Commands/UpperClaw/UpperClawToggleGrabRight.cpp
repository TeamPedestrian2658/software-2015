#include "UpperClawToggleGrabRight.h"

UpperClawToggleGrabRight::UpperClawToggleGrabRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void UpperClawToggleGrabRight::Initialize()
{
	if (Robot::upperClaw->isClawRightClosed()) {
		Robot::upperClaw->releaseRight();
	} else {
		Robot::upperClaw->grabRight();
	}
}

// Called repeatedly when this Command is scheduled to run
void UpperClawToggleGrabRight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawToggleGrabRight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawToggleGrabRight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawToggleGrabRight::Interrupted()
{

}
