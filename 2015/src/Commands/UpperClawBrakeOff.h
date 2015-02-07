#ifndef UpperClawBrakeOff_H
#define UpperClawBrakeOff_H

#include "../Robot.h"
#include "WPILib.h"

class UpperClawBrakeOff: public Command
{
public:
	UpperClawBrakeOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
