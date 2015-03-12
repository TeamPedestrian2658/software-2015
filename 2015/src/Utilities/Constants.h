/*
 * Constants.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#ifndef SRC_UTILITIES_CONSTANTS_H_
#define SRC_UTILITIES_CONSTANTS_H_

#include "WPILib.h"
#include <string>

using namespace std;

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
	struct AutonomousConstants {
		string autoScriptsDirectory;
	} autonomousConstants;
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
		int upperGrabberLeftModule;
		int upperGrabberLeftPort;
		int upperGrabberRightModule;
		int upperGrabberRightPort;
		int lowerGrabberLeftModule;
		int lowerGrabberLeftPort;
		int lowerGrabberRightModule;
		int lowerGrabberRightPort;
	} clawPorts;
	struct LiftPorts {
		int lowerTalonLeftPort;
		int lowerTalonRightPort;
		int upperTalonPort;
		int lowerEncoderLeftPortA;
		int lowerEncoderLeftPortB;
		int lowerEncoderRightPortA;
		int lowerEncoderRightPortB;
		int upperEncoderPortA;
		int upperEncoderPortB;
	} liftPorts;
	struct CompressorPorts {
		int compressorModule;
	} compressorPorts;
	struct OIPorts {
		int driverPort;
		int operatorPort;
	} oiPorts;
	struct DriverButtons {
		int shiftButton;
		int slowButton;
		int toggleEnhancedDriveButton;
	} driverButtons;
	struct OperatorButtons {
		int lowerClawGrabLeftButton;
		int lowerClawGrabRightButton;
		int lowerClawReleaseLeftButton;
		int lowerClawReleaseRightButton;
		int lowerClawItemCountResetButton;
		int lowerClawItemCountIncrementButton;
		int lowerClawItemCountDecrementButton;
		int toggleLowerLiftAutomaticButton;
		int toggleUpperLiftAutomaticButton;
	} operatorButtons;
	struct DriverAxes {
		int leftX;
		int leftY;
		int rightX;
		int rightY;
	} driverAxes;
	struct OperatorAxes {
		int leftX;
		int leftY;
		int rightX;
		int rightY;
	} operatorAxes;
	struct ShifterStates {
		bool highGear;
		bool lowGear;
	} shifterStates;
	struct ClawStates {
		bool upperClawLeftGrab;
		bool upperClawRightGrab;
		bool lowerClawLeftGrab;
		bool lowerClawRightGrab;
	} clawStates;
	struct DriveConstants {
		double enhancedMaxVelocityHigh[8];
		double enhancedMaxVelocityLow[8];
		double currentEnhancedMaxVelocityHigh;
		double currentEnhancedMaxVelocityLow;
		double slowScalar;
		double distancePerPulse;
		double shiftTime;
		double velocityTestSampleTime;
		double velocityTestAccelerationTime;
	} driveConstants;
	struct LiftConstants {
		double lowerDistancePerPulse;
		double upperDistancePerPulse;
		vector<tuple<double, int, string>> upperLiftLevels;			//setpoint, possession level, name
		vector<tuple<double, int, string>> lowerLiftLevels;
	} liftConstants;
	struct ItemCounts {
		int totalItems;
		int lowerClawItems;
		int upperClawItems;
		int totalMaxItems;
		int lowerClawMaxItems;
		int upperClawMaxItems;
	} itemCounts;
	PIDProfile lowGearDriveProfiles[8];
	PIDProfile highGearDriveProfiles[8];
	PIDProfile upperLiftProfiles[8];
	PIDProfile lowerLiftProfiles[8];
	virtual ~Constants();

	void updatePIDProfiles();
	PIDProfile getDriveProfile(bool highGear);
	PIDProfile getUpperLiftProfile();
	PIDProfile getLowerLiftProfile();

	void calculateClawItems(int lowerClawPosition,
							int upperClawPosition,
							bool lowerClawClosed,
							bool upperClawClosed);

	void incrementTotalItems();
	void decrementTotalItems();
	void resetTotalItems();

	void incrementLowerClawItems();
	void decrementLowerClawItems();
	void resetLowerClawItems();

	void incrementUpperClawItems();
	void decrementUpperClawItems();
	void resetUpperClawItems();
};

#endif /* SRC_UTILITIES_CONSTANTS_H_ */
