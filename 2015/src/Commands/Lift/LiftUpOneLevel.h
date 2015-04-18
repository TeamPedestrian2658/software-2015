#ifndef LiftUpOneLevel_H
#define LiftUpOneLevel_H

#include "../../Robot.h"
#include "WPILib.h"

class LiftUpOneLevel: public Command
{
public:
	LiftUpOneLevel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
