#ifndef LowerClawRelease_H
#define LowerClawRelease_H

#include "../Robot.h"
#include "WPILib.h"

class LowerClawRelease: public Command
{
public:
	LowerClawRelease();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
