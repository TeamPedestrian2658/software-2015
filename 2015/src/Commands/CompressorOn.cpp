#include "CompressorOn.h"

CompressorOn::CompressorOn()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CompressorOn::Initialize()
{
	RobotMap::compressor->Start();
}

// Called repeatedly when this Command is scheduled to run
void CompressorOn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CompressorOn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CompressorOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorOn::Interrupted()
{

}
