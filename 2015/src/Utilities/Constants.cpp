/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"

Constants::Constants() {
	drivePorts.talonLeftPort = 0;
	drivePorts.talonRightPort = 1;
	drivePorts.shifterLeftModule = 0;
	drivePorts.shifterRightModule = 0;
	drivePorts.shifterLeftPort = 0;
	drivePorts.shifterRightPort = 1;
	drivePorts.encoderLeftPortA = 0;
	drivePorts.encoderLeftPortB = 1;
	drivePorts.encoderRightPortA = 2;
	drivePorts.encoderRightPortB = 3;

	oiPorts.driverPort = 0;
	oiPorts.operatorPort = 1;
	oiPorts.shiftButton = 6;
	oiPorts.slowButton = 5;
	oiPorts.toggleEnhanceButton = 8;
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

