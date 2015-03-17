/*
 * AutoScriptRunner.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "AutoScriptRunner.h"
#include "../Commands/Drivetrain/ShiftHigh.h"
#include "../Commands/Drivetrain/ShiftLow.h"


AutoScriptRunner::AutoScriptRunner() {
	_constants = RobotMap::constants;
	_selectedFile = "";
	_group = new CommandGroup();
}

AutoScriptRunner::~AutoScriptRunner() {
	// TODO Auto-generated destructor stub
}

vector<string> AutoScriptRunner::splitString(string &str, string regexStr) {
	vector<string> args;
	regex rgx(regexStr);
	sregex_token_iterator iter(str.begin(), str.end(), rgx, -1);
	sregex_token_iterator end;
	while (iter != end) {
		args.push_back(*iter);
		iter++;
	}
	return args;
}

void AutoScriptRunner::executeFile(string filename) {
	_selectedFile = _constants->autonomousConstants.autoScriptsDirectory + "/" + filename;
	cout << _selectedFile << endl;

	ifstream stream(_selectedFile.c_str());
	string line;
	if (!stream) {
		cout << "ERR BAD FILE" << endl;
	}

	CommandGroup *group = new CommandGroup();

	while (getline(stream, line)) {
		cout << "GOT: ";
		vector<string> args = splitString(line);
		if (args[0] == "S") {
			cout << "SEQUENTIAL ";
			if (args[1] == "SHIFTHIGH") {
				cout << "SHIFTHIGH" << endl;
				group->AddSequential(new ShiftHigh());
			} else if (args[1] == "SHIFTLOW") {
				cout << "SHIFTLOW" << endl;
				group->AddSequential(new ShiftLow());
			}
		} else {
			cout << "PARALLEL ";
			if (args[1] == "SHIFTHIGH") {
				cout << "SHIFTHIGH" << endl;
				group->AddParallel(new ShiftHigh());
			} else if (args[1] == "SHIFTLOW") {
				cout << "SHIFTLOW" << endl;
				group->AddParallel(new ShiftLow());
			}
		}
	}
	_group = group;
	_group->Start();
}

void AutoScriptRunner::stop() {
	_group->Cancel();
}
