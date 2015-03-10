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

	Talon *_lowerLeftTalon;
	Talon *_lowerRightTalon;
	Talon *_upperTalon;

	Encoder *_lowerLeftEncoder;
	Encoder *_lowerRightEncoder;
	Encoder *_upperEncoder;

	PIDController *_lowerLeftController;
	PIDController *_lowerRightController;
	PIDController *_upperController;

	PIDProfile _lowerProfile;
	PIDProfile _upperProfile;

	vector<tuple<double, int, string>> _lowerLevels;
	vector<tuple<double, int, string>> _upperLevels;

	int _lowerLevel;
	int _upperLevel;

	bool _lowerAutomatic;
	bool _upperAutomatic;

public:
	Lift();
	void InitDefaultCommand();

	void enableLowerController();
	void disableLowerController();
	bool lowerControllerEnabled();

	void enableUpperController();
	void disableUpperController();
	bool upperControllerEnabled();

	void lowerUpOneLevel();
	void lowerDownOneLevel();
	void resetLowerLevel();
	int getLowerLevel();

	void upperUpOneLevel();
	void upperDownOneLevel();
	void resetUpperLevel();
	int getUpperLevel();

	void setLowerRaw(double value);
	void setUpperRaw(double value);

	double getLowerAverageHeight();
	double getLowerLeftHeight();
	double getLowerRightHeight();

	double getUpperHeight();

	double getLowerAverageRaw();
	double getLowerLeftRaw();
	double getLowerRightRaw();

	double getUpperRaw();

	void updatePIDCoefficients();
	PIDProfile getLowerPIDCoefficients();
	PIDProfile getUpperPIDCoefficients();
};

#endif
