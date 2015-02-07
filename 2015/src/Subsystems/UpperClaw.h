#ifndef UPPERCLAW_H
#define UPPERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class UpperClaw: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_grabber;
	Solenoid *_brake;
public:
	UpperClaw();
	void InitDefaultCommand();

	void grab();
	void release();
	void brakeOn();
	void brakeOff();

	bool isClawClosed();
	bool isBrakeOn();
};

#endif
