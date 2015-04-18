#ifndef LiftDisableAutomatic_H
#define LiftDisableAutomatic_H

#include "../../Robot.h"
#include "WPILib.h"

class LiftDisableAutomatic: public Command
{
public:
	LiftDisableAutomatic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
