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

	autonomousConstants.autoScriptsDirectory = _preferences->GetString("AutoScriptDirectory", "/home/lvuser/scripts")

	drivePorts.talonLeftPort = _preferences->GetInt("DriveTalonLeftPort", 3);
	drivePorts.talonRightPort = _preferences->GetInt("DriveTalonRightPort", 4);
	drivePorts.shifterModule = _preferences->GetInt("ShifterModule", 0);
	drivePorts.shifterPort = _preferences->GetInt("ShifterPort", 5);
	drivePorts.encoderLeftPortA = _preferences->GetInt("DriveEncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("DriveEncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("DriveEncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("DriveEncoderRightPortB", 3);

	clawPorts.upperGrabberModule = _preferences->GetInt("UpperGrabberModule, 0");
	clawPorts.upperGrabberPort = _preferences->GetInt("UpperGrabberPort", 0);
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

	operatorButtons.lowerClawGrabLeftButton = _preferences->GetInt("LowerClawGrabLeftButton", 5);
	operatorButtons.lowerClawGrabRightButton = _preferences->GetInt("LowerClawGrabRightButton", 6);
	operatorButtons.lowerClawReleaseLeftButton = _preferences->GetInt("LowerClawReleaseLeftButton", 7);
	operatorButtons.lowerClawReleaseRightButton = _preferences->GetInt("LowerClawReleaseRightButton", 8);
	operatorButtons.lowerClawItemCountResetButton = _preferences->GetInt("LowerClawItemCountResetButton", 4);
	operatorButtons.lowerClawItemCountIncrementButton = _preferences->GetInt("LowerClawItemCountIncrementButton", 3);
	operatorButtons.lowerClawItemCountDecrementButton = _preferences->GetInt("LowerClawItemCountDecrementButton", 1);
	operatorButtons.lowerLiftAutomaticDisableButton = _preferences->GetInt("LowerLiftAutomaticDisableButton", 11);
	operatorButtons.upperLiftAutomaticDisableButton = _preferences->GetInt("UpperLiftAutomaticDisableButton", 12);

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

	clawStates.upperClawGrab = _preferences->GetBoolean("UpperClawGrab", true);
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
	driveProfiles[0].p = _preferences->GetDouble("DriveProfile0P", 0);
	driveProfiles[0].i = _preferences->GetDouble("DriveProfile0I", 0);
	driveProfiles[0].d = _preferences->GetDouble("DriveProfile0D", 0);
	driveProfiles[0].f = _preferences->GetDouble("DriveProfile0F", 0);

	driveProfiles[1].p = _preferences->GetDouble("DriveProfile1P", 0);
	driveProfiles[1].i = _preferences->GetDouble("DriveProfile1I", 0);
	driveProfiles[1].d = _preferences->GetDouble("DriveProfile1D", 0);
	driveProfiles[1].f = _preferences->GetDouble("DriveProfile1F", 0);

	driveProfiles[2].p = _preferences->GetDouble("DriveProfile2P", 0);
	driveProfiles[2].i = _preferences->GetDouble("DriveProfile2I", 0);
	driveProfiles[2].d = _preferences->GetDouble("DriveProfile2D", 0);
	driveProfiles[2].f = _preferences->GetDouble("DriveProfile2F", 0);

	driveProfiles[3].p = _preferences->GetDouble("DriveProfile3P", 0);
	driveProfiles[3].i = _preferences->GetDouble("DriveProfile3I", 0);
	driveProfiles[3].d = _preferences->GetDouble("DriveProfile3D", 0);
	driveProfiles[3].f = _preferences->GetDouble("DriveProfile3F", 0);

	driveProfiles[4].p = _preferences->GetDouble("DriveProfile4P", 0);
	driveProfiles[4].i = _preferences->GetDouble("DriveProfile4I", 0);
	driveProfiles[4].d = _preferences->GetDouble("DriveProfile4D", 0);
	driveProfiles[4].f = _preferences->GetDouble("DriveProfile4F", 0);

	driveProfiles[5].p = _preferences->GetDouble("DriveProfile5P", 0);
	driveProfiles[5].i = _preferences->GetDouble("DriveProfile5I", 0);
	driveProfiles[5].d = _preferences->GetDouble("DriveProfile5D", 0);
	driveProfiles[5].f = _preferences->GetDouble("DriveProfile5F", 0);

	driveProfiles[6].p = _preferences->GetDouble("DriveProfile6P", 0);
	driveProfiles[6].i = _preferences->GetDouble("DriveProfile6I", 0);
	driveProfiles[6].d = _preferences->GetDouble("DriveProfile6D", 0);
	driveProfiles[6].f = _preferences->GetDouble("DriveProfile6F", 0);

	driveProfiles[7].p = _preferences->GetDouble("DriveProfile7P", 0);
	driveProfiles[7].i = _preferences->GetDouble("DriveProfile7I", 0);
	driveProfiles[7].d = _preferences->GetDouble("DriveProfile7D", 0);
	driveProfiles[7].f = _preferences->GetDouble("DriveProfile7F", 0);

	driveProfiles[8].p = _preferences->GetDouble("DriveProfile8P", 0);
	driveProfiles[8].i = _preferences->GetDouble("DriveProfile8I", 0);
	driveProfiles[8].d = _preferences->GetDouble("DriveProfile8D", 0);
	driveProfiles[8].f = _preferences->GetDouble("DriveProfile8F", 0);

	driveProfiles[9].p = _preferences->GetDouble("DriveProfile9P", 0);
	driveProfiles[9].i = _preferences->GetDouble("DriveProfile9I", 0);
	driveProfiles[9].d = _preferences->GetDouble("DriveProfile9D", 0);
	driveProfiles[9].f = _preferences->GetDouble("DriveProfile9F", 0);

	driveProfiles[10].p = _preferences->GetDouble("DriveProfile10P", 0);
	driveProfiles[10].i = _preferences->GetDouble("DriveProfile10I", 0);
	driveProfiles[10].d = _preferences->GetDouble("DriveProfile10D", 0);
	driveProfiles[10].f = _preferences->GetDouble("DriveProfile10F", 0);

	driveProfiles[11].p = _preferences->GetDouble("DriveProfile11P", 0);
	driveProfiles[11].i = _preferences->GetDouble("DriveProfile11I", 0);
	driveProfiles[11].d = _preferences->GetDouble("DriveProfile11D", 0);
	driveProfiles[11].f = _preferences->GetDouble("DriveProfile11F", 0);

	driveProfiles[12].p = _preferences->GetDouble("DriveProfile12P", 0);
	driveProfiles[12].i = _preferences->GetDouble("DriveProfile12I", 0);
	driveProfiles[12].d = _preferences->GetDouble("DriveProfile12D", 0);
	driveProfiles[12].f = _preferences->GetDouble("DriveProfile12F", 0);

	driveProfiles[13].p = _preferences->GetDouble("DriveProfile13P", 0);
	driveProfiles[13].i = _preferences->GetDouble("DriveProfile13I", 0);
	driveProfiles[13].d = _preferences->GetDouble("DriveProfile13D", 0);
	driveProfiles[13].f = _preferences->GetDouble("DriveProfile13F", 0);

	driveProfiles[14].p = _preferences->GetDouble("DriveProfile14P", 0);
	driveProfiles[14].i = _preferences->GetDouble("DriveProfile14I", 0);
	driveProfiles[14].d = _preferences->GetDouble("DriveProfile14D", 0);
	driveProfiles[14].f = _preferences->GetDouble("DriveProfile14F", 0);

	driveProfiles[15].p = _preferences->GetDouble("DriveProfile15P", 0);
	driveProfiles[15].i = _preferences->GetDouble("DriveProfile15I", 0);
	driveProfiles[15].d = _preferences->GetDouble("DriveProfile15D", 0);
	driveProfiles[15].f = _preferences->GetDouble("DriveProfile15F", 0);

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
		return driveProfiles[0 + itemCounts.totalItems];
	} else {
		return driveProfiles[8 + itemCounts.totalItems];
	}
}

PIDProfile Constants::getUpperLiftProfile() {
	return upperLiftProfiles[itemCounts.upperClawItems];
}

PIDProfile Constants::getLowerLiftProfile() {
	return lowerLiftProfiles[itemCounts.lowerClawItems];
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













