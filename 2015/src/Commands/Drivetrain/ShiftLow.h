#ifndef ShiftLow_H
#define ShiftLow_H

#include "../../Robot.h"
#include "WPILib.h"

class ShiftLow: public Command
{
private:
	Drivetrain *drivetrain;
public:
	ShiftLow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
