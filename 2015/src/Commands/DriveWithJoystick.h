#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "../Robot.h"
#include "WPILib.h"

const double MAX_VELOCITY = 0;
const double ENHANCE_SCALAR = 0.9;
const double SLOW_SCALAR = 0.75;

class DriveWithJoystick: public Command
{
private:
	Drivetrain *_drivetrain;
	Joystick *_driverStick;
	double _leftVelocity;
	double _rightVelocity;
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
