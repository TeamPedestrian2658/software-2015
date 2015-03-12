#include "ControlLift.h"

ControlLift::ControlLift()
{
	_lift = Robot::lift;
	_oi = Robot::oi;
	_upperReadyForInput = true;
	_lowerReadyForInput = true;
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
		if (_lowerReadyForInput) {
			if (-_oi->getOperatorStickLeftY() >= 0.6) {
				_lift->lowerUpOneLevel();
				_lowerReadyForInput = false;
			} else if (-_oi->getOperatorStickLeftY() <= -0.6){
				_lift->lowerDownOneLevel();
				_lowerReadyForInput = false;
			}
		} else if (-_oi->getOperatorStickLeftY() < 0.6 && -_oi->getOperatorStickLeftY() > -0.6) {
			_lowerReadyForInput = true;
		}
	} else {
		_lift->setLowerRaw(_oi->getOperatorStickLeftY());
	}

	if (_lift->upperControllerEnabled()) {
		if (_upperReadyForInput) {
			if (-_oi->getOperatorStickRightY() >= 0.6) {
				_lift->upperUpOneLevel();
				_upperReadyForInput = false;
			}  else if (-_oi->getOperatorStickRightY() <= -0.6) {
				_lift->upperDownOneLevel();
				_upperReadyForInput = false;
			}
		} else if (-_oi->getOperatorStickRightY() < 0.6 && -_oi->getOperatorStickRightY() > -0.6) {
			_upperReadyForInput = true;
		}
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
