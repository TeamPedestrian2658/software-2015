#ifndef PowerDistributionPanelMonitor_H
#define PowerDistributionPanelMonitor_H

#include "../../RobotMap.h"
#include "WPILib.h"

class PowerDistributionPanelMonitor: public Command
{
private:
	PowerDistributionPanel *panel;
public:
	PowerDistributionPanelMonitor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
