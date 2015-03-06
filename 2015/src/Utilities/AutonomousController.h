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

class AutonomousController {
private:
	AutoScriptSelector *_selector;
	AutoScriptRunner *_runner;
public:
	AutonomousController(string directory);
	virtual ~AutonomousController();

	void Run();
};

#endif /* SRC_UTILITIES_AUTONOMOUSCONTROLLER_H_ */
