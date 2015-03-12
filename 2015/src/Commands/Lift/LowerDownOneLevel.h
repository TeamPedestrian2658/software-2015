#ifndef LowerDownOneLevel_H
#define LowerDownOneLevel_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerDownOneLevel: public Command
{
public:
	LowerDownOneLevel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
