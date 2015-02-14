#ifndef DecrementLowerClawCount_H
#define DecrementLowerClawCount_H

#include "../../Robot.h"
#include "WPILib.h"

class DecrementLowerClawCount: public Command
{
public:
	DecrementLowerClawCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
