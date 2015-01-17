/*
 * Constants.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#ifndef SRC_UTILITIES_CONSTANTS_H_
#define SRC_UTILITIES_CONSTANTS_H_

#include "WPILib.h"

struct PIDProfile {
		double p;
		double i;
		double d;
		double f;
};

class Constants {
public:
	Constants();
	Preferences *_preferences;
	struct DrivePorts {
		int talonLeftPort;
		int talonRightPort;
		int shifterLeftModule;
		int shifterRightModule;
		int shifterLeftPort;
		int shifterRightPort;
		int encoderLeftPortA;
		int encoderLeftPortB;
		int encoderRightPortA;
		int encoderRightPortB;
	} drivePorts;
	struct OIPorts {
		int driverPort;
		int operatorPort;
		int shiftButton;
		int slowButton;
		int toggleEnhanceButton;
	} oiPorts;
	struct ShifterStates {
		bool highGear;
		bool lowGear;
	} shifterStates;
	struct DriveConstants {
		double maxVelocityHigh;
		double maxVelocityLow;
		double enhanceScalar;
		double slowScalar;
	} driveConstants;
	PIDProfile driveProfiles[10];			//0-4 are for low gear, 5-9 are for high gear
	virtual ~Constants();

	PIDProfile getDriveProfile(bool highGear, int items);
};

#endif /* SRC_UTILITIES_CONSTANTS_H_ */
