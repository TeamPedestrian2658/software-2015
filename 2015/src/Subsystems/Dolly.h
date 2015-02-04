#ifndef DOLLY_H
#define DOLLY_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Dolly: public Subsystem {
private:
	Constants *_constants;
	Solenoid *_cylinder;
public:
	Dolly();
	void InitDefaultCommand();

	void setDolly(bool back);
	bool dollyBack();
};

#endif
