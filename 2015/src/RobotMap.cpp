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

Solenoid *RobotMap::lowerClawGrabber = NULL;
Solenoid *RobotMap::lowerClawBrake = NULL;

Solenoid *RobotMap::dollyCylinder = NULL;

Talon *RobotMap::toteMoverTalon = NULL;

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

	lowerClawGrabber = new Solenoid(constants->clawPorts.lowerGrabberModule, constants->clawPorts.lowerGrabberPort);
	lowerClawBrake = new Solenoid(constants->clawPorts.lowerBrakeModule, constants->clawPorts.lowerBrakePort);
	liveWindow->AddActuator("Lower Claw", "Grabber", lowerClawGrabber);
	liveWindow->AddActuator("Lower Claw", "Brake", lowerClawBrake);

	dollyCylinder = new Solenoid(constants->dollyPorts.dollyModule, constants->dollyPorts.dollyPort);
	liveWindow->AddActuator("Dolly", "Cylinder", dollyCylinder);

	toteMoverTalon = new Talon(constants->toteMoverPorts.toteMoverPort);
	liveWindow->AddActuator("Tote Mover", "Talon", toteMoverTalon);

	compressor = new Compressor(constants->compressorPorts.compressorModule);
	compressor->Stop();

	powerDistributionPanel = new PowerDistributionPanel();
	powerDistributionPanel->ClearStickyFaults();
}


























