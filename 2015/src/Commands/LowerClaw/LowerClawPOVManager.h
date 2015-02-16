#ifndef LowerClawPOVManager_H
#define LowerClawPOVManager_H

#include "../../Robot.h"
#include "WPILib.h"

class LowerClawPOVManager: public Command
{
private:
	LowerClaw *_lowerClaw;
	OI *_oi;
public:
	LowerClawPOVManager();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
