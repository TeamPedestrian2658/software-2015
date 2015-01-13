#ifndef UPPERCLAW_H
#define UPPERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class UpperClaw: public Subsystem {
private:
public:
	UpperClaw();
	void InitDefaultCommand();
};

#endif
