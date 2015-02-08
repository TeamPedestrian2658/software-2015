#ifndef EnableSlow_H
#define EnableSlow_H

#include "../../Robot.h"
#include "WPILib.h"

class EnableSlow: public Command
{
public:
	EnableSlow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
