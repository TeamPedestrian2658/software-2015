#ifndef LIFT_H
#define LIFT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lift: public Subsystem {
private:
public:
	Lift();
	void InitDefaultCommand();
};

#endif
