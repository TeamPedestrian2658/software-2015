/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"
#include "../Commands/UpdatePIDProfiles.h"

Constants::Constants() {
	_preferences = Preferences::GetInstance();

	drivePorts.talonLeftPort = _preferences->GetInt("TalonLeftPort", 0);
	drivePorts.talonRightPort = _preferences->GetInt("TalonRightPort", 1);
	drivePorts.shifterModule = _preferences->GetInt("ShifterModule", 0);
	drivePorts.shifterPort = _preferences->GetInt("ShifterPort", 0);
	drivePorts.encoderLeftPortA = _preferences->GetInt("EncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("EncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("EncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("EncoderRightPortB", 3);

	clawPorts.upperGrabberModule = _preferences->GetInt("UpperGrabberModule, 0");
	clawPorts.upperGrabberPort = _preferences->GetInt("UpperGrabberPort", 1);
	clawPorts.upperBrakeModule = _preferences->GetInt("UpperBrakeModule", 0);
	clawPorts.upperBrakePort = _preferences->GetInt("UpperBrakePort", 2);
	clawPorts.lowerGrabberModule = _preferences->GetInt("LowerGrabberModule", 0);
	clawPorts.lowerGrabberPort = _preferences->GetInt("LowerGrabberPort", 3);
	clawPorts.lowerBrakeModule = _preferences->GetInt("LowerBrakeModule", 0);
	clawPorts.lowerBrakePort = _preferences->GetInt("LowerBrakePort", 4);

	dollyPorts.dollyModule = _preferences->GetInt("DollyModule", 0);
	dollyPorts.dollyPort = _preferences->GetInt("DollyPort", 5);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);
	oiPorts.shiftButton = _preferences->GetInt("ShiftButton", 6);
	oiPorts.slowButton = _preferences->GetInt("SlowButton", 5);
	oiPorts.toggleEnhanceDriveButton = _preferences->GetInt("ToggleEnhanceDriveButton", 8);
	oiPorts.toggleDollyButton = _preferences->GetInt("ToggleDollyButton", 3);

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	dollyStates.back = _preferences->GetBoolean("DollyBack", true);
	dollyStates.forward = _preferences->GetBoolean("DollyForward", false);

	driveConstants.maxVelocityHigh = _preferences->GetDouble("MaxVelocityHigh", 0);
	driveConstants.maxVelocityLow = _preferences->GetDouble("MaxVelocityLow", 0);
	driveConstants.enhanceScalar = _preferences->GetDouble("EnhanceScalar", 0.9);
	driveConstants.slowScalar = _preferences->GetDouble("SlowScalar", 0.75);
	driveConstants.distancePerPulse = _preferences->GetDouble("DistancePerPulse", 0);

	updatePIDProfiles();
	SmartDashboard::PutData(new UpdatePIDProfiles());
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

}
