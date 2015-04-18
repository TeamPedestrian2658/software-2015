#include "UpperClawRelease.h"

UpperClawRelease::UpperClawRelease()
{

}

// Called just before this Command runs the first time
void UpperClawRelease::Initialize()
{
	Robot::upperClaw->release();
}

// Called repeatedly when this Command is scheduled to run
void UpperClawRelease::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawRelease::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawRelease::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawRelease::Interrupted()
{

}
