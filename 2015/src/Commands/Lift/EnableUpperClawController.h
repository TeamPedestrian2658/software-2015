#ifndef EnableUpperClawController_H
#define EnableUpperClawController_H

#include "../../Robot.h"
#include "WPILib.h"

class EnableUpperClawController: public Command
{
public:
	EnableUpperClawController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
