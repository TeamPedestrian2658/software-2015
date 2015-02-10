#include "DriveSCurve.h"

DriveSCurve::DriveSCurve(double totalTime,
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
	SetTimeout(_totalTime * RobotMap::constants->driveConstants.sCurveTimeoutMultiplier);

	_isComplete = false;

	double _leftInitialVelocity = 0;
	double _rightInitialVelocity = 0;

	double _leftMiddleVelocity = 0;
	double _rightMiddleVelocity = 0;

	double _leftMiddleAcceleration1 = 0;
	double _rightMiddleAcceleration1 = 0;

	double _leftMiddleAcceleration2 = 0;
	double _rightMiddleAcceleration2 = 0;

	double _leftI = 0;
	double _rightI = 0;

	double _leftH = 0;
	double _rightH = 0;

	double _leftJ = 0;
	double _rightJ = 0;

	double _leftK = 0;
	double _rightK = 0;
}

// Called just before this Command runs the first time
void DriveSCurve::Initialize()
{
	_leftInitialVelocity = RobotMap::driveEncoderLeft->GetRate();
	_rightInitialVelocity = RobotMap::driveEncoderRight->GetRate();

	_leftMiddleVelocity = (1.5 * (_leftDistance / _totalTime)) - (_leftInitialVelocity / 4) - (_leftFinalVelocity / 4);
	_rightMiddleVelocity = (1.5 * (_rightDistance / _totalTime)) - (_rightInitialVelocity / 4) - (_rightFinalVelocity / 4);

	_leftMiddleAcceleration1 = (4.5 * ((_leftMiddleVelocity - _leftInitialVelocity) / (_totalTime)));
	_rightMiddleAcceleration1 = (4.5 * ((_rightMiddleVelocity - _rightInitialVelocity) / (_totalTime)));

	_leftMiddleAcceleration2 = (4.5 * ((_leftFinalVelocity - _leftMiddleVelocity) / (_totalTime)));
	_rightMiddleAcceleration2 = (4.5 * ((_rightFinalVelocity - _rightMiddleVelocity) / (_totalTime)));

	_leftH = (4.5 * (_leftMiddleAcceleration1 / _totalTime));
	_rightH = (4.5 * (_rightMiddleAcceleration1 / _totalTime));

	_leftI = ((_leftMiddleAcceleration1 * _totalTime) / 18);
	_rightI = ((_rightMiddleAcceleration1 * _totalTime) / 18);

	_leftJ = (4.5 * (_leftMiddleAcceleration2 / _totalTime));
	_rightJ = (4.5 * (_rightMiddleAcceleration2 / _totalTime));

	_leftK = (_leftMiddleAcceleration2 * _totalTime);
	_rightK = (_rightMiddleAcceleration2 * _totalTime);

	_timer->Reset();
	_timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveSCurve::Execute()
{
	double currentTime = _timer->Get();

	if (currentTime < (.1111 * _totalTime)) {
		double left = (_leftH * currentTime * currentTime) + _leftInitialVelocity;
		double right = (_rightH * currentTime * currentTime) + _rightInitialVelocity;
		_drivetrain->set(left, right);
	} else if (currentTime < (.2222 * _totalTime)) {
		double left = (_leftMiddleAcceleration1 * currentTime) - (_leftI) + _leftInitialVelocity;
		double right = (_rightMiddleAcceleration1 * currentTime) - (_rightI) + _rightInitialVelocity;
		_drivetrain->set(left, right);
	} else if (currentTime < (.3333 * _totalTime)) {
		double left = (3 * _leftMiddleAcceleration1 * currentTime) - (_leftH * currentTime * currentTime) - (5 * _leftI) + _leftInitialVelocity;
		double right = (3 * _rightMiddleAcceleration1 * currentTime) - (_rightH * currentTime * currentTime) - (5 * _rightI) + _rightInitialVelocity;
		_drivetrain->set(left, right);
	} else if (currentTime < (.6666 * _totalTime)) {
		_drivetrain->set(_leftMiddleVelocity, _rightMiddleVelocity);
	} else if (currentTime < (.7777 * _totalTime)) {
		double left = (_leftJ * currentTime * currentTime) - (6 * _leftMiddleAcceleration2 * currentTime) + (2 * _leftK) + _leftMiddleVelocity;
		double right = (_rightJ * currentTime * currentTime) - (6 * _rightMiddleAcceleration2 * currentTime) + (2 * _rightK) + _rightMiddleVelocity;
		_drivetrain->set(left, right);
	} else if (currentTime < (.8888 * _totalTime)) {
		double left = (_leftMiddleAcceleration2 * currentTime) - (.7222 * _leftK) + _leftMiddleVelocity;
		double right = (_rightMiddleAcceleration2 * currentTime) - (.7222 * _rightK) + _rightMiddleVelocity;
		_drivetrain->set(left, right);
	} else if (currentTime < _totalTime) {
		double left = (9 * _leftMiddleAcceleration2 * currentTime) - (_leftJ * currentTime * currentTime) - (4.278 * _leftK) + _leftMiddleVelocity;
		double right = (9 * _rightMiddleAcceleration2 * currentTime) - (_rightJ * currentTime * currentTime) - (4.278 * _rightK) + _rightMiddleVelocity;
		_drivetrain->set(left, right);
	} else {
		_isComplete = true;
		_timer->Stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSCurve::IsFinished()
{
	return _isComplete || IsTimedOut();
}

// Called once after isFinished returns true
void DriveSCurve::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSCurve::Interrupted()
{
	End();
}
