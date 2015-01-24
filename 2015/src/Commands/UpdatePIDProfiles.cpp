#include "UpdatePIDProfiles.h"

UpdatePIDProfiles::UpdatePIDProfiles()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void UpdatePIDProfiles::Initialize()
{
	RobotMap::constants->updatePIDProfiles();
}

// Called repeatedly when this Command is scheduled to run
void UpdatePIDProfiles::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpdatePIDProfiles::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpdatePIDProfiles::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdatePIDProfiles::Interrupted()
{

}
