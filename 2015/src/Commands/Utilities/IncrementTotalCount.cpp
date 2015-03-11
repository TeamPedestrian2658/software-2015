#include "IncrementTotalCount.h"

IncrementTotalCount::IncrementTotalCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IncrementTotalCount::Initialize()
{
	RobotMap::constants->incrementTotalItems();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::drivetrain->updatePIDCoefficients();
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void IncrementTotalCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IncrementTotalCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void IncrementTotalCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncrementTotalCount::Interrupted()
{

}
