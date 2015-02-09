#include "Robot.h"

Drivetrain* Robot::drivetrain = 0;
UpperClaw* Robot::upperClaw = 0;
LowerClaw* Robot::lowerClaw = 0;
Dolly* Robot::dolly = 0;
Lift* Robot::lift = 0;
ToteMover* Robot::toteMover = 0;
PowerDistributionPanelMonitor *Robot::monitor = 0;
DriverStickRumbleManager *Robot::rumbleManager = 0;
OI* Robot::oi = 0;
//AutoScriptSelector* Robot::selector = 0;

void Robot::RobotInit() {
	RobotMap::init();
	drivetrain = new Drivetrain();
	upperClaw = new UpperClaw();
	lowerClaw = new LowerClaw();
	dolly = new Dolly();
	lift = new Lift();
	toteMover = new ToteMover();
	monitor = new PowerDistributionPanelMonitor();
	rumbleManager = new DriverStickRumbleManager();
	oi = new OI();
	//selector = new AutoScriptSelector("/home/lvuser/scripts");
	liveWindow = LiveWindow::GetInstance();
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (!monitor->IsRunning()) {
		monitor->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (!monitor->IsRunning()) {
		monitor->Start();
	}
	if (!rumbleManager->IsRunning()) {
		rumbleManager->Start();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	liveWindow->Run();
}

START_ROBOT_CLASS(Robot);

