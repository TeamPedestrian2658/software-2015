#ifndef IncrementLowerClawCount_H
#define IncrementLowerClawCount_H

#include "../../Robot.h"
#include "WPILib.h"

class IncrementLowerClawCount: public Command
{
public:
	IncrementLowerClawCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
