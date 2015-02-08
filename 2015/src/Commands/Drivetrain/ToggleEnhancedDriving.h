#ifndef ToggleEnhancedDriving_H
#define ToggleEnhancedDriving_H

#include "../../Robot.h"
#include "WPILib.h"

class ToggleEnhancedDriving: public Command
{
public:
	ToggleEnhancedDriving();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
