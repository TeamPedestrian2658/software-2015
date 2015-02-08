#ifndef DollyBack_H
#define DollyBack_H

#include "../../Robot.h"
#include "WPILib.h"

class DollyBack: public Command
{
public:
	DollyBack();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
