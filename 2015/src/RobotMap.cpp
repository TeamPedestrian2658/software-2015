#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

Constants *RobotMap::constants = NULL;

SendableChooser *RobotMap::autoChooser = NULL;

Talon *RobotMap::driveTalonLeft = NULL;
Talon *RobotMap::driveTalonRight = NULL;

Solenoid *RobotMap::driveShifter = NULL;

Encoder *RobotMap::driveEncoderLeft = NULL;
Encoder *RobotMap::driveEncoderRight = NULL;

PIDController *RobotMap::driveControllerLeft = NULL;
PIDController *RobotMap::driveControllerRight = NULL;

SendableChooser *RobotMap::driveChooser = NULL;

Solenoid *RobotMap::upperClawGrabber = NULL;
Solenoid *RobotMap::upperClawBrake = NULL;

Solenoid *RobotMap::lowerClawGrabber = NULL;
Solenoid *RobotMap::lowerClawBrake = NULL;

Solenoid *RobotMap::dollyCylinder = NULL;

Talon *RobotMap::toteMoverTalon = NULL;

Compressor *RobotMap::compressor = NULL;

void RobotMap::init() {
	constants = new Constants();

	autoChooser = new SendableChooser();

	driveTalonLeft = new Talon(constants->drivePorts.talonLeftPort);
	driveTalonRight = new Talon(constants->drivePorts.talonRightPort);

	driveShifter = new Solenoid(constants->drivePorts.shifterModule, constants->drivePorts.shifterPort);
	driveShifter->Set(constants->shifterStates.lowGear);

	driveEncoderLeft = new Encoder(constants->drivePorts.encoderLeftPortA, constants->drivePorts.encoderLeftPortB, false);
	driveEncoderLeft->SetDistancePerPulse(constants->driveConstants.distancePerPulse);
	driveEncoderLeft->SetPIDSourceParameter(PIDSource::kRate);

	driveEncoderRight = new Encoder(constants->drivePorts.encoderRightPortA, constants->drivePorts.encoderRightPortB, true);
	driveEncoderRight->SetDistancePerPulse(constants->driveConstants.distancePerPulse);
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

	upperClawGrabber = new Solenoid(constants->clawPorts.upperGrabberModule, constants->clawPorts.upperGrabberPort);
	upperClawBrake = new Solenoid(constants->clawPorts.upperBrakeModule, constants->clawPorts.upperBrakePort);

	lowerClawGrabber = new Solenoid(constants->clawPorts.lowerGrabberModule, constants->clawPorts.lowerGrabberPort);
	lowerClawBrake = new Solenoid(constants->clawPorts.lowerBrakeModule, constants->clawPorts.lowerBrakePort);

	dollyCylinder = new Solenoid(constants->dollyPorts.dollyModule, constants->dollyPorts.dollyPort);

	toteMoverTalon = new Talon(constants->toteMoverPorts.toteMoverPort);

	compressor = new Compressor(constants->compressorPorts.compressorModule);
	compressor->Stop();
}


























