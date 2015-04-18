#include "IncrementItemCount.h"

IncrementItemCount::IncrementItemCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IncrementItemCount::Initialize()
{
	RobotMap::constants->incrementItemCount();
	Robot::lift->updatePIDCoefficients(Robot::lowerClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void IncrementItemCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IncrementItemCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void IncrementItemCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncrementItemCount::Interrupted()
{

}
