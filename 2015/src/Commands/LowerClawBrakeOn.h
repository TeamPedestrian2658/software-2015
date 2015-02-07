#ifndef LowerClawBrakeOn_H
#define LowerClawBrakeOn_H

#include "../Robot.h"
#include "WPILib.h"

class LowerClawBrakeOn: public Command
{
public:
	LowerClawBrakeOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
