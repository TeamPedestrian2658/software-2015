#ifndef LowerClawToggleGrabLeft_H
#define LowerClawToggleGrabLeft_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawToggleGrabLeft: public Command
{
public:
	LowerClawToggleGrabLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
