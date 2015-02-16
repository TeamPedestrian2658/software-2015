#ifndef LowerClawGrabRight_H
#define LowerClawGrabRight_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawGrabRight: public Command
{
public:
	LowerClawGrabRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
