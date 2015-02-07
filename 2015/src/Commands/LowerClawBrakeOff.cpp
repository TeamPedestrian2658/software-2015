#include "LowerClawBrakeOff.h"

LowerClawBrakeOff::LowerClawBrakeOff()
{
	Requires(Robot::lowerClaw);
}

// Called just before this Command runs the first time
void LowerClawBrakeOff::Initialize()
{
	Robot::lowerClaw->brakeOff();
}

// Called repeatedly when this Command is scheduled to run
void LowerClawBrakeOff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawBrakeOff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawBrakeOff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawBrakeOff::Interrupted()
{

}
