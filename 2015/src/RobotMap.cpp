#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

SendableChooser *RobotMap::autoChooser = NULL;

Talon *RobotMap::driveTalonLeft = NULL;
Talon *RobotMap::driveTalonRight = NULL;

Solenoid *RobotMap::driveShifterLeft = NULL;
Solenoid *RobotMap::driveShifterRight = NULL;

PIDEncoder *RobotMap::driveEncoderLeft = NULL;
PIDEncoder *RobotMap::driveEncoderRight = NULL;

PIDController *RobotMap::driveControllerLeft = NULL;
PIDController *RobotMap::driveControllerRight = NULL;

SendableChooser *RobotMap::driveChooser = NULL;

void RobotMap::init() {

	autoChooser = new SendableChooser();

	driveTalonLeft = new Talon(0);
	driveTalonRight = new Talon(1);

	driveShifterLeft = new Solenoid(0, 0);
	driveShifterLeft->Set(false);
	driveShifterRight = new Solenoid(0, 1);
	driveShifterRight->Set(false);

	driveEncoderLeft = new Encoder(0, 1);
	driveEncoderRight = new Encoder(2, 3);

	driveControllerLeft = new PIDController(1, 0, 0, 0, driveEncoderLeft, driveTalonLeft);
	driveControllerLeft->SetContinuous(false);
	driveControllerLeft->SetSetpoint(0);
	driveControllerRight = new PIDController(1, 0, 0, 0, driveEncoderRight, driveTalonRight);
	driveControllerRight->SetContinuous(false);
	driveControllerRight->SetSetpoint(0);

	driveChooser = new SendableChooser();

	LiveWindow* lw = LiveWindow::GetInstance();

}
