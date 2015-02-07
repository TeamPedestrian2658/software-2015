#include "LowerClawBrakeOn.h"

LowerClawBrakeOn::LowerClawBrakeOn()
{
	Requires(Robot::lowerClaw);
}

// Called just before this Command runs the first time
void LowerClawBrakeOn::Initialize()
{
	Robot::lowerClaw->brakeOn();
}

// Called repeatedly when this Command is scheduled to run
void LowerClawBrakeOn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawBrakeOn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawBrakeOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawBrakeOn::Interrupted()
{

}
