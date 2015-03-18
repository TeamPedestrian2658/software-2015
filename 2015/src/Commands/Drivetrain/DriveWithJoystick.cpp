#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick()
{
	_drivetrain = Robot::drivetrain;
	_oi = Robot::oi;
	_constants = RobotMap::constants;
	_rightVelocity = 0;
	_leftVelocity = 0;
	MAX_VELOCITY = 0;
	SLOW_SCALAR = _constants->driveConstants.slowScalar;
	Requires(_drivetrain);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	if (_drivetrain->isHighGear()) {
		MAX_VELOCITY = _constants->driveConstants.currentEnhancedMaxVelocityHigh;
	} else {
		MAX_VELOCITY = _constants->driveConstants.currentEnhancedMaxVelocityLow;
	}

	if (_drivetrain->enhanceEnabled()) {
		if (_drivetrain->tankEnabled()) {
			if (_drivetrain->slowEnabled()) {
				_leftVelocity = -_oi->getDriverStickLeftY() * SLOW_SCALAR * MAX_VELOCITY;
				_rightVelocity = -_oi->getDriverStickRightY() * SLOW_SCALAR * MAX_VELOCITY;
			} else {
				_leftVelocity = -_oi->getDriverStickLeftY() * MAX_VELOCITY;
				_rightVelocity = -_oi->getDriverStickRightY() * MAX_VELOCITY;
			}
		} else {
			double leftJoy = -_oi->getDriverStickLeftY() + _oi->getDriverStickRightX();
			double rightJoy = -_oi->getDriverStickLeftY() - _oi->getDriverStickRightX();

			if (leftJoy > 1.0) {
				leftJoy = 1.0;
			} else if (leftJoy < -1.0) {
				leftJoy = -1.0;
			}

			if (rightJoy > 1.0) {
				rightJoy = 1.0;
			} else if (rightJoy < -1.0) {
				rightJoy = -1.0;
			}

			if (_drivetrain->slowEnabled()) {
				_leftVelocity = leftJoy * SLOW_SCALAR * MAX_VELOCITY;
				_rightVelocity = rightJoy * SLOW_SCALAR * MAX_VELOCITY;
			} else {
				_leftVelocity = leftJoy * MAX_VELOCITY;
				_rightVelocity = rightJoy * MAX_VELOCITY;
			}
		}
		_drivetrain->set(_leftVelocity, _rightVelocity);
	} else {
		if (_drivetrain->tankEnabled()) {
			if (_drivetrain->slowEnabled()) {
				_drivetrain->setRaw(SLOW_SCALAR * -_oi->getDriverStickLeftY(), SLOW_SCALAR * -_oi->getDriverStickRightY());
			} else {
				_drivetrain->setRaw(-_oi->getDriverStickLeftY(), -_oi->getDriverStickRightY());
			}
		} else {
			double leftJoy = -_oi->getDriverStickLeftY() + _oi->getDriverStickRightX();
			double rightJoy = -_oi->getDriverStickLeftY() - _oi->getDriverStickRightX();

			if (leftJoy > 1.0) {
				leftJoy = 1.0;
			} else if (leftJoy < -1.0) {
				leftJoy = -1.0;
			}

			if (rightJoy > 1.0) {
				rightJoy = 1.0;
			} else if (rightJoy < -1.0) {
				rightJoy = -1.0;
			}

			if (_drivetrain->slowEnabled()) {
				_drivetrain->setRaw(SLOW_SCALAR * leftJoy, SLOW_SCALAR * rightJoy);
			} else {
				_drivetrain->setRaw(leftJoy, rightJoy);
			}
		}
	}

	if (_constants->debug) {
		SmartDashboard::PutNumber("Left Velocity", RobotMap::driveEncoderLeft->GetRate());
		SmartDashboard::PutNumber("Right Velocity", RobotMap::driveEncoderRight->GetRate());
	}

	if (_drivetrain->rumbleEnabled()) {
		double leftOutput = RobotMap::driveTalonLeft->Get();
		double rightOutput = RobotMap::driveTalonRight->Get();

		if (leftOutput < 0) {
			_oi->getDriverStick()->SetRumble(Joystick::kLeftRumble, -leftOutput);
		} else {
			_oi->getDriverStick()->SetRumble(Joystick::kLeftRumble, leftOutput);
		}

		if (rightOutput < 0) {
			_oi->getDriverStick()->SetRumble(Joystick::kRightRumble, -rightOutput);
		} else {
			_oi->getDriverStick()->SetRumble(Joystick::kRightRumble, rightOutput);
		}
	} else {
		_oi->getDriverStick()->SetRumble(Joystick::kLeftRumble, 0);
		_oi->getDriverStick()->SetRumble(Joystick::kRightRumble, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted()
{

}
