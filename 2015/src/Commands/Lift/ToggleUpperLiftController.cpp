#include "ToggleUpperLiftController.h"

ToggleUpperLiftController::ToggleUpperLiftController()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleUpperLiftController::Initialize()
{
	if (Robot::lift->upperControllerEnabled()) {
		Robot::lift->disableUpperController();
	} else {
		Robot::lift->enableUpperController();
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleUpperLiftController::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleUpperLiftController::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleUpperLiftController::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleUpperLiftController::Interrupted()
{

}
