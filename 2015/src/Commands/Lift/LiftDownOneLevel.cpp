#include "LiftDownOneLevel.h"

LiftDownOneLevel::LiftDownOneLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LiftDownOneLevel::Initialize()
{
	Robot::lift->downOneLevel();
}

// Called repeatedly when this Command is scheduled to run
void LiftDownOneLevel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftDownOneLevel::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LiftDownOneLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftDownOneLevel::Interrupted()
{

}
