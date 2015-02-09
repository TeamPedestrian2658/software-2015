#include "EnableSlow.h"

EnableSlow::EnableSlow()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void EnableSlow::Initialize()
{
	Robot::drivetrain->enableSlow();
}

// Called repeatedly when this Command is scheduled to run
void EnableSlow::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EnableSlow::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EnableSlow::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableSlow::Interrupted()
{

}
