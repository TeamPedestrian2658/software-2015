#ifndef UpperClawGrabLeft_H
#define UpperClawGrabLeft_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawGrabLeft: public Command
{
public:
	UpperClawGrabLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
