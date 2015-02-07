#ifndef LOWERCLAW_H
#define LOWERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class LowerClaw: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_grabber;
	Solenoid *_brake;
public:
	LowerClaw();
	void InitDefaultCommand();

	void grab();
	void release();
	void brakeOn();
	void brakeOff();

	bool isClawClosed();
	bool isBrakeOn();
};

#endif
