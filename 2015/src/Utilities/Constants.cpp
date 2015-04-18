/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"
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

	clawPorts.upperGrabberModule = _preferences->GetInt("UpperGrabberModule, 0");
	clawPorts.upperGrabberPort = _preferences->GetInt("UpperGrabberPort", 1);
	clawPorts.lowerGrabberLeftModule = _preferences->GetInt("LowerGrabberLeftModule", 0);
	clawPorts.lowerGrabberLeftPort = _preferences->GetInt("LowerGrabberLeftPort", 4);
	clawPorts.lowerGrabberRightModule = _preferences->GetInt("LowerGrabberRightModule", 0);
	clawPorts.lowerGrabberRightPort = _preferences->GetInt("LowerGrabberRightPort", 3);

	liftPorts.talonLeftPort = _preferences->GetInt("LiftTalonLeftPort", 1);
	liftPorts.talonRightPort = _preferences->GetInt("LiftTalonRightPort", 2);
	liftPorts.encoderPortA = _preferences->GetInt("LiftEncoderLeftPortA", 4);
	liftPorts.encoderPortB = _preferences->GetInt("LiftEncoderLeftPortB", 5);

	compressorPorts.compressorModule = _preferences->GetInt("CompressorModule", 0);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);

	driverButtons.shiftButton = _preferences->GetInt("ShiftButton", 6);
	driverButtons.slowButton = _preferences->GetInt("SlowButton", 5);
	driverButtons.toggleEnhancedDriveButton = _preferences->GetInt("ToggleEnhancedDriveButton", 8);
	driverButtons.incrementItemCountButton = _preferences->GetInt("IncrementItemCountButton", 10);
	driverButtons.decrementItemCountButton = _preferences->GetInt("DecrementItemCountButton", 1);
	driverButtons.resetItemCountButton = _preferences->GetInt("ResetItemCountButton", 9);
	driverButtons.compressorOnButton = _preferences->GetInt("CompressorOnButton", 3);
	driverButtons.compressorOffButton = _preferences->GetInt("CompressorOffButton", 4);

	operatorButtons.lowerClawToggleGrabButton = _preferences->GetInt("LowerClawToggleGrabButton", 5);
	operatorButtons.lowerClawToggleGrabLeftButton = _preferences->GetInt("LowerClawToggleGrabLeftButton", 7);
	operatorButtons.lowerClawToggleGrabRightButton = _preferences->GetInt("LowerClawToggleGrabRightButton", 8);
	operatorButtons.upperClawToggleGrabButton = _preferences->GetInt("UpperClawToggleGrabButton", 6);
	operatorButtons.toggleLiftAutomaticButton = _preferences->GetInt("ToggleLiftAutomaticButton", 11);

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
	driveConstants.shiftTime = _preferences->GetDouble("ShiftTime", 0.1);

	liftConstants.distancePerPulse = _preferences->GetDouble("LiftDistancePerPulse", 0);

	//hardcode levels here
	liftConstants.liftLevels.push_back(tuple<double, int, string>(0,0,"Lvl 0"));
	liftConstants.liftLevels.push_back(tuple<double, int, string>(10,1,"Lvl 1"));
	liftConstants.liftLevels.push_back(tuple<double, int, string>(20,2,"Lvl 2"));
	liftConstants.liftLevels.push_back(tuple<double, int, string>(30,3,"Lvl 3"));

	itemCounts.items = 0;
	itemCounts.maxItems = _preferences->GetInt("MaxItems", 7);

	updatePIDProfiles();

	SmartDashboard::PutString("Compressor", "ON");

	SmartDashboard::PutNumber("Items", itemCounts.items);

	SmartDashboard::PutNumber("Voltage", 0);
	SmartDashboard::PutNumber("Current", 0);
	SmartDashboard::PutNumber("Power", 0);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

void Constants::updatePIDProfiles() {
	lowGearDriveProfiles[0].p = _preferences->GetDouble("LowGearDriveProfile0P", 0);
	lowGearDriveProfiles[0].i = _preferences->GetDouble("LowGearDriveProfile0I", 0.003);
	lowGearDriveProfiles[0].d = _preferences->GetDouble("LowGearDriveProfile0D", 0);
	lowGearDriveProfiles[0].f = _preferences->GetDouble("LowGearDriveProfile0F", 0.012);

	lowGearDriveProfiles[1].p = _preferences->GetDouble("LowGearDriveProfile1P", 0);
	lowGearDriveProfiles[1].i = _preferences->GetDouble("LowGearDriveProfile1I", 0.003);
	lowGearDriveProfiles[1].d = _preferences->GetDouble("LowGearDriveProfile1D", 0);
	lowGearDriveProfiles[1].f = _preferences->GetDouble("LowGearDriveProfile1F", 0.012);

	lowGearDriveProfiles[2].p = _preferences->GetDouble("LowGearDriveProfile2P", 0);
	lowGearDriveProfiles[2].i = _preferences->GetDouble("LowGearDriveProfile2I", 0.003);
	lowGearDriveProfiles[2].d = _preferences->GetDouble("LowGearDriveProfile2D", 0);
	lowGearDriveProfiles[2].f = _preferences->GetDouble("LowGearDriveProfile2F", 0.012);

	lowGearDriveProfiles[3].p = _preferences->GetDouble("LowGearDriveProfile3P", 0);
	lowGearDriveProfiles[3].i = _preferences->GetDouble("LowGearDriveProfile3I", 0.003);
	lowGearDriveProfiles[3].d = _preferences->GetDouble("LowGearDriveProfile3D", 0);
	lowGearDriveProfiles[3].f = _preferences->GetDouble("LowGearDriveProfile3F", 0.012);

	lowGearDriveProfiles[4].p = _preferences->GetDouble("LowGearDriveProfile4P", 0);
	lowGearDriveProfiles[4].i = _preferences->GetDouble("LowGearDriveProfile4I", 0.003);
	lowGearDriveProfiles[4].d = _preferences->GetDouble("LowGearDriveProfile4D", 0);
	lowGearDriveProfiles[4].f = _preferences->GetDouble("LowGearDriveProfile4F", 0.012);

	lowGearDriveProfiles[5].p = _preferences->GetDouble("LowGearDriveProfile5P", 0);
	lowGearDriveProfiles[5].i = _preferences->GetDouble("LowGearDriveProfile5I", 0.003);
	lowGearDriveProfiles[5].d = _preferences->GetDouble("LowGearDriveProfile5D", 0);
	lowGearDriveProfiles[5].f = _preferences->GetDouble("LowGearDriveProfile5F", 0.012);

	lowGearDriveProfiles[6].p = _preferences->GetDouble("LowGearDriveProfile6P", 0);
	lowGearDriveProfiles[6].i = _preferences->GetDouble("LowGearDriveProfile6I", 0.003);
	lowGearDriveProfiles[6].d = _preferences->GetDouble("LowGearDriveProfile6D", 0);
	lowGearDriveProfiles[6].f = _preferences->GetDouble("LowGearDriveProfile6F", 0.012);

	lowGearDriveProfiles[7].p = _preferences->GetDouble("LowGearDriveProfile7P", 0);
	lowGearDriveProfiles[7].i = _preferences->GetDouble("LowGearDriveProfile7I", 0.003);
	lowGearDriveProfiles[7].d = _preferences->GetDouble("LowGearDriveProfile7D", 0);
	lowGearDriveProfiles[7].f = _preferences->GetDouble("LowGearDriveProfile7F", 0.012);

	highGearDriveProfiles[0].p = _preferences->GetDouble("HighGearDriveProfile0P", 0);
	highGearDriveProfiles[0].i = _preferences->GetDouble("HighGearDriveProfile0I", 0.003);
	highGearDriveProfiles[0].d = _preferences->GetDouble("HighGearDriveProfile0D", 0);
	highGearDriveProfiles[0].f = _preferences->GetDouble("HighGearDriveProfile0F", 0.005);

	highGearDriveProfiles[1].p = _preferences->GetDouble("HighGearDriveProfile1P", 0);
	highGearDriveProfiles[1].i = _preferences->GetDouble("HighGearDriveProfile1I", 0.003);
	highGearDriveProfiles[1].d = _preferences->GetDouble("HighGearDriveProfile1D", 0);
	highGearDriveProfiles[1].f = _preferences->GetDouble("HighGearDriveProfile1F", 0.005);

	highGearDriveProfiles[2].p = _preferences->GetDouble("HighGearDriveProfile2P", 0);
	highGearDriveProfiles[2].i = _preferences->GetDouble("HighGearDriveProfile2I", 0.003);
	highGearDriveProfiles[2].d = _preferences->GetDouble("HighGearDriveProfile2D", 0);
	highGearDriveProfiles[2].f = _preferences->GetDouble("HighGearDriveProfile2F", 0.005);

	highGearDriveProfiles[3].p = _preferences->GetDouble("HighGearDriveProfile3P", 0);
	highGearDriveProfiles[3].i = _preferences->GetDouble("HighGearDriveProfile3I", 0.003);
	highGearDriveProfiles[3].d = _preferences->GetDouble("HighGearDriveProfile3D", 0);
	highGearDriveProfiles[3].f = _preferences->GetDouble("HighGearDriveProfile3F", 0.005);

	highGearDriveProfiles[4].p = _preferences->GetDouble("HighGearDriveProfile4P", 0);
	highGearDriveProfiles[4].i = _preferences->GetDouble("HighGearDriveProfile4I", 0.003);
	highGearDriveProfiles[4].d = _preferences->GetDouble("HighGearDriveProfile4D", 0);
	highGearDriveProfiles[4].f = _preferences->GetDouble("HighGearDriveProfile4F", 0.005);

	highGearDriveProfiles[5].p = _preferences->GetDouble("HighGearDriveProfile5P", 0);
	highGearDriveProfiles[5].i = _preferences->GetDouble("HighGearDriveProfile5I", 0.003);
	highGearDriveProfiles[5].d = _preferences->GetDouble("HighGearDriveProfile5D", 0);
	highGearDriveProfiles[5].f = _preferences->GetDouble("HighGearDriveProfile5F", 0.005);

	highGearDriveProfiles[6].p = _preferences->GetDouble("HighGearDriveProfile6P", 0);
	highGearDriveProfiles[6].i = _preferences->GetDouble("HighGearDriveProfile6I", 0.003);
	highGearDriveProfiles[6].d = _preferences->GetDouble("HighGearDriveProfile6D", 0);
	highGearDriveProfiles[6].f = _preferences->GetDouble("HighGearDriveProfile6F", 0.005);

	highGearDriveProfiles[7].p = _preferences->GetDouble("HighGearDriveProfile7P", 0);
	highGearDriveProfiles[7].i = _preferences->GetDouble("HighGearDriveProfile7I", 0.003);
	highGearDriveProfiles[7].d = _preferences->GetDouble("HighGearDriveProfile7D", 0);
	highGearDriveProfiles[7].f = _preferences->GetDouble("HighGearDriveProfile7F", 0.005);

	liftProfiles[0].p = _preferences->GetDouble("LiftProfiles0P", 0);
	liftProfiles[0].i = _preferences->GetDouble("LiftProfiles0I", 0);
	liftProfiles[0].d = _preferences->GetDouble("LiftProfiles0D", 0);
	liftProfiles[0].f = _preferences->GetDouble("LiftProfiles0F", 0);

	liftProfiles[1].p = _preferences->GetDouble("LiftProfiles1P", 1);
	liftProfiles[1].i = _preferences->GetDouble("LiftProfiles1I", 1);
	liftProfiles[1].d = _preferences->GetDouble("LiftProfiles1D", 1);
	liftProfiles[1].f = _preferences->GetDouble("LiftProfiles1F", 1);

	liftProfiles[2].p = _preferences->GetDouble("LiftProfiles2P", 2);
	liftProfiles[2].i = _preferences->GetDouble("LiftProfiles2I", 2);
	liftProfiles[2].d = _preferences->GetDouble("LiftProfiles2D", 2);
	liftProfiles[2].f = _preferences->GetDouble("LiftProfiles2F", 2);

	liftProfiles[3].p = _preferences->GetDouble("LiftProfiles3P", 3);
	liftProfiles[3].i = _preferences->GetDouble("LiftProfiles3I", 3);
	liftProfiles[3].d = _preferences->GetDouble("LiftProfiles3D", 3);
	liftProfiles[3].f = _preferences->GetDouble("LiftProfiles3F", 3);

	liftProfiles[4].p = _preferences->GetDouble("LiftProfiles4P", 4);
	liftProfiles[4].i = _preferences->GetDouble("LiftProfiles4I", 4);
	liftProfiles[4].d = _preferences->GetDouble("LiftProfiles4D", 4);
	liftProfiles[4].f = _preferences->GetDouble("LiftProfiles4F", 4);

	liftProfiles[5].p = _preferences->GetDouble("LiftProfiles5P", 5);
	liftProfiles[5].i = _preferences->GetDouble("LiftProfiles5I", 5);
	liftProfiles[5].d = _preferences->GetDouble("LiftProfiles5D", 5);
	liftProfiles[5].f = _preferences->GetDouble("LiftProfiles5F", 5);

	liftProfiles[6].p = _preferences->GetDouble("LiftProfiles6P", 6);
	liftProfiles[6].i = _preferences->GetDouble("LiftProfiles6I", 6);
	liftProfiles[6].d = _preferences->GetDouble("LiftProfiles6D", 6);
	liftProfiles[6].f = _preferences->GetDouble("LiftProfiles6F", 6);

	liftProfiles[7].p = _preferences->GetDouble("LiftProfiles7P", 7);
	liftProfiles[7].i = _preferences->GetDouble("LiftProfiles7I", 7);
	liftProfiles[7].d = _preferences->GetDouble("LiftProfiles7D", 7);
	liftProfiles[7].f = _preferences->GetDouble("LiftProfiles7F", 7);
}


PIDProfile Constants::getDriveProfile(bool shifterState) {
	if (shifterState == shifterStates.highGear) {
		return highGearDriveProfiles[itemCounts.items];
	} else {
		return lowGearDriveProfiles[itemCounts.items];
	}
}

PIDProfile Constants::getLiftProfile(int lowerClawPosition,
									 bool lowerClawClosed) {
	if (!lowerClawClosed) {
		return liftProfiles[0];
	} else {
		return liftProfiles[itemCounts.items - lowerClawPosition];
	}
}
void Constants::incrementTotalItems() {
	if (itemCounts.items < itemCounts.maxItems) {
		itemCounts.items++;
		driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.items];
		driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.items];
	}
	SmartDashboard::PutNumber("Items", itemCounts.items);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

void Constants::decrementTotalItems() {
	if (itemCounts.items > 0) {
		itemCounts.items--;
		driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.items];
		driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.items];
	}
	SmartDashboard::PutNumber("Total Items", itemCounts.items);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}

void Constants::resetTotalItems() {
	itemCounts.items = 0;
	driveConstants.currentEnhancedMaxVelocityHigh = driveConstants.enhancedMaxVelocityHigh[itemCounts.items];
	driveConstants.currentEnhancedMaxVelocityLow = driveConstants.enhancedMaxVelocityLow[itemCounts.items];
	SmartDashboard::PutNumber("Items", itemCounts.items);

	if (debug) {
		SmartDashboard::PutNumber("Max Velocity High", driveConstants.currentEnhancedMaxVelocityHigh);
		SmartDashboard::PutNumber("Max Velocity Low", driveConstants.currentEnhancedMaxVelocityLow);
	}
}











