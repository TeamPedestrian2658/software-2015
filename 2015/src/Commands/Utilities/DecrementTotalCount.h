#ifndef DecrementTotalCount_H
#define DecrementTotalCount_H

#include "../../Robot.h"
#include "WPILib.h"

class DecrementTotalCount: public Command
{
public:
	DecrementTotalCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
