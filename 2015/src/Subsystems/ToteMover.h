#ifndef TOTEMOVER_H
#define TOTEMOVER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class ToteMover: public Subsystem {
private:
	Constants *_constants;
	Talon *_mover;
public:
	ToteMover();
	void InitDefaultCommand();

	void moveTotesLeft();
	void moveTotesRight();
	void stop();
};

#endif
