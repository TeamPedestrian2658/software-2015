/*
 * Constants.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#ifndef SRC_UTILITIES_CONSTANTS_H_
#define SRC_UTILITIES_CONSTANTS_H_

class Constants {
public:
	Constants();
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
		double maxVelocity;
		double enhanceScalar;
		double slowScalar;
	} driveConstants;
	virtual ~Constants();

	double getDriveP();
	double getDriveI();
	double getDriveD();
	double getDriveF();
};

#endif /* SRC_UTILITIES_CONSTANTS_H_ */
