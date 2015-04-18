#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

LiveWindow *RobotMap::liveWindow = NULL;

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
SendableChooser *RobotMap::driveRumbleChooser = NULL;

Solenoid *RobotMap::upperClawGrabber = NULL;

Solenoid *RobotMap::lowerClawLeftGrabber = NULL;
Solenoid *RobotMap::lowerClawRightGrabber = NULL;

Talon *RobotMap::liftTalonLeft = NULL;
Talon *RobotMap::liftTalonRight = NULL;

Encoder *RobotMap::liftEncoder = NULL;

PIDController *RobotMap::liftControllerLeft = NULL;
PIDController *RobotMap::liftControllerRight = NULL;

Compressor *RobotMap::compressor = NULL;

PowerDistributionPanel *RobotMap::powerDistributionPanel = NULL;

void RobotMap::init() {
	liveWindow = LiveWindow::GetInstance();

	constants = new Constants();

	autoChooser = new SendableChooser();

	driveTalonLeft = new Talon(constants->drivePorts.talonLeftPort);
	driveTalonRight = new Talon(constants->drivePorts.talonRightPort);
	liveWindow->AddActuator("Left Drive", "Left Talon", driveTalonLeft);
	liveWindow->AddActuator("Right Drive", "Right Talon", driveTalonRight);

	driveShifter = new Solenoid(constants->drivePorts.shifterModule, constants->drivePorts.shifterPort);
	driveShifter->Set(constants->shifterStates.lowGear);
	liveWindow->AddActuator("Shifter", "Shifter", driveShifter);

	driveEncoderLeft = new Encoder(constants->drivePorts.encoderLeftPortA, constants->drivePorts.encoderLeftPortB, false);
	driveEncoderLeft->SetDistancePerPulse(constants->driveConstants.distancePerPulse);
	driveEncoderLeft->SetPIDSourceParameter(PIDSource::kRate);
	liveWindow->AddSensor("Left Drive", "Left Encoder", driveEncoderLeft);

	driveEncoderRight = new Encoder(constants->drivePorts.encoderRightPortA, constants->drivePorts.encoderRightPortB, true);
	driveEncoderRight->SetDistancePerPulse(constants->driveConstants.distancePerPulse);
	driveEncoderRight->SetPIDSourceParameter(PIDSource::kRate);
	liveWindow->AddSensor("Right Drive", "Right Encoder", driveEncoderRight);

	driveControllerLeft = new PIDController(0, 0, 0, 0, driveEncoderLeft, driveTalonLeft);
	driveControllerLeft->SetContinuous(false);
	driveControllerLeft->SetOutputRange(-1, 1);
	driveControllerLeft->Reset();
	liveWindow->AddActuator("Left Drive", "Left PID Controller", driveControllerLeft);

	driveControllerRight = new PIDController(0, 0, 0, 0, driveEncoderRight, driveTalonRight);
	driveControllerRight->SetContinuous(false);
	driveControllerRight->SetOutputRange(-1, 1);
	driveControllerRight->Reset();
	liveWindow->AddActuator("Right Drive", "Right PID Controller", driveControllerRight);

	driveChooser = new SendableChooser();
	driveRumbleChooser = new SendableChooser();

	upperClawGrabber = new Solenoid(constants->clawPorts.upperGrabberModule, constants->clawPorts.upperGrabberPort);
	liveWindow->AddActuator("Upper Claw", "Grabber", upperClawGrabber);

	lowerClawLeftGrabber = new Solenoid(constants->clawPorts.lowerGrabberLeftModule, constants->clawPorts.lowerGrabberLeftPort);
	lowerClawRightGrabber = new Solenoid(constants->clawPorts.lowerGrabberRightModule, constants->clawPorts.lowerGrabberRightPort);
	liveWindow->AddActuator("Lower Claw", "Left Grabber", lowerClawLeftGrabber);
	liveWindow->AddActuator("Lower Claw", "Right Grabber", lowerClawRightGrabber);

	liftTalonLeft = new Talon(constants->liftPorts.talonLeftPort);
	liftTalonRight = new Talon(constants->liftPorts.talonRightPort);
	liveWindow->AddActuator("Lift", "Left Talon", liftTalonLeft);
	liveWindow->AddActuator("Lift", "Right Talon", liftTalonRight);

	liftEncoder = new Encoder(constants->liftPorts.encoderPortA, constants->liftPorts.encoderPortB, false);
	liftEncoder->SetDistancePerPulse(constants->liftConstants.distancePerPulse);
	liftEncoder->SetPIDSourceParameter(PIDSource::kDistance);
	liveWindow->AddSensor("Lift", "Encoder", liftEncoder);

	liftControllerLeft = new PIDController(0, 0, 0, 0, liftEncoder, liftTalonLeft);
	liftControllerLeft->SetContinuous(false);
	liftControllerLeft->SetOutputRange(-1, 1);
	liftControllerLeft->Reset();
	liveWindow->AddActuator("Lift", "Left Controller", liftControllerLeft);

	liftControllerRight = new PIDController(0, 0, 0, 0, liftEncoder, liftTalonRight);
	liftControllerRight->SetContinuous(false);
	liftControllerRight->SetOutputRange(-1, 1);
	liftControllerRight->Reset();
	liveWindow->AddActuator("Lift", "Right Controller", liftControllerRight);

	compressor = new Compressor(constants->compressorPorts.compressorModule);
	compressor->Start();

	powerDistributionPanel = new PowerDistributionPanel();
	powerDistributionPanel->ClearStickyFaults();
}


























