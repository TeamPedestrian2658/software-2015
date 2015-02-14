#ifndef ResetLowerClawCount_H
#define ResetLowerClawCount_H

#include "../../Robot.h"
#include "WPILib.h"

class ResetLowerClawCount: public Command
{
public:
	ResetLowerClawCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
