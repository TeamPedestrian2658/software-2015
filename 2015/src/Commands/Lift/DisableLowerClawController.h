#ifndef DisableLowerClawController_H
#define DisableLowerClawController_H

#include "../../Robot.h"
#include "WPILib.h"

class DisableLowerClawController: public Command
{
public:
	DisableLowerClawController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
