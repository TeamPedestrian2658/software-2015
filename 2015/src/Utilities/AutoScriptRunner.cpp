/*
 * AutoScriptRunner.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "AutoScriptRunner.h"

AutoScriptRunner::AutoScriptRunner() {
	_selectedFile = "";
	_group = new CommandGroup();
}

AutoScriptRunner::~AutoScriptRunner() {
	// TODO Auto-generated destructor stub
}

void AutoScriptRunner::executeFile(string filename) {
	_selectedFile = filename;
	//create stream from file
	//parse file
	//init command group
	//run command group
}

void AutoScriptRunner::registerCommand(string name, Command *command, int args) {
	_registry[name] = tuple<command, args>;
}
