#ifndef DollyForward_H
#define DollyForward_H

#include "../Robot.h"
#include "WPILib.h"

class DollyForward: public Command
{
public:
	DollyForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
