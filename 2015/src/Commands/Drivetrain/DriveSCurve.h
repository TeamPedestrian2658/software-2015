#ifndef DriveSCurve_H
#define DriveSCurve_H

#include "../../Robot.h"
#include "WPILib.h"

class DriveSCurve: public Command
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

	double _leftMiddleAcceleration1;
	double _rightMiddleAcceleration1;

	double _leftMiddleAcceleration2;
	double _rightMiddleAcceleration2;

	double _leftH;
	double _rightH;

	double _leftI;
	double _rightI;

	double _leftJ;
	double _rightJ;

	double _leftK;
	double _rightK;

	void adjustFinalVelocities();
	void adjustTotalTime();

public:
	DriveSCurve(double totalTime,
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
