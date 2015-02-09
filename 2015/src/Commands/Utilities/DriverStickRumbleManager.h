#ifndef DriverStickRumbleManager_H
#define DriverStickRumbleManager_H

#include "../Robot.h"
#include "WPILib.h"

class DriverStickRumbleManager: public Command
{
public:
	DriverStickRumbleManager();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
