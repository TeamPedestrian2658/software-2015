#include "ControlLift.h"

ControlLift::ControlLift()
{
	_lift = Robot::lift;
	_oi = Robot::oi;
	_readyForInput = true;
	Requires(_lift);
}

// Called just before this Command runs the first time
void ControlLift::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlLift::Execute()
{

	if (_lift->automaticEnabled()) {
		if (_readyForInput) {
			if (-_oi->getOperatorStickLeftY() >= 0.6) {
				_lift->upOneLevel();
				_readyForInput = false;
			} else if (-_oi->getOperatorStickLeftY() <= -0.6){
				_lift->downOneLevel();
				_readyForInput = false;
			}
		} else if (-_oi->getOperatorStickLeftY() < 0.6 && -_oi->getOperatorStickLeftY() > -0.6) {
			_readyForInput = true;
		}
	} else {
		_lift->setRaw(_oi->getOperatorStickLeftY());
	}

	if (RobotMap::constants->debug) {
		SmartDashboard::PutNumber("Lift Height", _lift->getHeight());
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
