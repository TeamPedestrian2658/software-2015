#ifndef SetToteMover_H
#define SetToteMover_H

#include "../../Robot.h"
#include "WPILib.h"

class SetToteMover: public Command
{
private:
	double _value;
public:
	SetToteMover(double value);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
