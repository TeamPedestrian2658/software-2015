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
	} oiPorts;
	struct DriverButtons {
		int shiftButton;
		int slowButton;
		int toggleEnhancedDriveButton;
	} driverButtons;
	struct OperatorButtons {
		int toggleDollyButton;
		int toteMoverLeftButton;
		int toteMoverRightButton;
		int upperClawGrabButton;
		int upperClawReleaseButton;
		int lowerClawGrabButton;
		int lowerClawReleaseButton;
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
		bool upperClawBrakeOn;
		bool lowerClawGrab;
		bool lowerClawBrakeOn;
	} clawStates;
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
		double shiftTime;
		double velocityTestSampleTime;
		double velocityTestAccelerationTime;
	} driveConstants;
	struct LiftConstants {
		double distancePerPulse;
	} liftConstants;
	struct PneumaticConstants {
		double startingPressure;
		double currentPressure;
		double compressorOnPressure;
		double shifterActuationLoss;
		double dollyActuationLoss;
		double upperClawGrabberActuationLoss;
		double upperClawBrakeActuationLoss;
		double lowerClawGrabberActuationLoss;
		double lowerClawBrakeActuationLoss;
	} pneumaticConstants;
	PIDProfile driveProfiles[20];
	virtual ~Constants();

	PIDProfile getDriveProfile(bool highGear, bool encoderVelocityMode, int items);
	void updatePIDProfiles();

	void reducePressure(double pressureLoss);
};

#endif /* SRC_UTILITIES_CONSTANTS_H_ */
