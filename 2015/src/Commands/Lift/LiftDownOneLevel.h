#ifndef LiftDownOneLevel_H
#define LiftDownOneLevel_H

#include "../../Robot.h"
#include "WPILib.h"

class LiftDownOneLevel: public Command
{
public:
	LiftDownOneLevel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
