#include "ToggleDolly.h"

ToggleDolly::ToggleDolly()
{
	Requires(Robot::dolly);
}

// Called just before this Command runs the first time
void ToggleDolly::Initialize()
{
	Robot::dolly->setDolly(!Robot::dolly->dollyBack());
}

// Called repeatedly when this Command is scheduled to run
void ToggleDolly::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleDolly::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleDolly::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleDolly::Interrupted()
{

}
