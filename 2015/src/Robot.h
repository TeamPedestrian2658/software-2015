#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/Dolly.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Lift.h"
#include "Subsystems/LowerClaw.h"
#include "Subsystems/UpperClaw.h"
#include "Subsystems/ToteMover.h"

#include "OI.h"

#include "Utilities/AutoScriptSelector.h"
#include "Utilities/Constants.h"

#include "Commands/Utilities/PowerDistributionPanelMonitor.h"

class Robot : public IterativeRobot {
public:
	LiveWindow *liveWindow;
	static OI *oi;
	static Drivetrain* drivetrain;
	static UpperClaw* upperClaw;
	static LowerClaw* lowerClaw;
	static Dolly* dolly;
	static Lift* lift;
	static ToteMover* toteMover;
	static PowerDistributionPanelMonitor *monitor;
	//static AutoScriptSelector* selector;
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
