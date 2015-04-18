#ifndef LIFT_H
#define LIFT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"
#include <vector>
#include <tuple>

using namespace std;

class Lift: public Subsystem {
private:
	Constants *_constants;

	Talon *_leftTalon;
	Talon *_rightTalon;

	Encoder *_encoder;

	PIDController *_leftController;
	PIDController *_rightController;

	PIDProfile _profile;

	vector<tuple<double, int, string>> _levels;

	unsigned int _level;

	bool _automatic;

public:
	Lift();
	void InitDefaultCommand();

	void enableAutomatic();
	void disableAutomatic();
	bool automaticEnabled();

	void upOneLevel();
	void downOneLevel();
	void resetLevel();
	int getLevel();

	int getPossessionLevel();

	void setRaw(double value);

	double getHeight();

	double getAverageRaw();
	double getLeftRaw();
	double getRightRaw();

	void updatePIDCoefficients(bool lowerClawClosed);
	PIDProfile getPIDCoefficients();
};

#endif
