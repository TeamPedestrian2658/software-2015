#ifndef LOWERCLAW_H
#define LOWERCLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class LowerClaw: public Subsystem {
private:
public:
	LowerClaw();
	void InitDefaultCommand();
};

#endif
