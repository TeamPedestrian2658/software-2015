#ifndef LowerClawBrakeOff_H
#define LowerClawBrakeOff_H

#include "../Robot.h"
#include "WPILib.h"

class LowerClawBrakeOff: public Command
{
public:
	LowerClawBrakeOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
