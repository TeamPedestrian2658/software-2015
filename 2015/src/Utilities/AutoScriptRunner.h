/*
 * AutoScriptRunner.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#ifndef SRC_UTILITIES_AUTOSCRIPTRUNNER_H_
#define SRC_UTILITIES_AUTOSCRIPTRUNNER_H_

#include <string>
#include <fstream>
#include <regex>
#include "WPILib.h"
#include "Constants.h"
#include "../RobotMap.h"

using namespace std;

class AutoScriptRunner {
private:
	Constants *_constants;
	string _selectedFile;
	CommandGroup *_group;

	vector<string> splitString(string &str, string regexStr = "\\s+");
public:
	AutoScriptRunner();
	virtual ~AutoScriptRunner();

	void executeFile(string filename);
	void stop();
};

#endif /* SRC_UTILITIES_AUTOSCRIPTRUNNER_H_ */
