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
	//register commands
}

AutonomousController::~AutonomousController() {
	// TODO Auto-generated destructor stub
}

void AutonomousController::Run() {
	_runner->executeFile(_selector->getSelectedFileName());
}

