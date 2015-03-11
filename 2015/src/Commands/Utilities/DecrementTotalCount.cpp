#include "DecrementTotalCount.h"

DecrementTotalCount::DecrementTotalCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DecrementTotalCount::Initialize()
{
	RobotMap::constants->decrementTotalItems();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::drivetrain->updatePIDCoefficients();
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void DecrementTotalCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DecrementTotalCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DecrementTotalCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DecrementTotalCount::Interrupted()
{

}
