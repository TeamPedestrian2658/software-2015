#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

Constants *RobotMap::constants = NULL;

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

	constants = new Constants();

	autoChooser = new SendableChooser();

	driveTalonLeft = new Talon(constants->drivePorts.talonLeftPort);
	driveTalonLeft->Set(0);
	driveTalonRight = new Talon(constants->drivePorts.talonRightPort);
	driveTalonRight->Set(0);

	driveShifterLeft = new Solenoid(constants->drivePorts.shifterLeftModule, constants->drivePorts.shifterLeftPort);
	driveShifterLeft->Set(false);
	driveShifterRight = new Solenoid(constants->drivePorts.shifterRightModule, constants->drivePorts.shifterRightPort);
	driveShifterRight->Set(false);

	driveEncoderLeft = new PIDEncoder(constants->drivePorts.encoderLeftPortA, constants->drivePorts.encoderLeftPortB, true);
	driveEncoderRight = new PIDEncoder(constants->drivePorts.encoderRightPortA, constants->drivePorts.encoderRightPortB, true);

	driveControllerLeft = new PIDController(1, 0, 0, 0, driveEncoderLeft, driveTalonLeft);
	driveControllerLeft->SetContinuous(false);
	driveControllerLeft->SetSetpoint(0);
	driveControllerRight = new PIDController(1, 0, 0, 0, driveEncoderRight, driveTalonRight);
	driveControllerRight->SetContinuous(false);
	driveControllerRight->SetSetpoint(0);

	driveChooser = new SendableChooser();
}
