#include "DollyForward.h"

DollyForward::DollyForward()
{
	Requires(Robot::dolly);
}

// Called just before this Command runs the first time
void DollyForward::Initialize()
{
	Robot::dolly->dollyForward();
}

// Called repeatedly when this Command is scheduled to run
void DollyForward::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DollyForward::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DollyForward::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DollyForward::Interrupted()
{

}
