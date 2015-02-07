#include "UpperClawBrakeOn.h"

UpperClawBrakeOn::UpperClawBrakeOn()
{
	Requires(Robot::upperClaw);
}

// Called just before this Command runs the first time
void UpperClawBrakeOn::Initialize()
{
	Robot::upperClaw->brakeOn();
}

// Called repeatedly when this Command is scheduled to run
void UpperClawBrakeOn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawBrakeOn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawBrakeOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawBrakeOn::Interrupted()
{

}
