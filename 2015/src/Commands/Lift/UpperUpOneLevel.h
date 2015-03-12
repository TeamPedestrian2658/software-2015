#ifndef UpperUpOneLevel_H
#define UpperUpOneLevel_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperUpOneLevel: public Command
{
public:
	UpperUpOneLevel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
