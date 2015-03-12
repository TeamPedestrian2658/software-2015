#ifndef LowerUpOneLevel_H
#define LowerUpOneLevel_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerUpOneLevel: public Command
{
public:
	LowerUpOneLevel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
