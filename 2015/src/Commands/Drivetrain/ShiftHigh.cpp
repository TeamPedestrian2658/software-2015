#include "ShiftHigh.h"

ShiftHigh::ShiftHigh()
{

}

// Called just before this Command runs the first time
void ShiftHigh::Initialize()
{
	Robot::drivetrain->shiftHigh();
}

// Called repeatedly when this Command is scheduled to run
void ShiftHigh::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShiftHigh::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShiftHigh::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftHigh::Interrupted()
{

}
