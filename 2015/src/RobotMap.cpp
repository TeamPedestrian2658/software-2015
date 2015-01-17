#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

Constants *RobotMap::constants = NULL;

SendableChooser *RobotMap::autoChooser = NULL;

Talon *RobotMap::driveTalonLeft = NULL;
Talon *RobotMap::driveTalonRight = NULL;

Solenoid *RobotMap::driveShifterLeft = NULL;
Solenoid *RobotMap::driveShifterRight = NULL;

Encoder *RobotMap::driveEncoderLeft = NULL;
Encoder *RobotMap::driveEncoderRight = NULL;

PIDController *RobotMap::driveControllerLeft = NULL;
PIDController *RobotMap::driveControllerRight = NULL;

SendableChooser *RobotMap::driveChooser = NULL;

void RobotMap::init() {
	constants = new Constants();

	autoChooser = new SendableChooser();

	driveTalonLeft = new Talon(constants->drivePorts.talonLeftPort);
	driveTalonRight = new Talon(constants->drivePorts.talonRightPort);

	driveShifterLeft = new Solenoid(constants->drivePorts.shifterLeftModule, constants->drivePorts.shifterLeftPort);
	driveShifterLeft->Set(constants->shifterStates.lowGear);
	driveShifterRight = new Solenoid(constants->drivePorts.shifterRightModule, constants->drivePorts.shifterRightPort);
	driveShifterRight->Set(constants->shifterStates.lowGear);

	driveEncoderLeft = new Encoder(constants->drivePorts.encoderLeftPortA, constants->drivePorts.encoderLeftPortB);
	driveEncoderLeft->SetDistancePerPulse(0);
	driveEncoderLeft->SetPIDSourceParameter(PIDSource::kRate);

	driveEncoderRight = new Encoder(constants->drivePorts.encoderRightPortA, constants->drivePorts.encoderRightPortB);
	driveEncoderRight->SetDistancePerPulse(0);
	driveEncoderRight->SetPIDSourceParameter(PIDSource::kRate);

	driveControllerLeft = new PIDController(0, 0, 0, 0, driveEncoderLeft, driveTalonLeft);
	driveControllerLeft->SetContinuous(false);
	driveControllerLeft->SetOutputRange(-1, 1);
	driveControllerLeft->Disable();

	driveControllerRight = new PIDController(0, 0, 0, 0, driveEncoderRight, driveTalonRight);
	driveControllerRight->SetContinuous(false);
	driveControllerRight->SetOutputRange(-1, 1);
	driveControllerRight->Disable();

	driveChooser = new SendableChooser();
}
