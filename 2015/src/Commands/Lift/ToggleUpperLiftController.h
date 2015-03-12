#ifndef ToggleUpperLiftController_H
#define ToggleUpperLiftController_H

#include "../../Robot.h"
#include "WPILib.h"

class ToggleUpperLiftController: public Command
{
public:
	ToggleUpperLiftController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
