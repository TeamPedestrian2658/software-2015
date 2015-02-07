#ifndef DOLLY_H
#define DOLLY_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class Dolly: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_cylinder;
public:
	Dolly();
	void InitDefaultCommand();

	void dollyBack();
	void dollyForward();

	bool isDollyBack();
};

#endif
