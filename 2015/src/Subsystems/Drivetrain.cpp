#include "Drivetrain.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	_controllerLeft = RobotMap::driveControllerLeft;
	_controllerRight = RobotMap::driveControllerRight;

	_shifterLeft = RobotMap::driveShifterLeft;
	_shifterRight = RobotMap::driveShifterRight;

	_chooser = RobotMap::driveChooser;
	_chooser->AddDefault("Tank", new bool(true));
	_chooser->AddObject("Arcade", new bool(false));
	SmartDashboard::PutData("Drive Mode", _chooser);
}
    
void Drivetrain::InitDefaultCommand() {

}

void Drivetrain::shiftHigh() {
	_shifterLeft->Set(true);
	_shifterRight->Set(true);
}

void Drivetrain::shiftLow() {
	_shifterLeft->Set(false);
	_shifterRight->Set(false);
}

void Drivetrain::set(double left, double right) {
	_controllerLeft->SetSetpoint(left);
	_controllerRight->SetSetpoint(right);
}
