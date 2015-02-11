#include "DriveTrapezoidal.h"

DriveTrapezoidal::DriveTrapezoidal(double totalTime,
		 	 	 	 	 	 	   double leftDistance,
								   double rightDistance,
								   double leftFinalVelocity,
								   double rightFinalVelocity) :
								   _totalTime(totalTime),
								   _leftDistance(leftDistance),
								   _rightDistance(rightDistance),
								   _leftFinalVelocity(leftFinalVelocity),
								   _rightFinalVelocity(rightFinalVelocity)
{
	_drivetrain = Robot::drivetrain;
	Requires(_drivetrain);

	_timer = new Timer();

	_isComplete = false;

	_enhancedMaxVelocityLow = RobotMap::constants->driveConstants.enhanceScalar
			* RobotMap::constants->driveConstants.maxVelocityLow;
	_enhancedMaxVelocityHigh = RobotMap::constants->driveConstants.enhanceScalar
			* RobotMap::constants->driveConstants.maxVelocityHigh;

	_leftInitialVelocity = 0;
	_rightInitialVelocity = 0;

	_leftMiddleVelocity = 0;
	_rightMiddleVelocity = 0;

	_leftAcceleration1 = 0;
	_rightAcceleration1 = 0;

	_leftAcceleration2 = 0;
	_rightAcceleration2 = 0;
}

// Called just before this Command runs the first time
void DriveTrapezoidal::Initialize()
{
	_leftInitialVelocity = RobotMap::driveEncoderLeft->GetRate();
	_rightInitialVelocity = RobotMap::driveEncoderRight->GetRate();

	adjustFinalVelocities();

	_leftMiddleVelocity = (1.5 * (_leftDistance / _totalTime)) - (_leftInitialVelocity / 4) - (_leftFinalVelocity / 4);
	_rightMiddleVelocity = (1.5 * (_rightDistance / _totalTime)) - (_rightInitialVelocity / 4) - (_rightFinalVelocity / 4);

	adjustTotalTime();

	_leftAcceleration1 = (3 * (_leftMiddleVelocity - _leftInitialVelocity)) / _totalTime;
	_rightAcceleration1 = (3 * (_rightMiddleVelocity - _rightInitialVelocity)) / _totalTime;

	_leftAcceleration2 = (3 * (_leftFinalVelocity - _leftMiddleVelocity)) / _totalTime;
	_rightAcceleration2 = (3 * (_rightFinalVelocity - _rightMiddleVelocity)) / _totalTime;

	_timer->Reset();
	_timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveTrapezoidal::Execute()
{
	double currentTime = _timer->Get();

	if (currentTime < (.3333 * _totalTime)) {
		double left = (_leftAcceleration1 * currentTime) + _leftInitialVelocity;
		double right = (_rightAcceleration1 * currentTime) + _rightInitialVelocity;
		_drivetrain->set(left, right);
	} else if (currentTime < (.6666 * _totalTime)) {
		_drivetrain->set(_leftMiddleVelocity, _rightMiddleVelocity);
	} else if (currentTime < _totalTime) {
		double left = (_leftAcceleration2 * currentTime) - (2 * _leftFinalVelocity) + (3 * _leftMiddleVelocity);
		double right = (_rightAcceleration2 * currentTime) - (2 * _rightFinalVelocity) + (3 * _rightMiddleVelocity);
	} else {
		_isComplete = true;
		_timer->Stop();
	}

	SmartDashboard::PutNumber("Left Velocity", RobotMap::driveEncoderLeft->GetRate());
	SmartDashboard::PutNumber("Right Velocity", RobotMap::driveEncoderRight->GetRate());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTrapezoidal::IsFinished()
{
	return _isComplete;
}

// Called once after isFinished returns true
void DriveTrapezoidal::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTrapezoidal::Interrupted()
{
	End();
}

void DriveTrapezoidal::adjustFinalVelocities() {
	if (_leftFinalVelocity < -_enhancedMaxVelocityLow || _leftFinalVelocity > _enhancedMaxVelocityLow) {
		_drivetrain->shiftHigh();
		if (_leftFinalVelocity > _enhancedMaxVelocityHigh) {
			_leftFinalVelocity = _enhancedMaxVelocityHigh;
		} else if (_leftFinalVelocity < -_enhancedMaxVelocityHigh) {
			_leftFinalVelocity = -_enhancedMaxVelocityHigh;
		}
	} else {
		_drivetrain->shiftLow();
	}

	if (_leftFinalVelocity < -_enhancedMaxVelocityLow || _rightFinalVelocity > _enhancedMaxVelocityLow) {
		_drivetrain->shiftHigh();
		if (_rightFinalVelocity > _enhancedMaxVelocityHigh) {
			_rightFinalVelocity = _enhancedMaxVelocityHigh;
		} else if (_rightFinalVelocity < -_enhancedMaxVelocityHigh) {
			_rightFinalVelocity = -_enhancedMaxVelocityHigh;
		}
	} else {
		_drivetrain->shiftLow();
	}
}

void DriveTrapezoidal::adjustTotalTime() {
	double actualTimeLeft = _totalTime;
	double actualTimeRight = _totalTime;

	if (_leftMiddleVelocity > _enhancedMaxVelocityLow) {
		_drivetrain->shiftHigh();
		if (_leftMiddleVelocity > _enhancedMaxVelocityHigh) {
			actualTimeLeft = (3 * _leftDistance) /
					((2 * _enhancedMaxVelocityHigh) + (_leftInitialVelocity / 2) + (_leftFinalVelocity / 2));
		}
	} else {
		_drivetrain->shiftLow();
	}

	if (_rightMiddleVelocity > _enhancedMaxVelocityLow) {
		_drivetrain->shiftHigh();
		if (_rightMiddleVelocity > _enhancedMaxVelocityHigh) {
			actualTimeRight = (3 * _rightDistance) /
					((2 * _enhancedMaxVelocityHigh) + (_rightInitialVelocity / 2) + (_rightFinalVelocity / 2));
		}
	} else {
		_drivetrain->shiftLow();
	}

	if (actualTimeLeft >= actualTimeRight) {
		_totalTime = actualTimeLeft;
	} else if (actualTimeRight > actualTimeLeft) {
		_totalTime = actualTimeRight;
	}

	_leftMiddleVelocity = (1.5 * (_leftDistance / _totalTime)) - (_leftInitialVelocity / 4) - (_leftFinalVelocity / 4);
	_rightMiddleVelocity = (1.5 * (_rightDistance / _totalTime)) - (_rightInitialVelocity / 4) - (_rightFinalVelocity / 4);
}
