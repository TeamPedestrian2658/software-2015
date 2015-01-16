#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/PIDEncoder.h"
#include "../Commands/DriveWithJoystick.h"

class Drivetrain: public Subsystem {
private:
	Talon *_talonLeft;
	Talon *_talonRight;

	PIDEncoder *_encoderLeft;
	PIDEncoder *_encoderRight;

	PIDController *_controllerLeft;
	PIDController *_controllerRight;

	Solenoid *_shifterLeft;
	Solenoid *_shifterRight;

	SendableChooser *_chooser;

	bool _enhanceEnabled;
	bool _slowEnabled;

public:
	Drivetrain();
	void InitDefaultCommand();

	void shiftHigh();
	void shiftLow();

	void set(double leftVelocity, double rightVelocity);
	void setRaw(double left, double right);

	void setEncoderMode(bool velocity);
	bool encoderMode();

	bool tankEnabled();

	void enableEnhancedDriving(bool enable);
	bool enhanceEnabled();

	void enableSlow(bool enable);
	bool slowEnabled();
};

#endif
