#ifndef UpperClawReleaseLeft_H
#define UpperClawReleaseLeft_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawReleaseLeft: public Command
{
public:
	UpperClawReleaseLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
