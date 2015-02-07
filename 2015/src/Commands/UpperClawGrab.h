#ifndef UpperClawGrab_H
#define UpperClawGrab_H

#include "../Robot.h"
#include "WPILib.h"

class UpperClawGrab: public Command
{
public:
	UpperClawGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
