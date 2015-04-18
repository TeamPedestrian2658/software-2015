#include "LiftUpOneLevel.h"

LiftUpOneLevel::LiftUpOneLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LiftUpOneLevel::Initialize()
{
	Robot::lift->upOneLevel();
}

// Called repeatedly when this Command is scheduled to run
void LiftUpOneLevel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftUpOneLevel::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LiftUpOneLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftUpOneLevel::Interrupted()
{

}
