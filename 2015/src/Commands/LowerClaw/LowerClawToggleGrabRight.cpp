#include "LowerClawToggleGrabRight.h"

LowerClawToggleGrabRight::LowerClawToggleGrabRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowerClawToggleGrabRight::Initialize()
{
	if (Robot::lowerClaw->isClawRightClosed()) {
		Robot::lowerClaw->releaseRight();
	} else {
		Robot::lowerClaw->grabRight();
	}

	Robot::lift->updatePIDCoefficients(Robot::lowerClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void LowerClawToggleGrabRight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawToggleGrabRight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawToggleGrabRight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawToggleGrabRight::Interrupted()
{

}
