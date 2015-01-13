#include "Robot.h"

Drivetrain* Robot::drivetrain = 0;
UpperClaw* Robot::upperClaw = 0;
LowerClaw* Robot::lowerClaw = 0;
Dolley* Robot::dolley = 0;
Lift* Robot::lift = 0;
OI* Robot::oi = 0;

void Robot::RobotInit() {
	RobotMap::init();
	drivetrain = new Drivetrain();
	upperClaw = new UpperClaw();
	lowerClaw = new LowerClaw();
	dolley = new Dolley();
	lift = new Lift();
	oi = new OI();
	lw = LiveWindow::GetInstance();
  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

