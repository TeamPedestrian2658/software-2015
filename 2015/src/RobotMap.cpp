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
Solenoid *RobotMap::upperClawBrake = NULL;

Solenoid *RobotMap::lowerClawLeftGrabber = NULL;
Solenoid *RobotMap::lowerClawRightGrabber = NULL;
Solenoid *RobotMap::lowerClawBrake = NULL;

Talon *RobotMap::lowerLiftTalonLeft = NULL;
Talon *RobotMap::lowerLiftTalonRight = NULL;
Talon *RobotMap::upperLiftTalon = NULL;

Encoder *RobotMap::lowerLiftEncoderLeft = NULL;
Encoder *RobotMap::lowerLiftEncoderRight = NULL;
Encoder *RobotMap::upperLiftEncoder = NULL;

PIDController *RobotMap::liftControllerLowerLeft = NULL;
PIDController *RobotMap::liftControllerLowerRight = NULL;
PIDController *RobotMap::liftControllerUpper = NULL;

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
	upperClawBrake = new Solenoid(constants->clawPorts.upperBrakeModule, constants->clawPorts.upperBrakePort);
	liveWindow->AddActuator("Upper Claw", "Grabber", upperClawGrabber);
	liveWindow->AddActuator("Upper Claw", "Brake", upperClawBrake);

	lowerClawLeftGrabber = new Solenoid(constants->clawPorts.lowerGrabberLeftModule, constants->clawPorts.lowerGrabberLeftPort);
	lowerClawRightGrabber = new Solenoid(constants->clawPorts.lowerGrabberRightModule, constants->clawPorts.lowerGrabberRightPort);
	lowerClawBrake = new Solenoid(constants->clawPorts.lowerBrakeModule, constants->clawPorts.lowerBrakePort);
	liveWindow->AddActuator("Lower Claw", "Left Grabber", lowerClawLeftGrabber);
	liveWindow->AddActuator("Lower Claw", "Right Grabber", lowerClawRightGrabber);
	liveWindow->AddActuator("Lower Claw", "Brake", lowerClawBrake);

	lowerLiftTalonLeft = new Talon(constants->liftPorts.lowerTalonLeftPort);
	lowerLiftTalonRight = new Talon(constants->liftPorts.lowerTalonRightPort);
	upperLiftTalon = new Talon(constants->liftPorts.upperTalonPort);
	liveWindow->AddActuator("Lower Lift", "Left Talon", lowerLiftTalonLeft);
	liveWindow->AddActuator("Lower Lift", "Right Talon", lowerLiftTalonRight);
	liveWindow->AddActuator("Upper Lift", "Talon", upperLiftTalon);

	lowerLiftEncoderLeft = new Encoder(constants->liftPorts.lowerEncoderLeftPortA, constants->liftPorts.lowerEncoderLeftPortB, false);
	lowerLiftEncoderLeft->SetDistancePerPulse(constants->liftConstants.distancePerPulse);
	lowerLiftEncoderLeft->SetPIDSourceParameter(PIDSource::kDistance);
	liveWindow->AddSensor("Lower Lift", "Encoder Left", lowerLiftEncoderLeft);

	lowerLiftEncoderRight = new Encoder(constants->liftPorts.lowerEncoderRightPortA, constants->liftPorts.lowerEncoderRightPortB, false);
	lowerLiftEncoderRight->SetDistancePerPulse(constants->liftConstants.distancePerPulse);
	lowerLiftEncoderRight->SetPIDSourceParameter(PIDSource::kDistance);
	liveWindow->AddSensor("Lower Lift", "Encoder Right", lowerLiftEncoderRight);

	upperLiftEncoder = new Encoder(constants->liftPorts.upperEncoderPortA, constants->liftPorts.upperEncoderPortB, false);
	upperLiftEncoder->SetDistancePerPulse(constants->liftConstants.distancePerPulse);
	upperLiftEncoder->SetPIDSourceParameter(PIDSource::kDistance);
	liveWindow->AddSensor("Upper Lift", "Encoder", upperLiftEncoder);

	liftControllerLowerLeft = new PIDController(0, 0, 0, 0, lowerLiftEncoderLeft, lowerLiftTalonLeft);
	liftControllerLowerLeft->SetContinuous(false);
	liftControllerLowerLeft->SetOutputRange(-1, 1);
	liftControllerLowerLeft->Reset();
	liveWindow->AddActuator("Lower Lift", "Left Controller", liftControllerLowerLeft);

	liftControllerLowerRight = new PIDController(0, 0, 0, 0, lowerLiftEncoderRight, lowerLiftTalonRight);
	liftControllerLowerRight->SetContinuous(false);
	liftControllerLowerRight->SetOutputRange(-1, 1);
	liftControllerLowerRight->Reset();
	liveWindow->AddActuator("Lower Lift", "Right Controller", liftControllerLowerRight);

	liftControllerUpper = new PIDController(0, 0, 0, 0, upperLiftEncoder, upperLiftTalon);
	liftControllerUpper->SetContinuous(false);
	liftControllerUpper->SetOutputRange(-1, 1);
	liftControllerUpper->Reset();
	liveWindow->AddActuator("Upper Lift", "Controller", liftControllerUpper);

	compressor = new Compressor(constants->compressorPorts.compressorModule);
	compressor->Start();

	powerDistributionPanel = new PowerDistributionPanel();
	powerDistributionPanel->ClearStickyFaults();
}


























