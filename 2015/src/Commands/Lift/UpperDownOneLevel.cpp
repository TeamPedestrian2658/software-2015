#include "UpperDownOneLevel.h"

UpperDownOneLevel::UpperDownOneLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void UpperDownOneLevel::Initialize()
{
	Robot::lift->upperDownOneLevel();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void UpperDownOneLevel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperDownOneLevel::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperDownOneLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperDownOneLevel::Interrupted()
{

}
