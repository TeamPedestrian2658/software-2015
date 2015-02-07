#ifndef LowerClawGrab_H
#define LowerClawGrab_H

#include "../Robot.h"
#include "WPILib.h"

class LowerClawGrab: public Command
{
public:
	LowerClawGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
