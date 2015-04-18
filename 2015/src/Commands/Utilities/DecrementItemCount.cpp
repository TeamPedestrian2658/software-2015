#include "DecrementItemCount.h"

DecrementItemCount::DecrementItemCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DecrementItemCount::Initialize()
{
	RobotMap::constants->decrementItemCount();
	Robot::lift->updatePIDCoefficients(Robot::lowerClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void DecrementItemCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DecrementItemCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DecrementItemCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DecrementItemCount::Interrupted()
{

}
