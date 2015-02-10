#include "DriveWithJoystick.h"
#include "../../RobotMap.h"

DriveWithJoystick::DriveWithJoystick()
{
	_drivetrain = Robot::drivetrain;
	_driverStick = Robot::oi->getDriverStick();
	_constants = RobotMap::constants;
	_rightVelocity = 0;
	_leftVelocity = 0;
	MAX_VELOCITY = 0;
	ENHANCE_SCALAR = _constants->driveConstants.enhanceScalar;
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
	if (_drivetrain->isHighGear() == _constants->shifterStates.highGear) {
		MAX_VELOCITY = _constants->driveConstants.maxVelocityHigh;
	} else {
		MAX_VELOCITY = _constants->driveConstants.maxVelocityLow;
	}

	if (_drivetrain->enhanceEnabled()) {
		if (_drivetrain->tankEnabled()) {
			if (_drivetrain->slowEnabled()) {
				_leftVelocity = -_driverStick->GetRawAxis(_constants->driverAxes.leftY) * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = -_driverStick->GetRawAxis(_constants->driverAxes.rightY) * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
			} else {
				_leftVelocity = -_driverStick->GetRawAxis(_constants->driverAxes.leftY) * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = -_driverStick->GetRawAxis(_constants->driverAxes.rightY) * ENHANCE_SCALAR * MAX_VELOCITY;
			}
		} else {
			double leftJoy = -_driverStick->GetRawAxis(_constants->driverAxes.leftY) + _driverStick->GetRawAxis(_constants->driverAxes.rightX);
			double rightJoy = -_driverStick->GetRawAxis(_constants->driverAxes.leftY) - _driverStick->GetRawAxis(_constants->driverAxes.rightX);

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
				_leftVelocity = leftJoy * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = rightJoy * SLOW_SCALAR * ENHANCE_SCALAR * MAX_VELOCITY;
			} else {
				_leftVelocity = leftJoy * ENHANCE_SCALAR * MAX_VELOCITY;
				_rightVelocity = rightJoy * ENHANCE_SCALAR * MAX_VELOCITY;
			}
		}
		_drivetrain->set(_leftVelocity, _rightVelocity);
	} else {
		if (_drivetrain->tankEnabled()) {
			if (_drivetrain->slowEnabled()) {
				_drivetrain->setRaw(SLOW_SCALAR * -_driverStick->GetRawAxis(_constants->driverAxes.leftY), SLOW_SCALAR * -_driverStick->GetRawAxis(_constants->driverAxes.rightY));
			} else {
				_drivetrain->setRaw(-_driverStick->GetRawAxis(_constants->driverAxes.leftY), -_driverStick->GetRawAxis(_constants->driverAxes.rightY));
			}
		} else {
			double leftJoy = -_driverStick->GetRawAxis(_constants->driverAxes.leftY) + _driverStick->GetRawAxis(_constants->driverAxes.rightX);
			double rightJoy = -_driverStick->GetRawAxis(_constants->driverAxes.leftY) - _driverStick->GetRawAxis(_constants->driverAxes.rightX);

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

	if (_drivetrain->rumbleEnabled()) {
		double leftOutput = RobotMap::driveTalonLeft->Get();
		double rightOutput = RobotMap::driveTalonRight->Get();

		if (leftOutput < 0) {
			_driverStick->SetRumble(Joystick::kLeftRumble, -leftOutput);
		} else {
			_driverStick->SetRumble(Joystick::kLeftRumble, leftOutput);
		}

		if (rightOutput < 0) {
			_driverStick->SetRumble(Joystick::kRightRumble, -rightOutput);
		} else {
			_driverStick->SetRumble(Joystick::kRightRumble, rightOutput);
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
