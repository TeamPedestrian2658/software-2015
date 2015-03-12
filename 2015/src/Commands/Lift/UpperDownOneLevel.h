#ifndef UpperDownOneLevel_H
#define UpperDownOneLevel_H

#include "../../Robot.h"
#include "WPILib.h"

class UpperDownOneLevel: public Command
{
public:
	UpperDownOneLevel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
