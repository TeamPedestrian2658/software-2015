#ifndef DriveTrapezoidal_H
#define DriveTrapezoidal_H

#include "../../Robot.h"
#include "WPILib.h"

class DriveTrapezoidal: public Command
{
private:
	Drivetrain *_drivetrain;
	Timer *_timer;

	bool _isComplete;

	double _enhancedMaxVelocityLow;
	double _enhancedMaxVelocityHigh;

	double _totalTime;
	double _leftDistance;
	double _rightDistance;
	double _leftFinalVelocity;
	double _rightFinalVelocity;

	double _leftInitialVelocity;
	double _rightInitialVelocity;

	double _leftMiddleVelocity;
	double _rightMiddleVelocity;

	double _leftAcceleration1;
	double _rightAcceleration1;

	double _leftAcceleration2;
	double _rightAcceleration2;

	void adjustFinalVelocities();
	void adjustTotalTime();
public:
	DriveTrapezoidal(double totalTime,
					 double leftDistance,
					 double rightDistance,
					 double leftFinalVelocity,
					 double rightFinalVelocity);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
