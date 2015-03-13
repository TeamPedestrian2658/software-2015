#ifndef UpperClawToggleGrabLeft_H
#define UpperClawToggleGrabLeft_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawToggleGrabLeft: public Command
{
public:
	UpperClawToggleGrabLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
