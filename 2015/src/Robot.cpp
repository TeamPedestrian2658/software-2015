#include "Robot.h"

Drivetrain* Robot::drivetrain = 0;
UpperClaw* Robot::upperClaw = 0;
LowerClaw* Robot::lowerClaw = 0;
Lift* Robot::lift = 0;
PowerDistributionPanelMonitor *Robot::monitor = 0;
OI* Robot::oi = 0;
//AutoScriptSelector* Robot::selector = 0;

void Robot::RobotInit() {
	RobotMap::init();
	drivetrain = new Drivetrain();
	upperClaw = new UpperClaw();
	lowerClaw = new LowerClaw();
	lift = new Lift();
	monitor = new PowerDistributionPanelMonitor();
	oi = new OI();
	//selector = new AutoScriptSelector("/home/lvuser/scripts");
	liveWindow = LiveWindow::GetInstance();
}

void Robot::DisabledInit() {
	oi->getDriverStick()->SetRumble(Joystick::kLeftRumble, 0);
	oi->getDriverStick()->SetRumble(Joystick::kRightRumble, 0);
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
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	liveWindow->Run();
}

START_ROBOT_CLASS(Robot);

