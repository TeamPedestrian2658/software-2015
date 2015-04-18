#ifndef ControlLift_H
#define ControlLift_H

#include "../../Robot.h"
#include "WPILib.h"

class ControlLift: public Command
{
private:
	Lift *_lift;
	OI *_oi;
	bool _readyForInput;
public:
	ControlLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
