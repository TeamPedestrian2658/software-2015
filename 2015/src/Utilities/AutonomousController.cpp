/*
 * AutonomousController.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: rahulsalvi
 */

#include "AutonomousController.h"

AutonomousController::AutonomousController(string directory) {
	_selector = new AutoScriptSelector(directory);
	_runner = new AutoScriptRunner();
}

AutonomousController::~AutonomousController() {
	// TODO Auto-generated destructor stub
}

void AutonomousController::Run() {

}

