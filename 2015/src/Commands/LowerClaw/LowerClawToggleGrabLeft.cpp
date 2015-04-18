#include "LowerClawToggleGrabLeft.h"

LowerClawToggleGrabLeft::LowerClawToggleGrabLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowerClawToggleGrabLeft::Initialize()
{
	if (Robot::lowerClaw->isClawLeftClosed()) {
		Robot::lowerClaw->releaseLeft();
	} else {
		Robot::lowerClaw->grabLeft();
	}

	Robot::lift->updatePIDCoefficients(Robot::lowerClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void LowerClawToggleGrabLeft::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawToggleGrabLeft::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawToggleGrabLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawToggleGrabLeft::Interrupted()
{

}
