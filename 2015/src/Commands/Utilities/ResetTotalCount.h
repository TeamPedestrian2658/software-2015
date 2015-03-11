#ifndef ResetTotalCount_H
#define ResetTotalCount_H

#include "../../Robot.h"
#include "WPILib.h"

class ResetTotalCount: public Command
{
public:
	ResetTotalCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
