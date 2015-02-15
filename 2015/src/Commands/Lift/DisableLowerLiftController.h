#ifndef DisableLowerLiftController_H
#define DisableLowerLiftController_H

#include "../../Robot.h"
#include "WPILib.h"

class DisableLowerLiftController: public Command
{
public:
	DisableLowerLiftController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
