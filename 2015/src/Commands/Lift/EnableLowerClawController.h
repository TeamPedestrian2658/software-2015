#ifndef EnableLowerClawController_H
#define EnableLowerClawController_H

#include "../../Robot.h"
#include "WPILib.h"

class EnableLowerClawController: public Command
{
public:
	EnableLowerClawController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
