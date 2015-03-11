#include "ControlLift.h"

ControlLift::ControlLift()
{
	_lift = Robot::lift;
	_oi = Robot::oi;
	Requires(_lift);
}

// Called just before this Command runs the first time
void ControlLift::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlLift::Execute()
{

	if (_lift->lowerControllerEnabled()) {
		//implement this
	} else {
		_lift->setLowerRaw(_oi->getOperatorStickLeftY());
	}

	if (_lift->upperControllerEnabled()) {
		//implement this
	} else {
		_lift->setUpperRaw(_oi->getOperatorStickRightY());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLift::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlLift::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlLift::Interrupted()
{

}
