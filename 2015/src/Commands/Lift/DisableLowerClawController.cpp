#include "DisableLowerClawController.h"

DisableLowerClawController::DisableLowerClawController()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DisableLowerClawController::Initialize()
{
	Robot::lift->disableLowerController();
}

// Called repeatedly when this Command is scheduled to run
void DisableLowerClawController::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DisableLowerClawController::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DisableLowerClawController::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DisableLowerClawController::Interrupted()
{

}
