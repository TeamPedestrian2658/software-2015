#ifndef UpperClawRelease_H
#define UpperClawRelease_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperClawRelease: public Command
{
public:
	UpperClawRelease();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
