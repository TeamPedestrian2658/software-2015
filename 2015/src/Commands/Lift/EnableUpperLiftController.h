#ifndef EnableUpperLiftController_H
#define EnableUpperLiftController_H

#include "../../Robot.h"
#include "WPILib.h"

class EnableUpperLiftController: public Command
{
public:
	EnableUpperLiftController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
