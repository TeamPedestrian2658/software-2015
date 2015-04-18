#include "ResetItemCount.h"

ResetItemCount::ResetItemCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetItemCount::Initialize()
{
	RobotMap::constants->resetItemCount();
	Robot::lift->updatePIDCoefficients(Robot::lowerClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void ResetItemCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetItemCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetItemCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetItemCount::Interrupted()
{

}
