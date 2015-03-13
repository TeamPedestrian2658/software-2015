#include "LowerClawToggleGrab.h"

LowerClawToggleGrab::LowerClawToggleGrab()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowerClawToggleGrab::Initialize()
{
	if (Robot::lowerClaw->isClawClosed()) {
		Robot::lowerClaw->releaseBoth();
	} else if (Robot::lowerClaw->isClawLeftClosed()) {
		Robot::lowerClaw->releaseLeft();
	} else if (Robot::lowerClaw->isClawRightClosed()) {
		Robot::lowerClaw->releaseRight();
	} else {
		Robot::lowerClaw->grabBoth();
	}
	RobotMap::constants->calculateClawItems(Robot::lift->getLowerPossessionLevel(),
											Robot::lift->getUpperPossessionLevel(),
											Robot::lowerClaw->isClawClosed(),
											Robot::upperClaw->isClawClosed());
	Robot::lift->updatePIDCoefficients();
}

// Called repeatedly when this Command is scheduled to run
void LowerClawToggleGrab::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClawToggleGrab::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClawToggleGrab::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClawToggleGrab::Interrupted()
{

}
