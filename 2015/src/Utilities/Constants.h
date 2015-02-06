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
		int shifterModule;
		int shifterPort;
		int encoderLeftPortA;
		int encoderLeftPortB;
		int encoderRightPortA;
		int encoderRightPortB;
	} drivePorts;
	struct ClawPorts {
		int upperGrabberModule;
		int upperGrabberPort;
		int upperBrakeModule;
		int upperBrakePort;
		int lowerGrabberModule;
		int lowerGrabberPort;
		int lowerBrakeModule;
		int lowerBrakePort;
	} clawPorts;
	struct DollyPorts {
		int dollyModule;
		int dollyPort;
	} dollyPorts;
	struct ToteMoverPorts {
		int toteMoverPort;
	} toteMoverPorts;
	struct CompressorPorts {
		int compressorModule;
	} compressorPorts;
	struct OIPorts {
		int driverPort;
		int operatorPort;
		int shiftButton;
		int slowButton;
		int toggleEnhanceDriveButton;
		int toggleDollyButton;
		int toteMoverLeftButton;
		int toteMoverRightButton;
	} oiPorts;
	struct ShifterStates {
		bool highGear;
		bool lowGear;
	} shifterStates;
	struct DollyStates {
		bool back;
		bool forward;
	} dollyStates;
	struct ToteMoverStates {
		double moveTotesLeft;
		double moveTotesRight;
		double stop;
	} toteMoverStates;
	struct DriveConstants {
		double maxVelocityHigh;
		double maxVelocityLow;
		double enhanceScalar;
		double slowScalar;
		double distancePerPulse;
	} driveConstants;
	PIDProfile driveProfiles[20];
	virtual ~Constants();

	PIDProfile getDriveProfile(bool highGear, bool encoderVelocityMode, int items);
	void updatePIDProfiles();
};

#endif /* SRC_UTILITIES_CONSTANTS_H_ */
