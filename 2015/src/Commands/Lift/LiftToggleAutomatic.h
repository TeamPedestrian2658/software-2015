#ifndef LiftToggleAutomatic_H
#define LiftToggleAutomatic_H

#include "../../Robot.h"
#include "WPILib.h"

class LiftToggleAutomatic: public Command
{
public:
	LiftToggleAutomatic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
