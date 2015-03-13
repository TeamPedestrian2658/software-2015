#ifndef LowerClawToggleGrabRight_H
#define LowerClawToggleGrabRight_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawToggleGrabRight: public Command
{
public:
	LowerClawToggleGrabRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
