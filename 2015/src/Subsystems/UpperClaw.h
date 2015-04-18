#ifndef UPPERCLAW_H
#define UPPERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class UpperClaw: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_grabber;
	bool _clawState;
public:
	UpperClaw();
	void InitDefaultCommand();

	void grab();
	void release();

	bool isClawClosed();
};

#endif
