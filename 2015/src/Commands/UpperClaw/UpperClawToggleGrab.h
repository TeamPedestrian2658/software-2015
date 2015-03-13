#ifndef UpperClawToggleGrab_H
#define UpperClawToggleGrab_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawToggleGrab: public Command
{
public:
	UpperClawToggleGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
