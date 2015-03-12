#ifndef ToggleLowerLiftController_H
#define ToggleLowerLiftController_H

#include "../../Robot.h"
#include "WPILib.h"

class ToggleLowerLiftController: public Command
{
public:
	ToggleLowerLiftController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
