#ifndef DetermineMaxVelocity_H
#define DetermineMaxVelocity_H

#include "../../Robot.h"
#include "WPILib.h"

class DetermineMaxVelocity: public Command
{
private:
	Drivetrain *_drivetrain;
	Timer *_timer;
	double _maxVelocityLeft;
	double _maxVelocityRight;
	int _numSamples;
public:
	DetermineMaxVelocity();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
