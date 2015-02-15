#ifndef DisableUpperClawController_H
#define DisableUpperClawController_H

#include "../../Robot.h"
#include "WPILib.h"

class DisableUpperClawController: public Command
{
public:
	DisableUpperClawController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
