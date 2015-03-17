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
		cout << "ERROR BAD FILE" << endl;
	}

	CommandGroup *group = new CommandGroup();

	while (getline(stream, line)) {
		cout << "GOT: ";
		vector<string> args = splitString(line);
		if (args.size() < 2) {
			cout << "NOT ENOUGH ARGUMENTS" << endl;
		}
		if (args[0] == "S") {
			cout << "SEQUENTIAL ";
			if (args[1] == "SHIFTHIGH") {
				cout << "SHIFTHIGH" << endl;
				group->AddSequential(new ShiftHigh());
			} else if (args[1] == "SHIFTLOW") {
				cout << "SHIFTLOW" << endl;
				group->AddSequential(new ShiftLow());
			} else if (args[1] == "DRIVESCURVE") {
				if (args.size() < 7) {
					cout << "NOT ENOUGH ARGUMENTS" << endl;
				} else {
					cout << "DRIVESCURVE ";
					for (unsigned int i = 2;i < args.size();i++) {
						cout << args[i] << " ";
					}
					cout << endl;
					group->AddSequential(new DriveSCurve(stod(args[2]),
														 stod(args[3]),
														 stod(args[4]),
														 stod(args[5]),
														 stod(args[6])));
				}
			}
		} else if (args[0] == "P") {
			cout << "PARALLEL ";
			if (args[1] == "SHIFTHIGH") {
				cout << "SHIFTHIGH" << endl;
				group->AddParallel(new ShiftHigh());
			} else if (args[1] == "SHIFTLOW") {
				cout << "SHIFTLOW" << endl;
				group->AddParallel(new ShiftLow());
			}
		} else {
			cout << "UNKNOWN SEQUENTIAL/PARALLEL" << endl;
		}
	}
	_group = group;
	_group->Start();
}

void AutoScriptRunner::stop() {
	_group->Cancel();
}
