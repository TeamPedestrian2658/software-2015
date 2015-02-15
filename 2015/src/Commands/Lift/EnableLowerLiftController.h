#ifndef EnableLowerLiftController_H
#define EnableLowerLiftController_H

#include "../../Robot.h"
#include "WPILib.h"

class EnableLowerLiftController: public Command
{
public:
	EnableLowerLiftController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
