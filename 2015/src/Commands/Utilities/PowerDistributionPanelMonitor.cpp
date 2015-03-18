#include "PowerDistributionPanelMonitor.h"

PowerDistributionPanelMonitor::PowerDistributionPanelMonitor()
{
	panel = RobotMap::powerDistributionPanel;
}

// Called just before this Command runs the first time
void PowerDistributionPanelMonitor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PowerDistributionPanelMonitor::Execute()
{
	SmartDashboard::PutNumber("Current", panel->GetTotalCurrent());
	SmartDashboard::PutNumber("Voltage", panel->GetVoltage());
	SmartDashboard::PutNumber("Power", panel->GetTotalPower());
}

// Make this return true when this Command no longer needs to run execute()
bool PowerDistributionPanelMonitor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PowerDistributionPanelMonitor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PowerDistributionPanelMonitor::Interrupted()
{

}
