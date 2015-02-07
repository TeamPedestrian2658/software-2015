#ifndef UpperClawBrakeOn_H
#define UpperClawBrakeOn_H

#include "../Robot.h"
#include "WPILib.h"

class UpperClawBrakeOn: public Command
{
public:
	UpperClawBrakeOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
