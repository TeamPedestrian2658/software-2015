#ifndef ToggleLiftAutomatic_H
#define ToggleLiftAutomatic_H

#include "../../Robot.h"
#include "WPILib.h"

class ToggleLiftAutomatic: public Command
{
public:
	ToggleLiftAutomatic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
