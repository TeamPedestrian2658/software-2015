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
	Solenoid *_brake;
public:
	LowerClaw();
	void InitDefaultCommand();

	void grabLeft();
	void grabRight();
	void grabBoth();

	void releaseLeft();
	void releaseRight();
	void releaseBoth();

	void brakeOn();
	void brakeOff();

	bool isClawLeftClosed();
	bool isClawRightClosed();
	bool isClawClosed();
	bool isBrakeOn();
};

#endif
