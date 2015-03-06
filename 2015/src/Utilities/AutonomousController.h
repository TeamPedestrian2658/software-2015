/*
 * AutonomousController.h
 *
 *  Created on: Mar 5, 2015
 *      Author: rahulsalvi
 */

#ifndef SRC_UTILITIES_AUTONOMOUSCONTROLLER_H_
#define SRC_UTILITIES_AUTONOMOUSCONTROLLER_H_

#include "WPILib.h"
#include "string"
#include "AutoScriptSelector.cpp"
#include "AutoScriptRunner.cpp"
#include "Constants.h"
#include "RobotMap.h"

class AutonomousController {
private:
	Constants *_constants;
	AutoScriptSelector *_selector;
	AutoScriptRunner *_runner;
public:
	AutonomousController();
	virtual ~AutonomousController();

	void Run();
};

#endif /* SRC_UTILITIES_AUTONOMOUSCONTROLLER_H_ */
