#ifndef ToteMoverManager_H
#define ToteMoverManager_H

#include "../../Robot.h"
#include "WPILib.h"

class ToteMoverManager: public Command
{
private:
	OI *_oi;
	Constants *_constants;
public:
	ToteMoverManager();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
