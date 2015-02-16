#ifndef LowerClawGrabLeft_H
#define LowerClawGrabLeft_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawGrabLeft: public Command
{
public:
	LowerClawGrabLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
