#include "ToggleLowerLiftController.h"

ToggleLowerLiftController::ToggleLowerLiftController()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleLowerLiftController::Initialize()
{
	if (Robot::lift->lowerControllerEnabled()) {
		Robot::lift->disableLowerController();
	} else {
		Robot::lift->enableLowerController();
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleLowerLiftController::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLowerLiftController::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleLowerLiftController::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLowerLiftController::Interrupted()
{

}
