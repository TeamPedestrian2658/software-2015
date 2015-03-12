#include "LowerUpOneLevel.h"

LowerUpOneLevel::LowerUpOneLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowerUpOneLevel::Initialize()
{
	Robot::lift->lowerUpOneLevel();
}

// Called repeatedly when this Command is scheduled to run
void LowerUpOneLevel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerUpOneLevel::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerUpOneLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerUpOneLevel::Interrupted()
{

}
