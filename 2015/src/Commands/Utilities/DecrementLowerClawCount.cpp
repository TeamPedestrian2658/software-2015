#include "DecrementLowerClawCount.h"

DecrementLowerClawCount::DecrementLowerClawCount()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DecrementLowerClawCount::Initialize()
{
	RobotMap::constants->decrementLowerClawItems();
	Robot::drivetrain->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void DecrementLowerClawCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DecrementLowerClawCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DecrementLowerClawCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DecrementLowerClawCount::Interrupted()
{

}
