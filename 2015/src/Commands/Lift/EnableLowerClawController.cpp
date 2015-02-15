#include "EnableLowerClawController.h"

EnableLowerClawController::EnableLowerClawController()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void EnableLowerClawController::Initialize()
{
	Robot::lift->enableLowerController();
}

// Called repeatedly when this Command is scheduled to run
void EnableLowerClawController::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EnableLowerClawController::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EnableLowerClawController::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableLowerClawController::Interrupted()
{

}
