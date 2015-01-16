#ifndef DisableSlow_H
#define DisableSlow_H

#include "../Robot.h"
#include "WPILib.h"

class DisableSlow: public Command
{
public:
	DisableSlow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
