#ifndef UpperClawReleaseRight_H
#define UpperClawReleaseRight_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawReleaseRight: public Command
{
public:
	UpperClawReleaseRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
