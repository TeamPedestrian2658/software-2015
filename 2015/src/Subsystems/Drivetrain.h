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
	SendableChooser *_rumbleChooser;

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

	bool tankEnabled();

	bool rumbleEnabled();

	void enableEnhancedDriving();
	void disableEnhancedDriving();
	bool enhanceEnabled();

	void enableSlow();
	void disableSlow();
	bool slowEnabled();

	void updatePIDCoefficients();
	PIDProfile getPIDCoefficients();
};

#endif
