#include "DriverStickRumbleManager.h"

DriverStickRumbleManager::DriverStickRumbleManager()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriverStickRumbleManager::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriverStickRumbleManager::Execute()
{
	double left = RobotMap::driveTalonLeft->Get();
	double right = RobotMap::driveTalonRight->Get();
	if (left < 0) {
		Robot::oi->getDriverStick()->SetRumble(Joystick::kLeftRumble, -left);
	} else {
		Robot::oi->getDriverStick()->SetRumble(Joystick::kLeftRumble, left);
	}
	if (right < 0) {
		Robot::oi->getDriverStick()->SetRumble(Joystick::kRightRumble, -right);
	} else {
		Robot::oi->getDriverStick()->SetRumble(Joystick::kRightRumble, right);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriverStickRumbleManager::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriverStickRumbleManager::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriverStickRumbleManager::Interrupted()
{

}
