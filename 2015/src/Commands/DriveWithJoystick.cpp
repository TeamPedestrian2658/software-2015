#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick()
{
	_driverStick = Robot::oi->getDriverStick();
	_rightVelocity = 0;
	_leftVelocity = 0;
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	if (Robot::drivetrain->enhanceEnabled()) {
		if (Robot::drivetrain->tankEnabled()) {
			if (Robot::drivetrain->slowEnabled()) {
				_leftVelocity = _driverStick->GetRawAxis(0) * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = _driverStick->GetRawAxis(1) * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
			} else {
				_leftVelocity = _driverStick->GetRawAxis(0) * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = _driverStick->GetRawAxis(1) * ENHANCE_SCALAR * MAX_VELOCITY;
			}
		} else {
			double leftJoy =_driverStick->GetRawAxis(0) + _driverStick->GetRawAxis(2);
			double rightJoy = _driverStick->GetRawAxis(0) - _driverStick->GetRawAxis(2);

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

			if (Robot::drivetrain->slowEnabled()) {
				_leftVelocity = leftJoy * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = rightJoy * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
			} else {
				_leftVelocity = leftJoy * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = rightJoy * ENHANCE_SCALAR * MAX_VELOCITY;
			}
		}
		Robot::drivetrain->set(_leftVelocity, _rightVelocity);
	} else {
		if (Robot::drivetrain->tankEnabled()) {
			if (Robot::drivetrain->slowEnabled()) {
				Robot::drivetrain->setRaw(SLOW_SCALAR * _driverStick->GetRawAxis(0), SLOW_SCALAR * _driverStick->GetRawAxis(1));
			} else {
				Robot::drivetrain->setRaw(_driverStick->GetRawAxis(0), _driverStick->GetRawAxis(1));
			}
		} else {
			double leftJoy =_driverStick->GetRawAxis(0) + _driverStick->GetRawAxis(2);
			double rightJoy = _driverStick->GetRawAxis(0) - _driverStick->GetRawAxis(2);

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

			if (Robot::drivetrain->slowEnabled()) {
				Robot::drivetrain->setRaw(SLOW_SCALAR * leftJoy, SLOW_SCALAR * rightJoy);
			} else {
				Robot::drivetrain->setRaw(leftJoy, rightJoy);
			}
		}
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
