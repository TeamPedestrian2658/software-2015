#ifndef ToggleDolly_H
#define ToggleDolly_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleDolly: public CommandBase
{
public:
	ToggleDolly();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
