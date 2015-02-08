#include "UpperClawBrakeOff.h"

UpperClawBrakeOff::UpperClawBrakeOff()
{
	Requires(Robot::upperClaw);
}

// Called just before this Command runs the first time
void UpperClawBrakeOff::Initialize()
{
	Robot::upperClaw->brakeOff();
}

// Called repeatedly when this Command is scheduled to run
void UpperClawBrakeOff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpperClawBrakeOff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpperClawBrakeOff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpperClawBrakeOff::Interrupted()
{

}
