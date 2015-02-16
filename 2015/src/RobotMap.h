#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "Utilities/Constants.h"

class RobotMap {
public:
	static LiveWindow *liveWindow;

	static Constants *constants;

	static SendableChooser *autoChooser;

	static Talon *driveTalonLeft;
	static Talon *driveTalonRight;

	static Solenoid *driveShifter;

	static Encoder *driveEncoderLeft;
	static Encoder *driveEncoderRight;

	static PIDController *driveControllerLeft;
	static PIDController *driveControllerRight;

	static SendableChooser *driveChooser;
	static SendableChooser *driveRumbleChooser;

	static Solenoid *upperClawGrabber;
	static Solenoid *upperClawBrake;

	static Solenoid *lowerClawLeftGrabber;
	static Solenoid *lowerClawRightGrabber;
	static Solenoid *lowerClawBrake;

	static Talon *lowerLiftTalonLeft;
	static Talon *lowerLiftTalonRight;
	static Talon *upperLiftTalon;

	static Encoder *lowerLiftEncoderLeft;
	static Encoder *lowerLiftEncoderRight;
	static Encoder *upperLiftEncoder;

	static PIDController *liftControllerLowerLeft;
	static PIDController *liftControllerLowerRight;
	static PIDController *liftControllerUpper;

	static Compressor *compressor;

	static PowerDistributionPanel *powerDistributionPanel;

	static void init();
};
#endif
