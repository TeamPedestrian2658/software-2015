#ifndef LowerClawToggleGrab_H
#define LowerClawToggleGrab_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawToggleGrab: public Command
{
public:
	LowerClawToggleGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
