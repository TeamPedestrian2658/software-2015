#include "CompressorOff.h"

CompressorOff::CompressorOff()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CompressorOff::Initialize()
{
	RobotMap::compressor->Stop();
}

// Called repeatedly when this Command is scheduled to run
void CompressorOff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CompressorOff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CompressorOff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorOff::Interrupted()
{

}
