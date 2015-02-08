#include "DollyBack.h"

DollyBack::DollyBack()
{
	Requires(Robot::dolly);
}

// Called just before this Command runs the first time
void DollyBack::Initialize()
{
	Robot::dolly->dollyBack();
}

// Called repeatedly when this Command is scheduled to run
void DollyBack::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DollyBack::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DollyBack::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DollyBack::Interrupted()
{

}
