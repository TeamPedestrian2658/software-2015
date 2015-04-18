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
	bool debug;
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
		int upperGrabberModule;
		int upperGrabberPort;
		int lowerGrabberLeftModule;
		int lowerGrabberLeftPort;
		int lowerGrabberRightModule;
		int lowerGrabberRightPort;
	} clawPorts;
	struct LiftPorts {
		int talonLeftPort;
		int talonRightPort;
		int encoderPortA;
		int encoderPortB;
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
		int incrementItemCountButton;
		int decrementItemCountButton;
		int resetItemCountButton;
		int compressorOnButton;
		int compressorOffButton;
	} driverButtons;
	struct OperatorButtons {
		int lowerClawToggleGrabButton;
		int lowerClawToggleGrabLeftButton;
		int lowerClawToggleGrabRightButton;
		int upperClawToggleGrabButton;
		int toggleLiftAutomaticButton;
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
		bool upperClawGrab;
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
	} driveConstants;
	struct LiftConstants {
		double distancePerPulse;			//setpoint, possession level, name
		vector<tuple<double, int, string>> liftLevels;
	} liftConstants;
	struct ItemCounts {
		int items;
		int maxItems;
	} itemCounts;
	PIDProfile lowGearDriveProfiles[8];
	PIDProfile highGearDriveProfiles[8];
	PIDProfile liftProfiles[8];
	virtual ~Constants();

	void updatePIDProfiles();
	PIDProfile getDriveProfile(bool shifterState);
	PIDProfile getLiftProfile(int lowerClawPosition,
							  bool lowerClawClosed);

	void incrementItemCount();
	void decrementItemCount();
	void resetItemCount();
};

#endif /* SRC_UTILITIES_CONSTANTS_H_ */
