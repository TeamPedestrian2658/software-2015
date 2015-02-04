#include "SetToteMover.h"

SetToteMover::SetToteMover(double value) : _value(value) {

}

// Called just before this Command runs the first time
void SetToteMover::Initialize()
{
	Robot::toteMover->setToteMover(_value);
}

// Called repeatedly when this Command is scheduled to run
void SetToteMover::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetToteMover::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetToteMover::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetToteMover::Interrupted()
{

}
