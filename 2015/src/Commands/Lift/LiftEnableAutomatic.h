#ifndef LiftEnableAutomatic_H
#define LiftEnableAutomatic_H

#include "../../Robot.h"
#include "WPILib.h"

class LiftEnableAutomatic: public Command
{
public:
	LiftEnableAutomatic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
