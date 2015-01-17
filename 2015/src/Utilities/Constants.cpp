/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"

Constants::Constants() {
	_preferences = Preferences::GetInstance();

	drivePorts.talonLeftPort = _preferences->GetInt("TalonLeftPort", 0);
	drivePorts.talonRightPort = _preferences->GetInt("TalonRightPort", 1);
	drivePorts.shifterLeftModule = _preferences->GetInt("ShifterLeftModule", 0);
	drivePorts.shifterRightModule = _preferences->GetInt("ShifterRightModule", 0);
	drivePorts.shifterLeftPort = _preferences->GetInt("ShifterLeftPort", 0);
	drivePorts.shifterRightPort = _preferences->GetInt("ShifterRightPort", 1);
	drivePorts.encoderLeftPortA = _preferences->GetInt("EncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("EncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("EncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("EncoderRightPortB", 3);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);
	oiPorts.shiftButton = _preferences->GetInt("ShiftButton", 6);
	oiPorts.slowButton = _preferences->GetInt("SlowButton", 5);
	oiPorts.toggleEnhanceButton = _preferences->GetInt("ToggleEnhanceButton", 8);

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	driveConstants.maxVelocityHigh = _preferences->GetDouble("MaxVelocityHigh", 0);
	driveConstants.maxVelocityLow = _preferences->GetDouble("MaxVelocityLow", 0);
	driveConstants.enhanceScalar = _preferences->GetDouble("EnhanceScalar", 0.9);
	driveConstants.slowScalar = _preferences->GetDouble("SlowScalar", 0.75);
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

PIDProfile Constants::getDriveProfile(bool highGear, int items) {
	return highGear ? driveProfiles[1 + items] : driveProfiles[0 + items];
}
