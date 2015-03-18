/*
 * AutonomousController.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: rahulsalvi
 */

#include "AutonomousController.h"

AutonomousController::AutonomousController() {
	_constants = RobotMap::constants;
	_selector = new AutoScriptSelector(_constants->autonomousConstants.autoScriptsDirectory);
	_runner = new AutoScriptRunner();
}

AutonomousController::~AutonomousController() {
	// TODO Auto-generated destructor stub
}

void AutonomousController::run() {
	_runner->executeFile(_selector->getSelectedFileName());
}

void AutonomousController::stop() {
	_runner->stop();
}
