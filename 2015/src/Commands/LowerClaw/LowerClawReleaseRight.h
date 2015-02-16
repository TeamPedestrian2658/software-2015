#ifndef LowerClawReleaseRight_H
#define LowerClawReleaseRight_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawReleaseRight: public Command
{
public:
	LowerClawReleaseRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
