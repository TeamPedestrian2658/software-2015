#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "../../Robot.h"
#include "WPILib.h"
#include "../../Utilities/Constants.h"

class DriveWithJoystick: public Command
{
private:
	Drivetrain *_drivetrain;
	Joystick *_driverStick;
	Constants *_constants;
	double _leftVelocity;
	double _rightVelocity;
	double MAX_VELOCITY;
	double ENHANCE_SCALAR;
	double SLOW_SCALAR;
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
