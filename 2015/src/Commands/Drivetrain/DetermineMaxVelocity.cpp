#include "DetermineMaxVelocity.h"
#include "../../RobotMap.h"

DetermineMaxVelocity::DetermineMaxVelocity()
{
	_drivetrain = Robot::drivetrain;
	_timer = new Timer();
	_maxVelocityLeft = 0;
	_maxVelocityRight = 0;
	_numSamples = 0;
	Requires(_drivetrain);
	SetTimeout(RobotMap::constants->driveConstants.velocityTestSampleTime + RobotMap::constants->driveConstants.velocityTestAccelerationTime);
}

// Called just before this Command runs the first time
void DetermineMaxVelocity::Initialize()
{
	_drivetrain->disableEnhancedDriving();
	_timer->Reset();
	_timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DetermineMaxVelocity::Execute()
{
	_drivetrain->setRaw(1, 1);
	if (_timer->Get() > RobotMap::constants->driveConstants.velocityTestAccelerationTime) {
		_maxVelocityLeft += RobotMap::driveEncoderLeft->GetRate();
		_maxVelocityRight += RobotMap::driveEncoderRight->GetRate();
		_numSamples++;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DetermineMaxVelocity::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void DetermineMaxVelocity::End()
{
	Robot::drivetrain->setRaw(0, 0);
	Robot::drivetrain->enableEnhancedDriving();

	_timer->Stop();
	_maxVelocityLeft /= _numSamples;
	_maxVelocityRight /= _numSamples;

	if (_maxVelocityLeft >= _maxVelocityRight) {
		SmartDashboard::PutNumber("Max Velocity", _maxVelocityRight);
	} else {
		SmartDashboard::PutNumber("Max Velocity", _maxVelocityLeft);
	}

	_maxVelocityLeft = 0;
	_maxVelocityRight = 0;
	_numSamples = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DetermineMaxVelocity::Interrupted()
{
	End();
}
