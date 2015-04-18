#ifndef IncrementItemCount_H
#define IncrementItemCount_H

#include "../../Robot.h"
#include "WPILib.h"

class IncrementItemCount: public Command
{
public:
	IncrementItemCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
