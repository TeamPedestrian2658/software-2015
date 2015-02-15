#ifndef DisableUpperLiftController_H
#define DisableUpperLiftController_H

#include "../../Robot.h"
#include "WPILib.h"

class DisableUpperLiftController: public Command
{
public:
	DisableUpperLiftController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
