#ifndef LOWERCLAW_H
#define LOWERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class LowerClaw: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_leftGrabber;
	Solenoid *_rightGrabber;
	bool _leftState;
	bool _rightState;
public:
	LowerClaw();
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
