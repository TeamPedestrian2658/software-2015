#include "LiftDisableAutomatic.h"

LiftDisableAutomatic::LiftDisableAutomatic()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LiftDisableAutomatic::Initialize()
{
	Robot::lift->disableAutomatic();
}

// Called repeatedly when this Command is scheduled to run
void LiftDisableAutomatic::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftDisableAutomatic::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LiftDisableAutomatic::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftDisableAutomatic::Interrupted()
{

}
