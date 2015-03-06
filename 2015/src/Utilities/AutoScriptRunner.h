/*
 * AutoScriptRunner.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#ifndef SRC_UTILITIES_AUTOSCRIPTRUNNER_H_
#define SRC_UTILITIES_AUTOSCRIPTRUNNER_H_

#include <string>
#include <map>
#include <tuple>
#include "WPILib.h"

using namespace std;

class AutoScriptRunner {
private:
	string _selectedFile;
	map<string, tuple<Command, int>> _registry;
	CommandGroup *_group;
	void parseFile();
	void initCommandGroup();
public:
	AutoScriptRunner();
	virtual ~AutoScriptRunner();

	void executeFile(string filename);
	void registerCommand(string name, Command *command, int args);
};

#endif /* SRC_UTILITIES_AUTOSCRIPTRUNNER_H_ */
