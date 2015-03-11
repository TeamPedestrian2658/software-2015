#ifndef UpperClawGrabRight_H
#define UpperClawGrabRight_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawGrabRight: public Command
{
public:
	UpperClawGrabRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
