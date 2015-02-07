/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"
#include "../Commands/UpdatePIDProfiles.h"
#include "../Commands/CompressorOn.h"
#include "../Commands/CompressorOff.h"

Constants::Constants() {
	_preferences = Preferences::GetInstance();

	drivePorts.talonLeftPort = _preferences->GetInt("TalonLeftPort", 3);
	drivePorts.talonRightPort = _preferences->GetInt("TalonRightPort", 4);
	drivePorts.shifterModule = _preferences->GetInt("ShifterModule", 0);
	drivePorts.shifterPort = _preferences->GetInt("ShifterPort", 5);
	drivePorts.encoderLeftPortA = _preferences->GetInt("EncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("EncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("EncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("EncoderRightPortB", 3);

	clawPorts.upperGrabberModule = _preferences->GetInt("UpperGrabberModule, 0");
	clawPorts.upperGrabberPort = _preferences->GetInt("UpperGrabberPort", 0);
	clawPorts.upperBrakeModule = _preferences->GetInt("UpperBrakeModule", 0);
	clawPorts.upperBrakePort = _preferences->GetInt("UpperBrakePort", 1);
	clawPorts.lowerGrabberModule = _preferences->GetInt("LowerGrabberModule", 0);
	clawPorts.lowerGrabberPort = _preferences->GetInt("LowerGrabberPort", 2);
	clawPorts.lowerBrakeModule = _preferences->GetInt("LowerBrakeModule", 0);
	clawPorts.lowerBrakePort = _preferences->GetInt("LowerBrakePort", 3);

	dollyPorts.dollyModule = _preferences->GetInt("DollyModule", 0);
	dollyPorts.dollyPort = _preferences->GetInt("DollyPort", 4);

	toteMoverPorts.toteMoverPort = _preferences->GetInt("ToteMoverPort", 5);

	compressorPorts.compressorModule = _preferences->GetInt("CompressorModule", 0);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);

	driverButtons.shiftButton = _preferences->GetInt("ShiftButton", 6);
	driverButtons.slowButton = _preferences->GetInt("SlowButton", 5);
	driverButtons.toggleEnhancedDriveButton = _preferences->GetInt("ToggleEnhancedDriveButton", 8);

	operatorButtons.toggleDollyButton = _preferences->GetInt("ToggleDollyButton", 3);
	operatorButtons.toteMoverLeftButton = _preferences->GetInt("ToteMoverLeftButton", 2);
	operatorButtons.toteMoverRightButton = _preferences->GetInt("ToteMoverRightButton", 1);

	driverAxes.leftX = _preferences->GetInt("DriverLeftX", 0);
	driverAxes.leftY = _preferences->GetInt("DriverLeftY", 1);
	driverAxes.rightX = _preferences->GetInt("DriverRightX", 4);
	driverAxes.rightY = _preferences->GetInt("DriverRightY", 5);

	operatorAxes.leftX = _preferences->GetInt("OperatorLeftX", 0);
	operatorAxes.leftY = _preferences->GetInt("OperatorLeftY", 0);
	operatorAxes.rightX = _preferences->GetInt("OperatorRightX", 0);
	operatorAxes.rightY = _preferences->GetInt("OperatorRightY", 0);

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	clawStates.upperClawGrab = _preferences->GetBoolean("UpperClawGrab", true);
	clawStates.upperClawBrakeOn = _preferences->GetBoolean("UpperClawBrakeOn", false);
	clawStates.lowerClawGrab = _preferences->GetBoolean("LowerClawGrab", true);
	clawStates.lowerClawBrakeOn = _preferences->GetBoolean("LowerClawBrakeOn", false);

	dollyStates.back = _preferences->GetBoolean("DollyBack", true);
	dollyStates.forward = _preferences->GetBoolean("DollyForward", false);

	toteMoverStates.moveTotesLeft = _preferences->GetDouble("MoveTotesLeft", -1);
	toteMoverStates.moveTotesRight = _preferences->GetDouble("MoveTotesRight", 1);
	toteMoverStates.stop = _preferences->GetDouble("ToteMoverStop", 0);

	driveConstants.maxVelocityHigh = _preferences->GetDouble("MaxVelocityHigh", 0);
	driveConstants.maxVelocityLow = _preferences->GetDouble("MaxVelocityLow", 0);
	driveConstants.enhanceScalar = _preferences->GetDouble("EnhanceScalar", 0.9);
	driveConstants.slowScalar = _preferences->GetDouble("SlowScalar", 0.75);
	driveConstants.distancePerPulse = _preferences->GetDouble("DistancePerPulse", 0.0490874);

	pneumaticConstants.startingPressure = _preferences->GetDouble("StartingPressure", 115);
	pneumaticConstants.currentPressure = pneumaticConstants.startingPressure;
	pneumaticConstants.compressorOnPressure = _preferences->GetDouble("CompressorOnPressure", 80);
	pneumaticConstants.shifterActuationLoss = _preferences->GetDouble("ShifterActuationLoss", 0);
	pneumaticConstants.dollyActuationLoss = _preferences->GetDouble("DollyActuationLoss", 0);
	pneumaticConstants.upperClawGrabberActuationLoss = _preferences->GetDouble("UpperClawGrabberActuationLoss", 0);
	pneumaticConstants.upperClawBrakeActuationLoss = _preferences->GetDouble("UpperClawBrakeActuationLoss", 0);
	pneumaticConstants.lowerClawGrabberActuationLoss = _preferences->GetDouble("LowerClawGrabberActuationLoss", 0);
	pneumaticConstants.lowerClawBrakeActuationLoss = _preferences->GetDouble("LowerClawBrakeActuationLoss", 0);

	updatePIDProfiles();
	SmartDashboard::PutData("UpdatePIDProfiles", new UpdatePIDProfiles());
	SmartDashboard::PutData("CompressorOn", new CompressorOn());
	SmartDashboard::PutData("CompressorOff", new CompressorOff());
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

PIDProfile Constants::getDriveProfile(bool highGear, bool encoderVelocityMode, int items) {
	if (encoderVelocityMode) {
		if (highGear == shifterStates.highGear) {
			return driveProfiles[0 + items];		//high gear velocity
		} else {
			return driveProfiles[5 + items];		//low gear velocity
		}
	} else {
		if (highGear == shifterStates.highGear) {
			return driveProfiles[10 + items];		//high gear position
		} else {
			return driveProfiles[15 + items];		//low gear position
		}
	}
}

void Constants::updatePIDProfiles() {
	driveProfiles[0].p = _preferences->GetDouble("DriveProfile0P", 0);
	driveProfiles[0].i = _preferences->GetDouble("DriveProfile0I", 0);
	driveProfiles[0].d = _preferences->GetDouble("DriveProfile0D", 0);
	driveProfiles[0].f = _preferences->GetDouble("DriveProfile0F", 0);

	driveProfiles[1].p = _preferences->GetDouble("DriveProfile1P", 0);
	driveProfiles[1].i = _preferences->GetDouble("DriveProfile1I", 0);
	driveProfiles[1].d = _preferences->GetDouble("DriveProfile1D", 0);
	driveProfiles[1].f = _preferences->GetDouble("DriveProfile1F", 0);

	driveProfiles[2].p = _preferences->GetDouble("DriveProfile2P", 0);
	driveProfiles[2].i = _preferences->GetDouble("DriveProfile2I", 0);
	driveProfiles[2].d = _preferences->GetDouble("DriveProfile2D", 0);
	driveProfiles[2].f = _preferences->GetDouble("DriveProfile2F", 0);

	driveProfiles[3].p = _preferences->GetDouble("DriveProfile3P", 0);
	driveProfiles[3].i = _preferences->GetDouble("DriveProfile3I", 0);
	driveProfiles[3].d = _preferences->GetDouble("DriveProfile3D", 0);
	driveProfiles[3].f = _preferences->GetDouble("DriveProfile3F", 0);

	driveProfiles[4].p = _preferences->GetDouble("DriveProfile4P", 0);
	driveProfiles[4].i = _preferences->GetDouble("DriveProfile4I", 0);
	driveProfiles[4].d = _preferences->GetDouble("DriveProfile4D", 0);
	driveProfiles[4].f = _preferences->GetDouble("DriveProfile4F", 0);

	driveProfiles[5].p = _preferences->GetDouble("DriveProfile5P", 0);
	driveProfiles[5].i = _preferences->GetDouble("DriveProfile5I", 0);
	driveProfiles[5].d = _preferences->GetDouble("DriveProfile5D", 0);
	driveProfiles[5].f = _preferences->GetDouble("DriveProfile5F", 0);

	driveProfiles[6].p = _preferences->GetDouble("DriveProfile6P", 0);
	driveProfiles[6].i = _preferences->GetDouble("DriveProfile6I", 0);
	driveProfiles[6].d = _preferences->GetDouble("DriveProfile6D", 0);
	driveProfiles[6].f = _preferences->GetDouble("DriveProfile6F", 0);

	driveProfiles[7].p = _preferences->GetDouble("DriveProfile7P", 0);
	driveProfiles[7].i = _preferences->GetDouble("DriveProfile7I", 0);
	driveProfiles[7].d = _preferences->GetDouble("DriveProfile7D", 0);
	driveProfiles[7].f = _preferences->GetDouble("DriveProfile7F", 0);

	driveProfiles[8].p = _preferences->GetDouble("DriveProfile8P", 0);
	driveProfiles[8].i = _preferences->GetDouble("DriveProfile8I", 0);
	driveProfiles[8].d = _preferences->GetDouble("DriveProfile8D", 0);
	driveProfiles[8].f = _preferences->GetDouble("DriveProfile8F", 0);

	driveProfiles[9].p = _preferences->GetDouble("DriveProfile9P", 0);
	driveProfiles[9].i = _preferences->GetDouble("DriveProfile9I", 0);
	driveProfiles[9].d = _preferences->GetDouble("DriveProfile9D", 0);
	driveProfiles[9].f = _preferences->GetDouble("DriveProfile9F", 0);
}

void Constants::reducePressure(double pressureLoss) {
	pneumaticConstants.currentPressure -= pressureLoss;
	if (pneumaticConstants.currentPressure < pneumaticConstants.compressorOnPressure) {
		//Command *c = new CompressorOn();
		//c->Start();
	}
}














