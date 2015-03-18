/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"
#include "../Commands/Utilities/UpdatePIDProfiles.h"
#include "../Commands/Utilities/CompressorOn.h"
#include "../Commands/Utilities/CompressorOff.h"

Constants::Constants() {
	_preferences = Preferences::GetInstance();

	debug = _preferences->GetBoolean("Debug", true);

	autonomousConstants.autoScriptsDirectory = _preferences->GetString("AutoScriptDirectory", "/home/lvuser/scripts");

	drivePorts.talonLeftPort = _preferences->GetInt("DriveTalonLeftPort", 3);
	drivePorts.talonRightPort = _preferences->GetInt("DriveTalonRightPort", 4);
	drivePorts.shifterModule = _preferences->GetInt("ShifterModule", 0);
	drivePorts.shifterPort = _preferences->GetInt("ShifterPort", 5);
	drivePorts.encoderLeftPortA = _preferences->GetInt("DriveEncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("DriveEncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("DriveEncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("DriveEncoderRightPortB", 3);

	clawPorts.upperGrabberLeftModule = _preferences->GetInt("UpperGrabberLeftModule, 0");
	clawPorts.upperGrabberLeftPort = _preferences->GetInt("UpperGrabberLeftPort", 0);
	clawPorts.upperGrabberRightModule = _preferences->GetInt("UpperGrabberRightModule", 0);
	clawPorts.upperGrabberRightPort = _preferences->GetInt("UpperGrabberRightPort", 1);
	clawPorts.lowerGrabberLeftModule = _preferences->GetInt("LowerGrabberLeftModule", 0);
	clawPorts.lowerGrabberLeftPort = _preferences->GetInt("LowerGrabberLeftPort", 3);
	clawPorts.lowerGrabberRightModule = _preferences->GetInt("LowerGrabberRightModule", 0);
	clawPorts.lowerGrabberRightPort = _preferences->GetInt("LowerGrabberRightPort", 4);

	liftPorts.lowerTalonLeftPort = _preferences->GetInt("LiftLowerTalonLeftPort", 1);
	liftPorts.lowerTalonRightPort = _preferences->GetInt("LiftLowerTalonRightPort", 2);
	liftPorts.upperTalonPort = _preferences->GetInt("LiftUpperTalonPort", 0);
	liftPorts.lowerEncoderLeftPortA = _preferences->GetInt("LiftLowerEncoderLeftPortA", 4);
	liftPorts.lowerEncoderLeftPortB = _preferences->GetInt("LiftLowerEncoderLeftPortB", 5);
	liftPorts.lowerEncoderRightPortA = _preferences->GetInt("LiftLowerEncoderRightPortA", 6);
	liftPorts.lowerEncoderRightPortB = _preferences->GetInt("LiftLowerEncoderRightPortB", 7);
	liftPorts.upperEncoderPortA = _preferences->GetInt("LiftUpperEncoderPortA", 8);
	liftPorts.upperEncoderPortB = _preferences->GetInt("LiftUpperEncoderPortB", 9);

	compressorPorts.compressorModule = _preferences->GetInt("CompressorModule", 0);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);

	driverButtons.shiftButton = _preferences->GetInt("ShiftButton", 6);
	driverButtons.slowButton = _preferences->GetInt("SlowButton", 5);
	driverButtons.toggleEnhancedDriveButton = _preferences->GetInt("ToggleEnhancedDriveButton", 8);
	driverButtons.incrementTotalItemCountButton = _preferences->GetInt("IncrementTotalItemCountButton", 10);
	driverButtons.decrementTotalItemCountButton = _preferences->GetInt("DecrementTotalItemCountButton", 1);
	driverButtons.resetTotalItemCountButton = _preferences->GetInt("ResetTotalItemCountButton", 9);

	operatorButtons.lowerClawToggleGrabButton = _preferences->GetInt("LowerClawToggleGrabButton", 5);
	operatorButtons.lowerClawToggleGrabLeftButton = _preferences->GetInt("LowerClawToggleGrabLeftButton", 7);
	operatorButtons.lowerClawToggleGrabRightButton = _preferences->GetInt("LowerClawToggleGrabRightButton", 8);
	operatorButtons.upperClawToggleGrabButton = _preferences->GetInt("UpperClawToggleGrabButton", 6);
	operatorButtons.upperClawToggleGrabLeftButton = _preferences->GetInt("UpperClawToggleGrabLeftButton", 1);
	operatorButtons.upperClawToggleGrabRightButton = _preferences->GetInt("UpperClawToggleGrabRightButton", 3);
	operatorButtons.toggleLowerLiftAutomaticButton = _preferences->GetInt("ToggleLowerLiftAutomaticButton", 11);
	operatorButtons.toggleUpperLiftAutomaticButton = _preferences->GetInt("ToggleUpperLiftAutomaticButton", 12);

	driverAxes.leftX = _preferences->GetInt("DriverLeftX", 0);
	driverAxes.leftY = _preferences->GetInt("DriverLeftY", 1);
	driverAxes.rightX = _preferences->GetInt("DriverRightX", 4);
	driverAxes.rightY = _preferences->GetInt("DriverRightY", 5);

	operatorAxes.leftX = _preferences->GetInt("OperatorLeftX", 0);
	operatorAxes.leftY = _preferences->GetInt("OperatorLeftY", 1);
	operatorAxes.rightX = _preferences->GetInt("OperatorRightX", 2);
	operatorAxes.rightY = _preferences->GetInt("OperatorRightY", 3);

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	clawStates.upperClawLeftGrab = _preferences->GetBoolean("UpperClawGrab", false);
	clawStates.upperClawRightGrab = _preferences->GetBoolean("UpperClawRightGrab", false);
	clawStates.lowerClawLeftGrab = _preferences->GetBoolean("LowerClawLeftGrab", true);
	clawStates.lowerClawRightGrab = _preferences->GetBoolean("LowerClawRightGrab", true);

	driveConstants.enhancedMaxVelocityHigh[0] = _preferences->GetDouble("EnhancedMaxVelocityHigh0", 10);
	driveConstants.enhancedMaxVelocityLow[0] = _preferences->GetDouble("EnhancedMaxVelocityLow0", 1);
	driveConstants.enhancedMaxVelocityHigh[1] = _preferences->GetDouble("EnhancedMaxVelocityHigh1", 20);
	driveConstants.enhancedMaxVelocityLow[1] = _preferences->GetDouble("EnhancedMaxVelocityLow1", 2);
	driveConstants.enhancedMaxVelocityHigh[2] = _preferences->GetDouble("EnhancedMaxVelocityHigh2", 30);
	driveConstants.enhancedMaxVelocityLow[2] = _preferences->GetDouble("EnhancedMaxVelocityLow2", 3);
	driveConstants.enhancedMaxVelocityHigh[3] = _preferences->GetDouble("EnhancedMaxVelocityHigh3", 40);
	driveConstants.enhancedMaxVelocityLow[3] = _preferences->GetDouble("EnhancedMaxVelocityLow3", 4);
	driveConstants.enhancedMaxVelocityHigh[4] = _preferences->GetDouble("EnhancedMaxVelocityHigh4", 50);
	driveConstants.enhancedMaxVelocityLow[4] = _preferences->GetDouble("EnhancedMaxVelocityLow4", 5);
	driveConstants.enhancedMaxVelocityHigh[5] = _preferences->GetDouble("EnhancedMaxVelocityHigh5", 60);
	driveConstants.enhancedMaxVelocityLow[5] = _preferences->GetDouble("EnhancedMaxVelocityLow5", 6);
	driveConstants.enhancedMaxVelocityHigh[6] = _preferences->GetDouble("EnhancedMaxVelocityHigh6", 70);
	driveConstants.enhancedMaxVelocityLow[6] = _preferences->GetDouble("EnhancedMaxVelocityLow6", 7);
	driveConstants.enhancedMaxVelocityHigh[7] = _preferences->GetDouble("EnhancedMaxVelocityHigh7", 80);
	driveConstants.enhancedMaxVelocityLow[7] = _preferences->GetDouble("EnhancedMaxVelocityLow7", 8);
	driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[0];
	driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[0];
	driveConstants.slowScalar = _preferences->GetDouble("SlowScalar", 0.6);
	driveConstants.distancePerPulse = _preferences->GetDouble("DriveDistancePerPulse", 0.027271);
	driveConstants.shiftTime = _preferences->GetDouble("ShiftTime", 0.25);
	driveConstants.velocityTestSampleTime = _preferences->GetDouble("VelocityTestSampleTime", 1);
	driveConstants.velocityTestAccelerationTime = _preferences->GetDouble("VelocityTestAccelerationTime", 2);

	liftConstants.lowerDistancePerPulse = _preferences->GetDouble("LowerLiftDistancePerPulse", 0);
	liftConstants.upperDistancePerPulse = _preferences->GetDouble("UpperDistancePerPulse", 0);

	//hardcode levels here
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(0,0,"Lvl 0"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(10,1,"Lvl 1"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(20,2,"Lvl 2"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(30,3,"Lvl 3"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(0,1,"Lvl 1"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(10,2,"Lvl 2"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(20,3,"Lvl 3"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(30,4,"Lvl 4"));

	itemCounts.totalItems = 0;
	itemCounts.lowerClawItems = 0;
	itemCounts.upperClawItems = 0;
	itemCounts.totalMaxItems = _preferences->GetInt("TotalMaxItems", 7);
	itemCounts.lowerClawMaxItems = _preferences->GetInt("LowerClawMaxItems", 7);
	itemCounts.upperClawMaxItems = _preferences->GetInt("UpperClawMaxItems", 7);

	updatePIDProfiles();

	SmartDashboard::PutString("Compressor", "ON");

	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

void Constants::updatePIDProfiles() {
	lowGearDriveProfiles[0].p = _preferences->GetDouble("LowGearDriveProfile0P", 1);
	lowGearDriveProfiles[0].i = _preferences->GetDouble("LowGearDriveProfile0I", 1);
	lowGearDriveProfiles[0].d = _preferences->GetDouble("LowGearDriveProfile0D", 1);
	lowGearDriveProfiles[0].f = _preferences->GetDouble("LowGearDriveProfile0F", 1);

	lowGearDriveProfiles[1].p = _preferences->GetDouble("LowGearDriveProfile1P", 2);
	lowGearDriveProfiles[1].i = _preferences->GetDouble("LowGearDriveProfile1I", 2);
	lowGearDriveProfiles[1].d = _preferences->GetDouble("LowGearDriveProfile1D", 2);
	lowGearDriveProfiles[1].f = _preferences->GetDouble("LowGearDriveProfile1F", 2);

	lowGearDriveProfiles[2].p = _preferences->GetDouble("LowGearDriveProfile2P", 3);
	lowGearDriveProfiles[2].i = _preferences->GetDouble("LowGearDriveProfile2I", 3);
	lowGearDriveProfiles[2].d = _preferences->GetDouble("LowGearDriveProfile2D", 3);
	lowGearDriveProfiles[2].f = _preferences->GetDouble("LowGearDriveProfile2F", 3);

	lowGearDriveProfiles[3].p = _preferences->GetDouble("LowGearDriveProfile3P", 4);
	lowGearDriveProfiles[3].i = _preferences->GetDouble("LowGearDriveProfile3I", 4);
	lowGearDriveProfiles[3].d = _preferences->GetDouble("LowGearDriveProfile3D", 4);
	lowGearDriveProfiles[3].f = _preferences->GetDouble("LowGearDriveProfile3F", 4);

	lowGearDriveProfiles[4].p = _preferences->GetDouble("LowGearDriveProfile4P", 5);
	lowGearDriveProfiles[4].i = _preferences->GetDouble("LowGearDriveProfile4I", 5);
	lowGearDriveProfiles[4].d = _preferences->GetDouble("LowGearDriveProfile4D", 5);
	lowGearDriveProfiles[4].f = _preferences->GetDouble("LowGearDriveProfile4F", 5);

	lowGearDriveProfiles[5].p = _preferences->GetDouble("LowGearDriveProfile5P", 6);
	lowGearDriveProfiles[5].i = _preferences->GetDouble("LowGearDriveProfile5I", 6);
	lowGearDriveProfiles[5].d = _preferences->GetDouble("LowGearDriveProfile5D", 6);
	lowGearDriveProfiles[5].f = _preferences->GetDouble("LowGearDriveProfile5F", 6);

	lowGearDriveProfiles[6].p = _preferences->GetDouble("LowGearDriveProfile6P", 7);
	lowGearDriveProfiles[6].i = _preferences->GetDouble("LowGearDriveProfile6I", 7);
	lowGearDriveProfiles[6].d = _preferences->GetDouble("LowGearDriveProfile6D", 7);
	lowGearDriveProfiles[6].f = _preferences->GetDouble("LowGearDriveProfile6F", 7);

	lowGearDriveProfiles[7].p = _preferences->GetDouble("LowGearDriveProfile7P", 8);
	lowGearDriveProfiles[7].i = _preferences->GetDouble("LowGearDriveProfile7I", 8);
	lowGearDriveProfiles[7].d = _preferences->GetDouble("LowGearDriveProfile7D", 8);
	lowGearDriveProfiles[7].f = _preferences->GetDouble("LowGearDriveProfile7F", 8);

	highGearDriveProfiles[0].p = _preferences->GetDouble("HighGearDriveProfile0P", 10);
	highGearDriveProfiles[0].i = _preferences->GetDouble("HighGearDriveProfile0I", 10);
	highGearDriveProfiles[0].d = _preferences->GetDouble("HighGearDriveProfile0D", 10);
	highGearDriveProfiles[0].f = _preferences->GetDouble("HighGearDriveProfile0F", 10);

	highGearDriveProfiles[1].p = _preferences->GetDouble("HighGearDriveProfile1P", 20);
	highGearDriveProfiles[1].i = _preferences->GetDouble("HighGearDriveProfile1I", 20);
	highGearDriveProfiles[1].d = _preferences->GetDouble("HighGearDriveProfile1D", 20);
	highGearDriveProfiles[1].f = _preferences->GetDouble("HighGearDriveProfile1F", 20);

	highGearDriveProfiles[2].p = _preferences->GetDouble("HighGearDriveProfile2P", 30);
	highGearDriveProfiles[2].i = _preferences->GetDouble("HighGearDriveProfile2I", 30);
	highGearDriveProfiles[2].d = _preferences->GetDouble("HighGearDriveProfile2D", 30);
	highGearDriveProfiles[2].f = _preferences->GetDouble("HighGearDriveProfile2F", 30);

	highGearDriveProfiles[3].p = _preferences->GetDouble("HighGearDriveProfile3P", 40);
	highGearDriveProfiles[3].i = _preferences->GetDouble("HighGearDriveProfile3I", 40);
	highGearDriveProfiles[3].d = _preferences->GetDouble("HighGearDriveProfile3D", 40);
	highGearDriveProfiles[3].f = _preferences->GetDouble("HighGearDriveProfile3F", 40);

	highGearDriveProfiles[4].p = _preferences->GetDouble("HighGearDriveProfile4P", 50);
	highGearDriveProfiles[4].i = _preferences->GetDouble("HighGearDriveProfile4I", 50);
	highGearDriveProfiles[4].d = _preferences->GetDouble("HighGearDriveProfile4D", 50);
	highGearDriveProfiles[4].f = _preferences->GetDouble("HighGearDriveProfile4F", 50);

	highGearDriveProfiles[5].p = _preferences->GetDouble("HighGearDriveProfile5P", 60);
	highGearDriveProfiles[5].i = _preferences->GetDouble("HighGearDriveProfile5I", 60);
	highGearDriveProfiles[5].d = _preferences->GetDouble("HighGearDriveProfile5D", 60);
	highGearDriveProfiles[5].f = _preferences->GetDouble("HighGearDriveProfile5F", 60);

	highGearDriveProfiles[6].p = _preferences->GetDouble("HighGearDriveProfile6P", 70);
	highGearDriveProfiles[6].i = _preferences->GetDouble("HighGearDriveProfile6I", 70);
	highGearDriveProfiles[6].d = _preferences->GetDouble("HighGearDriveProfile6D", 70);
	highGearDriveProfiles[6].f = _preferences->GetDouble("HighGearDriveProfile6F", 70);

	highGearDriveProfiles[7].p = _preferences->GetDouble("HighGearDriveProfile7P", 80);
	highGearDriveProfiles[7].i = _preferences->GetDouble("HighGearDriveProfile7I", 80);
	highGearDriveProfiles[7].d = _preferences->GetDouble("HighGearDriveProfile7D", 80);
	highGearDriveProfiles[7].f = _preferences->GetDouble("HighGearDriveProfile7F", 80);

	upperLiftProfiles[0].p = _preferences->GetDouble("UpperLiftProfiles0P", 0);
	upperLiftProfiles[0].i = _preferences->GetDouble("UpperLiftProfiles0I", 0);
	upperLiftProfiles[0].d = _preferences->GetDouble("UpperLiftProfiles0D", 0);
	upperLiftProfiles[0].f = _preferences->GetDouble("UpperLiftProfiles0F", 0);

	upperLiftProfiles[1].p = _preferences->GetDouble("UpperLiftProfiles1P", 1);
	upperLiftProfiles[1].i = _preferences->GetDouble("UpperLiftProfiles1I", 1);
	upperLiftProfiles[1].d = _preferences->GetDouble("UpperLiftProfiles1D", 1);
	upperLiftProfiles[1].f = _preferences->GetDouble("UpperLiftProfiles1F", 1);

	upperLiftProfiles[2].p = _preferences->GetDouble("UpperLiftProfiles2P", 2);
	upperLiftProfiles[2].i = _preferences->GetDouble("UpperLiftProfiles2I", 2);
	upperLiftProfiles[2].d = _preferences->GetDouble("UpperLiftProfiles2D", 2);
	upperLiftProfiles[2].f = _preferences->GetDouble("UpperLiftProfiles2F", 2);

	upperLiftProfiles[3].p = _preferences->GetDouble("UpperLiftProfiles3P", 3);
	upperLiftProfiles[3].i = _preferences->GetDouble("UpperLiftProfiles3I", 3);
	upperLiftProfiles[3].d = _preferences->GetDouble("UpperLiftProfiles3D", 3);
	upperLiftProfiles[3].f = _preferences->GetDouble("UpperLiftProfiles3F", 3);

	upperLiftProfiles[4].p = _preferences->GetDouble("UpperLiftProfiles4P", 4);
	upperLiftProfiles[4].i = _preferences->GetDouble("UpperLiftProfiles4I", 4);
	upperLiftProfiles[4].d = _preferences->GetDouble("UpperLiftProfiles4D", 4);
	upperLiftProfiles[4].f = _preferences->GetDouble("UpperLiftProfiles4F", 4);

	upperLiftProfiles[5].p = _preferences->GetDouble("UpperLiftProfiles5P", 5);
	upperLiftProfiles[5].i = _preferences->GetDouble("UpperLiftProfiles5I", 5);
	upperLiftProfiles[5].d = _preferences->GetDouble("UpperLiftProfiles5D", 5);
	upperLiftProfiles[5].f = _preferences->GetDouble("UpperLiftProfiles5F", 5);

	upperLiftProfiles[6].p = _preferences->GetDouble("UpperLiftProfiles6P", 6);
	upperLiftProfiles[6].i = _preferences->GetDouble("UpperLiftProfiles6I", 6);
	upperLiftProfiles[6].d = _preferences->GetDouble("UpperLiftProfiles6D", 6);
	upperLiftProfiles[6].f = _preferences->GetDouble("UpperLiftProfiles6F", 6);

	upperLiftProfiles[7].p = _preferences->GetDouble("UpperLiftProfiles7P", 7);
	upperLiftProfiles[7].i = _preferences->GetDouble("UpperLiftProfiles7I", 7);
	upperLiftProfiles[7].d = _preferences->GetDouble("UpperLiftProfiles7D", 7);
	upperLiftProfiles[7].f = _preferences->GetDouble("UpperLiftProfiles7F", 7);

	lowerLiftProfiles[0].p = _preferences->GetDouble("LowerLiftProfiles0P", 0);
	lowerLiftProfiles[0].i = _preferences->GetDouble("LowerLiftProfiles0I", 0);
	lowerLiftProfiles[0].d = _preferences->GetDouble("LowerLiftProfiles0D", 0);
	lowerLiftProfiles[0].f = _preferences->GetDouble("LowerLiftProfiles0F", 0);

	lowerLiftProfiles[1].p = _preferences->GetDouble("LowerLiftProfiles1P", 1);
	lowerLiftProfiles[1].i = _preferences->GetDouble("LowerLiftProfiles1I", 1);
	lowerLiftProfiles[1].d = _preferences->GetDouble("LowerLiftProfiles1D", 1);
	lowerLiftProfiles[1].f = _preferences->GetDouble("LowerLiftProfiles1F", 1);

	lowerLiftProfiles[2].p = _preferences->GetDouble("LowerLiftProfiles2P", 2);
	lowerLiftProfiles[2].i = _preferences->GetDouble("LowerLiftProfiles2I", 2);
	lowerLiftProfiles[2].d = _preferences->GetDouble("LowerLiftProfiles2D", 2);
	lowerLiftProfiles[2].f = _preferences->GetDouble("LowerLiftProfiles2F", 2);

	lowerLiftProfiles[3].p = _preferences->GetDouble("LowerLiftProfiles3P", 3);
	lowerLiftProfiles[3].i = _preferences->GetDouble("LowerLiftProfiles3I", 3);
	lowerLiftProfiles[3].d = _preferences->GetDouble("LowerLiftProfiles3D", 3);
	lowerLiftProfiles[3].f = _preferences->GetDouble("LowerLiftProfiles3F", 3);

	lowerLiftProfiles[4].p = _preferences->GetDouble("LowerLiftProfiles4P", 4);
	lowerLiftProfiles[4].i = _preferences->GetDouble("LowerLiftProfiles4I", 4);
	lowerLiftProfiles[4].d = _preferences->GetDouble("LowerLiftProfiles4D", 4);
	lowerLiftProfiles[4].f = _preferences->GetDouble("LowerLiftProfiles4F", 4);

	lowerLiftProfiles[5].p = _preferences->GetDouble("LowerLiftProfiles5P", 5);
	lowerLiftProfiles[5].i = _preferences->GetDouble("LowerLiftProfiles5I", 5);
	lowerLiftProfiles[5].d = _preferences->GetDouble("LowerLiftProfiles5D", 5);
	lowerLiftProfiles[5].f = _preferences->GetDouble("LowerLiftProfiles5F", 5);

	lowerLiftProfiles[6].p = _preferences->GetDouble("LowerLiftProfiles6P", 6);
	lowerLiftProfiles[6].i = _preferences->GetDouble("LowerLiftProfiles6I", 6);
	lowerLiftProfiles[6].d = _preferences->GetDouble("LowerLiftProfiles6D", 6);
	lowerLiftProfiles[6].f = _preferences->GetDouble("LowerLiftProfiles6F", 6);

	lowerLiftProfiles[7].p = _preferences->GetDouble("LowerLiftProfiles7P", 7);
	lowerLiftProfiles[7].i = _preferences->GetDouble("LowerLiftProfiles7I", 7);
	lowerLiftProfiles[7].d = _preferences->GetDouble("LowerLiftProfiles7D", 7);
	lowerLiftProfiles[7].f = _preferences->GetDouble("LowerLiftProfiles7F", 7);
}


PIDProfile Constants::getDriveProfile(bool shifterState) {
	if (shifterState == shifterStates.highGear) {
		return highGearDriveProfiles[itemCounts.totalItems];
	} else {
		return lowGearDriveProfiles[itemCounts.totalItems];
	}
}

PIDProfile Constants::getUpperLiftProfile() {
	return upperLiftProfiles[itemCounts.upperClawItems];
}

PIDProfile Constants::getLowerLiftProfile() {
	return lowerLiftProfiles[itemCounts.lowerClawItems];
}

void Constants::calculateClawItems(int lowerClawPosition,
								   int upperClawPosition,
								   bool lowerClawClosed,
								   bool upperClawClosed) {
	if (!upperClawClosed) {
		itemCounts.upperClawItems = 0;
	} else {
		itemCounts.upperClawItems = itemCounts.totalItems - upperClawPosition;
		if (itemCounts.upperClawItems < 0) {
			itemCounts.upperClawItems = 0;
		}
	}

	if (!lowerClawClosed) {
		itemCounts.lowerClawItems = 0;
	} else {
		itemCounts.lowerClawItems = itemCounts.totalItems - lowerClawPosition - itemCounts.upperClawItems;
		if (itemCounts.lowerClawItems < 0) {
			itemCounts.lowerClawItems = 0;
		}
	}

	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::incrementTotalItems() {
	if (itemCounts.totalItems < itemCounts.totalMaxItems) {
		itemCounts.totalItems++;
		driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
		driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	}
	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

void Constants::decrementTotalItems() {
	if (itemCounts.totalItems > 0) {
		itemCounts.totalItems--;
		driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
		driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	}
	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

void Constants::resetTotalItems() {
	itemCounts.totalItems = 0;
	driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
	driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

void Constants::incrementLowerClawItems() {
	if (itemCounts.lowerClawItems < itemCounts.lowerClawMaxItems) {
		itemCounts.lowerClawItems++;
		incrementTotalItems();
	}
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::decrementLowerClawItems() {
	if (itemCounts.lowerClawItems > 0) {
		itemCounts.lowerClawItems--;
		decrementTotalItems();
	}
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::resetLowerClawItems() {
	itemCounts.totalItems -= itemCounts.lowerClawItems;
	itemCounts.lowerClawItems = 0;
	driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
	driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::incrementUpperClawItems() {
	if (itemCounts.upperClawItems < itemCounts.upperClawMaxItems) {
		itemCounts.upperClawItems++;
		incrementTotalItems();
	}
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

void Constants::decrementUpperClawItems() {
	if (itemCounts.upperClawItems > 0) {
		itemCounts.upperClawItems--;
		decrementTotalItems();
	}
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

void Constants::resetUpperClawItems() {
	itemCounts.totalItems -= itemCounts.upperClawItems;
	itemCounts.upperClawItems = 0;
	driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
	driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}













