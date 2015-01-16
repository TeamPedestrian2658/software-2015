#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/Dolley.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Lift.h"
#include "Subsystems/LowerClaw.h"
#include "Subsystems/UpperClaw.h"

#include "OI.h"

#include "Utilities/AutoScriptSelector.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	LiveWindow *lw;
	static OI *oi;
	static Drivetrain* drivetrain;
	static UpperClaw* upperClaw;
	static LowerClaw* lowerClaw;
	static Dolley* dolley;
	static Lift* lift;
	static AutoScriptSelector* selector;
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
