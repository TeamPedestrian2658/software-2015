#ifndef TOTEMOVER_H
#define TOTEMOVER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class ToteMover: public Subsystem {
private:
	Talon *mover;
public:
	ToteMover();
	void InitDefaultCommand();
	void setToteMover(double value);
	double getToteMover();
};

#endif
