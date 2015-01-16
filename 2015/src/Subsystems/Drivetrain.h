#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem {
private:
	PIDController *_controllerLeft;
	PIDController *_controllerRight;

	Solenoid *_shifterLeft;
	Solenoid *_shifterRight;

	SendableChooser *_chooser;

public:
	Drivetrain();
	void InitDefaultCommand();

	void shiftHigh();
	void shiftLow();

	void set(double left, double right);
};

#endif
