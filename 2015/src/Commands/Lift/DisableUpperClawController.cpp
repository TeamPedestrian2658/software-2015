#include "DisableUpperClawController.h"

DisableUpperClawController::DisableUpperClawController()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DisableUpperClawController::Initialize()
{
	Robot::lift->disableUpperController();
}

// Called repeatedly when this Command is scheduled to run
void DisableUpperClawController::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DisableUpperClawController::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DisableUpperClawController::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DisableUpperClawController::Interrupted()
{

}
