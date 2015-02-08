#ifndef ToggleDolly_H
#define ToggleDolly_H

#include "../../Robot.h"
#include "WPILib.h"

class ToggleDolly: public Command
{
public:
	ToggleDolly();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
