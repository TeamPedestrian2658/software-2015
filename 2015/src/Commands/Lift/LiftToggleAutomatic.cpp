#include "LiftToggleAutomatic.h"

LiftToggleAutomatic::LiftToggleAutomatic()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LiftToggleAutomatic::Initialize()
{
	if (Robot::lift->automaticEnabled()) {
		Robot::lift->disableAutomatic();
	} else {
		Robot::lift->enableAutomatic();
	}
}

// Called repeatedly when this Command is scheduled to run
void LiftToggleAutomatic::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToggleAutomatic::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LiftToggleAutomatic::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToggleAutomatic::Interrupted()
{

}
