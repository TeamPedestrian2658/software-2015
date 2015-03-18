#ifndef Delay_H
#define Delay_H

#include "../../Robot.h"
#include "WPILib.h"

class Delay: public Command
{
public:
	Delay(double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
