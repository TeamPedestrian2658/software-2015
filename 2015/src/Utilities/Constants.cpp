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

	operatorButtons.lowerClawToggleGrabButton = _preferences->GetInt("LowerClawToggleGrabButton", 5);
	operatorButtons.lowerClawToggleGrabLeftButton = _preferences->GetInt("LowerClawToggleGrabLeftButton", 3);
	operatorButtons.lowerClawToggleGrabRightButton = _preferences->GetInt("LowerClawToggleGrabRightButton", 4);
	operatorButtons.upperClawToggleGrabButton = _preferences->GetInt("UpperClawToggleGrabButton", 6);
	operatorButtons.upperClawToggleGrabLeftButton = _preferences->GetInt("UpperClawToggleGrabLeftButton", 1);
	operatorButtons.upperClawToggleGrabRightButton = _preferences->GetInt("UpperClawToggleGrabRightButton", 2);
	operatorButtons.toggleLowerLiftAutomaticButton = _preferences->GetInt("ToggleLowerLiftAutomaticButton", 9);
	operatorButtons.toggleUpperLiftAutomaticButton = _preferences->GetInt("ToggleUpperLiftAutomaticButton", 10);

	driverAxes.leftX = _preferences->GetInt("DriverLeftX", 0);
	driverAxes.leftY = _preferences->GetInt("DriverLeftY", 1);
	driverAxes.rightX = _preferences->GetInt("DriverRightX", 4);
	driverAxes.rightY = _preferences->GetInt("DriverRightY", 5);

	operatorAxes.leftX = _preferences->GetInt("OperatorLeftX", 0);
	operatorAxes.leftY = _preferences->GetInt("OperatorLeftY", 1);
	operatorAxes.rightX = _preferences->GetInt("OperatorRightX", 2);
	operatorAxes.rightY = _preferences->GetInt("OperatorRightY", 5);	//Change to 3 later

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	clawStates.upperClawLeftGrab = _preferences->GetBoolean("UpperClawGrab", false);
	clawStates.upperClawRightGrab = _preferences->GetBoolean("UpperClawRightGrab", false);
	clawStates.lowerClawLeftGrab = _preferences->GetBoolean("LowerClawLeftGrab", true);
	clawStates.lowerClawRightGrab = _preferences->GetBoolean("LowerClawRightGrab", true);

	driveConstants.enhancedMaxVelocityHigh[0] = _preferences->GetDouble("EnhancedMaxVelocityHigh0", 190);
	driveConstants.enhancedMaxVelocityLow[0] = _preferences->GetDouble("EnhancedMaxVelocityLow0", 75);
	driveConstants.enhancedMaxVelocityHigh[1] = _preferences->GetDouble("EnhancedMaxVelocityHigh1", 190);
	driveConstants.enhancedMaxVelocityLow[1] = _preferences->GetDouble("EnhancedMaxVelocityLow1", 75);
	driveConstants.enhancedMaxVelocityHigh[2] = _preferences->GetDouble("EnhancedMaxVelocityHigh2", 190);
	driveConstants.enhancedMaxVelocityLow[2] = _preferences->GetDouble("EnhancedMaxVelocityLow2", 75);
	driveConstants.enhancedMaxVelocityHigh[3] = _preferences->GetDouble("EnhancedMaxVelocityHigh3", 190);
	driveConstants.enhancedMaxVelocityLow[3] = _preferences->GetDouble("EnhancedMaxVelocityLow3", 75);
	driveConstants.enhancedMaxVelocityHigh[4] = _preferences->GetDouble("EnhancedMaxVelocityHigh4", 190);
	driveConstants.enhancedMaxVelocityLow[4] = _preferences->GetDouble("EnhancedMaxVelocityLow4", 75);
	driveConstants.enhancedMaxVelocityHigh[5] = _preferences->GetDouble("EnhancedMaxVelocityHigh5", 190);
	driveConstants.enhancedMaxVelocityLow[5] = _preferences->GetDouble("EnhancedMaxVelocityLow5", 75);
	driveConstants.enhancedMaxVelocityHigh[6] = _preferences->GetDouble("EnhancedMaxVelocityHigh6", 190);
	driveConstants.enhancedMaxVelocityLow[6] = _preferences->GetDouble("EnhancedMaxVelocityLow6", 75);
	driveConstants.enhancedMaxVelocityHigh[7] = _preferences->GetDouble("EnhancedMaxVelocityHigh7", 190);
	driveConstants.enhancedMaxVelocityLow[7] = _preferences->GetDouble("EnhancedMaxVelocityLow7", 75);
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
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(0,0,"Bottom"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(10,0,"Lvl 1"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(15, 0, "Lvl 1.5"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(20,0,"Lvl 2"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(30,0,"Lvl 3"));
	liftConstants.lowerLiftLevels.push_back(tuple<double, int, string>(40,0,"Top"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(0,0,"Bottom"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(10,0,"Lvl 1"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(20,0,"Lvl 2"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(30,0,"Lvl 3"));
	liftConstants.upperLiftLevels.push_back(tuple<double, int, string>(40,0,"Top"));

	itemCounts.totalItems = 0;
	itemCounts.lowerClawItems = 0;
	itemCounts.upperClawItems = 0;
	itemCounts.totalMaxItems = _preferences->GetInt("TotalMaxItems", 7);
	itemCounts.lowerClawMaxItems = _preferences->GetInt("LowerClawMaxItems", 7);
	itemCounts.upperClawMaxItems = _preferences->GetInt("UpperClawMaxItems", 7);

	updatePIDProfiles();
	SmartDashboard::PutData("UpdatePIDProfiles", new UpdatePIDProfiles());

	SmartDashboard::PutData("CompressorOn", new CompressorOn());
	SmartDashboard::PutData("CompressorOff", new CompressorOff());
	SmartDashboard::PutString("Compressor", "ON");

	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

void Constants::updatePIDProfiles() {
	lowGearDriveProfiles[0].p = _preferences->GetDouble("LowGearDriveProfile0P", 0);
	lowGearDriveProfiles[0].i = _preferences->GetDouble("LowGearDriveProfile0I", 0);
	lowGearDriveProfiles[0].d = _preferences->GetDouble("LowGearDriveProfile0D", 0);
	lowGearDriveProfiles[0].f = _preferences->GetDouble("LowGearDriveProfile0F", 0);

	lowGearDriveProfiles[1].p = _preferences->GetDouble("LowGearDriveProfile1P", 0);
	lowGearDriveProfiles[1].i = _preferences->GetDouble("LowGearDriveProfile1I", 0);
	lowGearDriveProfiles[1].d = _preferences->GetDouble("LowGearDriveProfile1D", 0);
	lowGearDriveProfiles[1].f = _preferences->GetDouble("LowGearDriveProfile1F", 0);

	lowGearDriveProfiles[2].p = _preferences->GetDouble("LowGearDriveProfile2P", 0);
	lowGearDriveProfiles[2].i = _preferences->GetDouble("LowGearDriveProfile2I", 0);
	lowGearDriveProfiles[2].d = _preferences->GetDouble("LowGearDriveProfile2D", 0);
	lowGearDriveProfiles[2].f = _preferences->GetDouble("LowGearDriveProfile2F", 0);

	lowGearDriveProfiles[3].p = _preferences->GetDouble("LowGearDriveProfile3P", 0);
	lowGearDriveProfiles[3].i = _preferences->GetDouble("LowGearDriveProfile3I", 0);
	lowGearDriveProfiles[3].d = _preferences->GetDouble("LowGearDriveProfile3D", 0);
	lowGearDriveProfiles[3].f = _preferences->GetDouble("LowGearDriveProfile3F", 0);

	lowGearDriveProfiles[4].p = _preferences->GetDouble("LowGearDriveProfile4P", 0);
	lowGearDriveProfiles[4].i = _preferences->GetDouble("LowGearDriveProfile4I", 0);
	lowGearDriveProfiles[4].d = _preferences->GetDouble("LowGearDriveProfile4D", 0);
	lowGearDriveProfiles[4].f = _preferences->GetDouble("LowGearDriveProfile4F", 0);

	lowGearDriveProfiles[5].p = _preferences->GetDouble("LowGearDriveProfile5P", 0);
	lowGearDriveProfiles[5].i = _preferences->GetDouble("LowGearDriveProfile5I", 0);
	lowGearDriveProfiles[5].d = _preferences->GetDouble("LowGearDriveProfile5D", 0);
	lowGearDriveProfiles[5].f = _preferences->GetDouble("LowGearDriveProfile5F", 0);

	lowGearDriveProfiles[6].p = _preferences->GetDouble("LowGearDriveProfile6P", 0);
	lowGearDriveProfiles[6].i = _preferences->GetDouble("LowGearDriveProfile6I", 0);
	lowGearDriveProfiles[6].d = _preferences->GetDouble("LowGearDriveProfile6D", 0);
	lowGearDriveProfiles[6].f = _preferences->GetDouble("LowGearDriveProfile6F", 0);

	lowGearDriveProfiles[7].p = _preferences->GetDouble("LowGearDriveProfile7P", 0);
	lowGearDriveProfiles[7].i = _preferences->GetDouble("LowGearDriveProfile7I", 0);
	lowGearDriveProfiles[7].d = _preferences->GetDouble("LowGearDriveProfile7D", 0);
	lowGearDriveProfiles[7].f = _preferences->GetDouble("LowGearDriveProfile7F", 0);

	highGearDriveProfiles[0].p = _preferences->GetDouble("HighGearDriveProfile0P", 0);
	highGearDriveProfiles[0].i = _preferences->GetDouble("HighGearDriveProfile0I", 0);
	highGearDriveProfiles[0].d = _preferences->GetDouble("HighGearDriveProfile0D", 0);
	highGearDriveProfiles[0].f = _preferences->GetDouble("HighGearDriveProfile0F", 0);

	highGearDriveProfiles[1].p = _preferences->GetDouble("HighGearDriveProfile1P", 0);
	highGearDriveProfiles[1].i = _preferences->GetDouble("HighGearDriveProfile1I", 0);
	highGearDriveProfiles[1].d = _preferences->GetDouble("HighGearDriveProfile1D", 0);
	highGearDriveProfiles[1].f = _preferences->GetDouble("HighGearDriveProfile1F", 0);

	highGearDriveProfiles[2].p = _preferences->GetDouble("HighGearDriveProfile2P", 0);
	highGearDriveProfiles[2].i = _preferences->GetDouble("HighGearDriveProfile2I", 0);
	highGearDriveProfiles[2].d = _preferences->GetDouble("HighGearDriveProfile2D", 0);
	highGearDriveProfiles[2].f = _preferences->GetDouble("HighGearDriveProfile2F", 0);

	highGearDriveProfiles[3].p = _preferences->GetDouble("HighGearDriveProfile3P", 0);
	highGearDriveProfiles[3].i = _preferences->GetDouble("HighGearDriveProfile3I", 0);
	highGearDriveProfiles[3].d = _preferences->GetDouble("HighGearDriveProfile3D", 0);
	highGearDriveProfiles[3].f = _preferences->GetDouble("HighGearDriveProfile3F", 0);

	highGearDriveProfiles[4].p = _preferences->GetDouble("HighGearDriveProfile4P", 0);
	highGearDriveProfiles[4].i = _preferences->GetDouble("HighGearDriveProfile4I", 0);
	highGearDriveProfiles[4].d = _preferences->GetDouble("HighGearDriveProfile4D", 0);
	highGearDriveProfiles[4].f = _preferences->GetDouble("HighGearDriveProfile4F", 0);

	highGearDriveProfiles[5].p = _preferences->GetDouble("HighGearDriveProfile5P", 0);
	highGearDriveProfiles[5].i = _preferences->GetDouble("HighGearDriveProfile5I", 0);
	highGearDriveProfiles[5].d = _preferences->GetDouble("HighGearDriveProfile5D", 0);
	highGearDriveProfiles[5].f = _preferences->GetDouble("HighGearDriveProfile5F", 0);

	highGearDriveProfiles[6].p = _preferences->GetDouble("HighGearDriveProfile6P", 0);
	highGearDriveProfiles[6].i = _preferences->GetDouble("HighGearDriveProfile6I", 0);
	highGearDriveProfiles[6].d = _preferences->GetDouble("HighGearDriveProfile6D", 0);
	highGearDriveProfiles[6].f = _preferences->GetDouble("HighGearDriveProfile6F", 0);

	highGearDriveProfiles[7].p = _preferences->GetDouble("HighGearDriveProfile7P", 0);
	highGearDriveProfiles[7].i = _preferences->GetDouble("HighGearDriveProfile7I", 0);
	highGearDriveProfiles[7].d = _preferences->GetDouble("HighGearDriveProfile7D", 0);
	highGearDriveProfiles[7].f = _preferences->GetDouble("HighGearDriveProfile7F", 0);

	upperLiftProfiles[0].p = _preferences->GetDouble("UpperLiftProfiles0P", 0);
	upperLiftProfiles[0].i = _preferences->GetDouble("UpperLiftProfiles0I", 0);
	upperLiftProfiles[0].d = _preferences->GetDouble("UpperLiftProfiles0D", 0);
	upperLiftProfiles[0].f = _preferences->GetDouble("UpperLiftProfiles0F", 0);

	upperLiftProfiles[1].p = _preferences->GetDouble("UpperLiftProfiles1P", 0);
	upperLiftProfiles[1].i = _preferences->GetDouble("UpperLiftProfiles1I", 0);
	upperLiftProfiles[1].d = _preferences->GetDouble("UpperLiftProfiles1D", 0);
	upperLiftProfiles[1].f = _preferences->GetDouble("UpperLiftProfiles1F", 0);

	upperLiftProfiles[2].p = _preferences->GetDouble("UpperLiftProfiles2P", 0);
	upperLiftProfiles[2].i = _preferences->GetDouble("UpperLiftProfiles2I", 0);
	upperLiftProfiles[2].d = _preferences->GetDouble("UpperLiftProfiles2D", 0);
	upperLiftProfiles[2].f = _preferences->GetDouble("UpperLiftProfiles2F", 0);

	upperLiftProfiles[3].p = _preferences->GetDouble("UpperLiftProfiles3P", 0);
	upperLiftProfiles[3].i = _preferences->GetDouble("UpperLiftProfiles3I", 0);
	upperLiftProfiles[3].d = _preferences->GetDouble("UpperLiftProfiles3D", 0);
	upperLiftProfiles[3].f = _preferences->GetDouble("UpperLiftProfiles3F", 0);

	upperLiftProfiles[4].p = _preferences->GetDouble("UpperLiftProfiles4P", 0);
	upperLiftProfiles[4].i = _preferences->GetDouble("UpperLiftProfiles4I", 0);
	upperLiftProfiles[4].d = _preferences->GetDouble("UpperLiftProfiles4D", 0);
	upperLiftProfiles[4].f = _preferences->GetDouble("UpperLiftProfiles4F", 0);

	upperLiftProfiles[5].p = _preferences->GetDouble("UpperLiftProfiles5P", 0);
	upperLiftProfiles[5].i = _preferences->GetDouble("UpperLiftProfiles5I", 0);
	upperLiftProfiles[5].d = _preferences->GetDouble("UpperLiftProfiles5D", 0);
	upperLiftProfiles[5].f = _preferences->GetDouble("UpperLiftProfiles5F", 0);

	upperLiftProfiles[6].p = _preferences->GetDouble("UpperLiftProfiles6P", 0);
	upperLiftProfiles[6].i = _preferences->GetDouble("UpperLiftProfiles6I", 0);
	upperLiftProfiles[6].d = _preferences->GetDouble("UpperLiftProfiles6D", 0);
	upperLiftProfiles[6].f = _preferences->GetDouble("UpperLiftProfiles6F", 0);

	upperLiftProfiles[7].p = _preferences->GetDouble("UpperLiftProfiles7P", 0);
	upperLiftProfiles[7].i = _preferences->GetDouble("UpperLiftProfiles7I", 0);
	upperLiftProfiles[7].d = _preferences->GetDouble("UpperLiftProfiles7D", 0);
	upperLiftProfiles[7].f = _preferences->GetDouble("UpperLiftProfiles7F", 0);

	lowerLiftProfiles[0].p = _preferences->GetDouble("LowerLiftProfiles0P", 0);
	lowerLiftProfiles[0].i = _preferences->GetDouble("LowerLiftProfiles0I", 0);
	lowerLiftProfiles[0].d = _preferences->GetDouble("LowerLiftProfiles0D", 0);
	lowerLiftProfiles[0].f = _preferences->GetDouble("LowerLiftProfiles0F", 0);

	lowerLiftProfiles[1].p = _preferences->GetDouble("LowerLiftProfiles1P", 0);
	lowerLiftProfiles[1].i = _preferences->GetDouble("LowerLiftProfiles1I", 0);
	lowerLiftProfiles[1].d = _preferences->GetDouble("LowerLiftProfiles1D", 0);
	lowerLiftProfiles[1].f = _preferences->GetDouble("LowerLiftProfiles1F", 0);

	lowerLiftProfiles[2].p = _preferences->GetDouble("LowerLiftProfiles2P", 0);
	lowerLiftProfiles[2].i = _preferences->GetDouble("LowerLiftProfiles2I", 0);
	lowerLiftProfiles[2].d = _preferences->GetDouble("LowerLiftProfiles2D", 0);
	lowerLiftProfiles[2].f = _preferences->GetDouble("LowerLiftProfiles2F", 0);

	lowerLiftProfiles[3].p = _preferences->GetDouble("LowerLiftProfiles3P", 0);
	lowerLiftProfiles[3].i = _preferences->GetDouble("LowerLiftProfiles3I", 0);
	lowerLiftProfiles[3].d = _preferences->GetDouble("LowerLiftProfiles3D", 0);
	lowerLiftProfiles[3].f = _preferences->GetDouble("LowerLiftProfiles3F", 0);

	lowerLiftProfiles[4].p = _preferences->GetDouble("LowerLiftProfiles4P", 0);
	lowerLiftProfiles[4].i = _preferences->GetDouble("LowerLiftProfiles4I", 0);
	lowerLiftProfiles[4].d = _preferences->GetDouble("LowerLiftProfiles4D", 0);
	lowerLiftProfiles[4].f = _preferences->GetDouble("LowerLiftProfiles4F", 0);

	lowerLiftProfiles[5].p = _preferences->GetDouble("LowerLiftProfiles5P", 0);
	lowerLiftProfiles[5].i = _preferences->GetDouble("LowerLiftProfiles5I", 0);
	lowerLiftProfiles[5].d = _preferences->GetDouble("LowerLiftProfiles5D", 0);
	lowerLiftProfiles[5].f = _preferences->GetDouble("LowerLiftProfiles5F", 0);

	lowerLiftProfiles[6].p = _preferences->GetDouble("LowerLiftProfiles6P", 0);
	lowerLiftProfiles[6].i = _preferences->GetDouble("LowerLiftProfiles6I", 0);
	lowerLiftProfiles[6].d = _preferences->GetDouble("LowerLiftProfiles6D", 0);
	lowerLiftProfiles[6].f = _preferences->GetDouble("LowerLiftProfiles6F", 0);

	lowerLiftProfiles[7].p = _preferences->GetDouble("LowerLiftProfiles7P", 0);
	lowerLiftProfiles[7].i = _preferences->GetDouble("LowerLiftProfiles7I", 0);
	lowerLiftProfiles[7].d = _preferences->GetDouble("LowerLiftProfiles7D", 0);
	lowerLiftProfiles[7].f = _preferences->GetDouble("LowerLiftProfiles7F", 0);
}


PIDProfile Constants::getDriveProfile(bool highGear) {
	if (highGear == shifterStates.highGear) {
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
	}

	if (!lowerClawClosed) {
		itemCounts.lowerClawItems = 0;
	} else {
		itemCounts.lowerClawItems = itemCounts.totalItems - lowerClawPosition - itemCounts.upperClawItems;
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
}

void Constants::decrementTotalItems() {
	if (itemCounts.totalItems > 0) {
		itemCounts.totalItems--;
		driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
		driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	}
	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);
}

void Constants::resetTotalItems() {
	itemCounts.totalItems = 0;
	driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.totalItems];
	driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.totalItems];
	SmartDashboard::PutNumber("Total Items", itemCounts.totalItems);
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













