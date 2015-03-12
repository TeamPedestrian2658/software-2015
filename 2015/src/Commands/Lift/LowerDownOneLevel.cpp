#include "LowerDownOneLevel.h"

LowerDownOneLevel::LowerDownOneLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowerDownOneLevel::Initialize()
{
	Robot::lift->lowerDownOneLevel();
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
}

// Called repeatedly when this Command is scheduled to run
void LowerDownOneLevel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerDownOneLevel::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerDownOneLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerDownOneLevel::Interrupted()
{

}
