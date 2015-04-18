#ifndef DecrementItemCount_H
#define DecrementItemCount_H

#include "../../Robot.h"
#include "WPILib.h"

class DecrementItemCount: public Command
{
public:
	DecrementItemCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
