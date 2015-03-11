#ifndef IncrementTotalCount_H
#define IncrementTotalCount_H

#include "../../Robot.h"
#include "WPILib.h"

class IncrementTotalCount: public Command
{
public:
	IncrementTotalCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
