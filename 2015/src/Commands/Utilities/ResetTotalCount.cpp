#include "ResetTotalCount.h"

ResetTotalCount::ResetTotalCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetTotalCount::Initialize()
{
	RobotMap::constants->resetTotalItems();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::drivetrain->updatePIDCoefficients();
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void ResetTotalCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetTotalCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetTotalCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetTotalCount::Interrupted()
{

}
