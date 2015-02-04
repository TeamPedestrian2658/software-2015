#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class Drivetrain: public Subsystem {
private:
	Constants *_constants;

	Talon *_talonLeft;
	Talon *_talonRight;

	Encoder *_encoderLeft;
	Encoder *_encoderRight;

	PIDController *_controllerLeft;
	PIDController *_controllerRight;

	Solenoid *_shifter;

	PIDProfile _profile;

	SendableChooser *_chooser;

	bool _encoderVelocityMode;
	bool _enhanceEnabled;
	bool _slowEnabled;
	bool _highGear;

public:
	Drivetrain();
	void InitDefaultCommand();

	void shiftHigh();
	void shiftLow();
	bool isHighGear();

	void set(double leftVelocity, double rightVelocity);
	void setRaw(double left, double right);

	void setEncoderMode(bool velocity);
	bool encoderVelocityMode();

	bool tankEnabled();

	void enableEnhancedDriving(bool enable);
	bool enhanceEnabled();

	void enableSlow(bool enable);
	bool slowEnabled();

	void updatePIDCoefficients();
	PIDProfile getPIDCoefficients();
};

#endif
