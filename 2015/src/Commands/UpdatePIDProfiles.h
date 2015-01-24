#ifndef UpdatePIDProfiles_H
#define UpdatePIDProfiles_H

#include "../Robot.h"
#include "WPILib.h"

class UpdatePIDProfiles: public Command
{
public:
	UpdatePIDProfiles();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
