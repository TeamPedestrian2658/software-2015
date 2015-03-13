#ifndef UpperClawToggleGrabRight_H
#define UpperClawToggleGrabRight_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawToggleGrabRight: public Command
{
public:
	UpperClawToggleGrabRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
