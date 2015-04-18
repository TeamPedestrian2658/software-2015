#ifndef ResetItemCount_H
#define ResetItemCount_H

#include "../../Robot.h"
#include "WPILib.h"

class ResetItemCount: public Command
{
public:
	ResetItemCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
