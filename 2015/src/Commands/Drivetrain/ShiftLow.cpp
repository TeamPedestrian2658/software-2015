#include "ShiftLow.h"

ShiftLow::ShiftLow()
{
	drivetrain = Robot::drivetrain;
	SetTimeout(RobotMap::constants->driveConstants.shiftTime);
}

// Called just before this Command runs the first time
void ShiftLow::Initialize()
{
	drivetrain->enableSlow();
}

// Called repeatedly when this Command is scheduled to run
void ShiftLow::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShiftLow::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void ShiftLow::End()
{
	drivetrain->shiftLow();
	drivetrain->disableSlow();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftLow::Interrupted()
{

}
