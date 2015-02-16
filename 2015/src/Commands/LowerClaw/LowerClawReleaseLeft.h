#ifndef LowerClawReleaseLeft_H
#define LowerClawReleaseLeft_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawReleaseLeft: public Command
{
public:
	LowerClawReleaseLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
