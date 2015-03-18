/*
 * AutoScriptRunner.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "AutoScriptRunner.h"

#include "../Commands/Drivetrain/ShiftHigh.h"
#include "../Commands/Drivetrain/ShiftLow.h"
#include "../Commands/Drivetrain/DriveSCurve.h"
#include "../Commands/Drivetrain/DriveTrapezoidal.h"
#include "../Commands/Lift/UpperUpOneLevel.h"
#include "../Commands/Lift/UpperDownOneLevel.h"
#include "../Commands/Lift/LowerUpOneLevel.h"
#include "../Commands/Lift/LowerDownOneLevel.h"
#include "../Commands/LowerClaw/LowerClawGrab.h"
#include "../Commands/LowerClaw/LowerClawRelease.h"
#include "../Commands/LowerClaw/LowerClawGrabRight.h"
#include "../Commands/LowerClaw/LowerClawReleaseRight.h"
#include "../Commands/LowerClaw/LowerClawGrabLeft.h"
#include "../Commands/LowerClaw/LowerClawReleaseLeft.h"
#include "../Commands/UpperClaw/UpperClawGrab.h"
#include "../Commands/UpperClaw/UpperClawRelease.h"
#include "../Commands/UpperClaw/UpperClawGrabRight.h"
#include "../Commands/UpperClaw/UpperClawReleaseRight.h"
#include "../Commands/UpperClaw/UpperClawGrabLeft.h"
#include "../Commands/UpperClaw/UpperClawReleaseLeft.h"
#include "../Commands/Utilities/CompressorOn.h"
#include "../Commands/Utilities/CompressorOff.h"
#include "../Commands/Utilities/IncrementTotalCount.h"
#include "../Commands/Utilities/DecrementTotalCount.h"
#include "../Commands/Utilities/ResetTotalCount.h"

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
	cout << "EXECUTING:" << _selectedFile << endl;

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
		} else {
			if (args[0] == "S") {
				cout << "SEQUENTIAL ";
				if (args[1] == "SHIFTHIGH") {
					cout << args[1] << endl;
					group->AddSequential(new ShiftHigh());
				} else if (args[1] == "SHIFTLOW") {
					cout << args[1] << endl;
					group->AddSequential(new ShiftLow());
				} else if (args[1] == "DRIVESCURVE") {
					cout << args[1] << " ";
					if (args.size() < 7) {
						cout << "NOT ENOUGH ARGUMENTS" << endl;
					} else {
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
				} else if (args[1] == "DRIVETRAPEZOIDAL") {
					cout << args[1] << " ";
					if (args.size() < 7) {
						cout << "NOT ENOUGH ARGUMENTS" << endl;
					} else {
						for (unsigned int i = 2;i < args.size();i++) {
							cout << args[i] << " ";
						}
						cout << endl;
						group->AddSequential(new DriveTrapezoidal(stod(args[2]),
															 	  stod(args[3]),
																  stod(args[4]),
																  stod(args[5]),
																  stod(args[6])));
					}
				} else if (args[1] == "UPPERUPLEVEL") {
					cout << args[1] << endl;
					group->AddSequential(new UpperUpOneLevel());
				} else if (args[1] == "UPPERDOWNLEVEL") {
					cout << args[1] << endl;
					group->AddSequential(new UpperDownOneLevel());
				} else if (args[1] == "LOWERUPLEVEL") {
					cout << args[1] << endl;
					group->AddSequential(new LowerUpOneLevel());
				} else if (args[1] == "LOWERDOWNLEVEL") {
					cout << args[1] << endl;
					group->AddSequential(new LowerDownOneLevel());
				} else if (args[1] == "LOWEROPEN") {
					cout << args[1] << endl;
					group->AddSequential(new LowerClawRelease());
				} else if (args[1] == "LOWERCLOSE") {
					cout << args[1] << endl;
					group->AddSequential(new LowerClawGrab());
				} else if (args[1] == "LOWERRIGHTOPEN") {
					cout << args[1] << endl;
					group->AddSequential(new LowerClawReleaseRight());
				} else if (args[1] == "LOWERRIGHTCLOSE") {
					cout << args[1] << endl;
					group->AddSequential(new LowerClawGrabRight());
				} else if (args[1] == "LOWERLEFTOPEN") {
					cout << args[1] << endl;
					group->AddSequential(new LowerClawReleaseLeft());
				} else if (args[1] == "LOWERLEFTCLOSE") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawGrabLeft());
				} else if (args[1] == "UPPEROPEN") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawRelease());
				} else if (args[1] == "UPPERCLOSE") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawGrab());
				} else if (args[1] == "UPPERRIGHTOPEN") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawReleaseRight());
				} else if (args[1] == "UPPERRIGHTCLOSE") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawGrabRight());
				} else if (args[1] == "UPPERLEFTOPEN") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawReleaseLeft());
				} else if (args[1] == "UPPERLEFTCLOSE") {
					cout << args[1] << endl;
					group->AddSequential(new UpperClawGrabLeft());
				} else if (args[1] == "COMPRESSORON") {
					cout << args[1] << endl;
					group->AddSequential(new CompressorOn());
				} else if (args[1] == "COMPRESSOROFF") {
					cout << args[1] << endl;
					group->AddSequential(new CompressorOff());
				} else if (args[1] == "INCREMENTCOUNT") {
					cout << args[1] << endl;
					group->AddSequential(new IncrementTotalCount());
				} else if (args[1] == "DECREMENTCOUNT") {
					cout << args[1] << endl;
					group->AddSequential(new DecrementTotalCount());
				} else if (args[1] == "RESETCOUNT") {
					cout << args[1] << endl;
					group->AddSequential(new ResetTotalCount());
				} else {
					cout << "UNKNOWN COMMAND" << endl;
				}
			} else if (args[0] == "P") {
				cout << "PARALLEL ";
				if (args[1] == "SHIFTHIGH") {
					cout << "SHIFTHIGH" << endl;
					group->AddParallel(new ShiftHigh());
				} else if (args[1] == "SHIFTLOW") {
					cout << "SHIFTLOW" << endl;
					group->AddParallel(new ShiftLow());
				} else if (args[1] == "DRIVESCURVE") {
					cout << "DRIVESCURVE ";
					if (args.size() < 7) {
						cout << "NOT ENOUGH ARGUMENTS" << endl;
					} else {
						for (unsigned int i = 2;i < args.size();i++) {
							cout << args[i] << " ";
						}
						cout << endl;
						group->AddParallel(new DriveSCurve(stod(args[2]),
														   stod(args[3]),
														   stod(args[4]),
														   stod(args[5]),
														   stod(args[6])));
					}
				} else if (args[1] == "DRIVETRAPEZOIDAL") {
					cout << args[1] << " ";
					if (args.size() < 7) {
						cout << "NOT ENOUGH ARGUMENTS" << endl;
					} else {
						for (unsigned int i = 2;i < args.size();i++) {
							cout << args[i] << " ";
						}
						cout << endl;
						group->AddParallel(new DriveTrapezoidal(stod(args[2]),
															 	stod(args[3]),
																stod(args[4]),
																stod(args[5]),
																stod(args[6])));
					}
				} else if (args[1] == "UPPERUPLEVEL") {
					cout << args[1] << endl;
					group->AddParallel(new UpperUpOneLevel());
				} else if (args[1] == "UPPERDOWNLEVEL") {
					cout << args[1] << endl;
					group->AddParallel(new UpperDownOneLevel());
				} else if (args[1] == "LOWERUPLEVEL") {
					cout << args[1] << endl;
					group->AddParallel(new LowerUpOneLevel());
				} else if (args[1] == "LOWERDOWNLEVEL") {
					cout << args[1] << endl;
					group->AddParallel(new LowerDownOneLevel());
				} else if (args[1] == "LOWEROPEN") {
					cout << args[1] << endl;
					group->AddParallel(new LowerClawRelease());
				} else if (args[1] == "LOWERCLOSE") {
					cout << args[1] << endl;
					group->AddParallel(new LowerClawGrab());
				} else if (args[1] == "LOWERRIGHTOPEN") {
					cout << args[1] << endl;
					group->AddParallel(new LowerClawReleaseRight());
				} else if (args[1] == "LOWERRIGHTCLOSE") {
					cout << args[1] << endl;
					group->AddParallel(new LowerClawGrabRight());
				} else if (args[1] == "LOWERLEFTOPEN") {
					cout << args[1] << endl;
					group->AddParallel(new LowerClawReleaseLeft());
				} else if (args[1] == "LOWERLEFTCLOSE") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawGrabLeft());
				} else if (args[1] == "UPPEROPEN") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawRelease());
				} else if (args[1] == "UPPERCLOSE") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawGrab());
				} else if (args[1] == "UPPERRIGHTOPEN") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawReleaseRight());
				} else if (args[1] == "UPPERRIGHTCLOSE") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawGrabRight());
				} else if (args[1] == "UPPERLEFTOPEN") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawReleaseLeft());
				} else if (args[1] == "UPPERLEFTCLOSE") {
					cout << args[1] << endl;
					group->AddParallel(new UpperClawGrabLeft());
				} else if (args[1] == "COMPRESSORON") {
					cout << args[1] << endl;
					group->AddParallel(new CompressorOn());
				} else if (args[1] == "COMPRESSOROFF") {
					cout << args[1] << endl;
					group->AddParallel(new CompressorOff());
				} else if (args[1] == "INCREMENTCOUNT") {
					cout << args[1] << endl;
					group->AddParallel(new IncrementTotalCount());
				} else if (args[1] == "DECREMENTCOUNT") {
					cout << args[1] << endl;
					group->AddParallel(new DecrementTotalCount());
				} else if (args[1] == "RESETCOUNT") {
					cout << args[1] << endl;
					group->AddParallel(new ResetTotalCount());
				} else {
					cout << "UNKNOWN COMMAND" << endl;
				}
			} else {
				cout << "UNKNOWN SEQUENTIAL/PARALLEL" << endl;
			}
		}
	}
	_group = group;
	_group->Start();
}

void AutoScriptRunner::stop() {
	_group->Cancel();
}
