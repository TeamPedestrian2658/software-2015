#include "UpperUpOneLevel.h"

UpperUpOneLevel::UpperUpOneLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void UpperUpOneLevel::Initialize()
{
	Robot::lift->upperUpOneLevel();
}

// Called repeatedly when this Command is scheduled to run
void UpperUpOneLevel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperUpOneLevel::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperUpOneLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperUpOneLevel::Interrupted()
{

}
