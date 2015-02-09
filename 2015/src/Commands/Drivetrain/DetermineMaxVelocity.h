#ifndef DetermineMaxVelocity_H
#define DetermineMaxVelocity_H

#include "../../Robot.h"
#include "WPILib.h"

class DetermineMaxVelocity: public Command
{
private:
	double _maxVelocity;
public:
	DetermineMaxVelocity();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
