#ifndef UPPERCLAW_H
#define UPPERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class UpperClaw: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_leftGrabber;
	Solenoid *_rightGrabber;
public:
	UpperClaw();
	void InitDefaultCommand();

	void grabLeft();
	void grabRight();
	void grabBoth();

	void releaseLeft();
	void releaseRight();
	void releaseBoth();

	bool isClawLeftClosed();
	bool isClawRightClosed();
	bool isClawClosed();
};

#endif
