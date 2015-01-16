/*
 * AutoScriptSelector.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "AutoScriptSelector.h"
#include "../RobotMap.h"

AutoScriptSelector::AutoScriptSelector(string directory) :
	_directory(directory)
{
	_chooser = RobotMap::autoChooser;

	discoverFiles();
	initSendableChooser();
}

AutoScriptSelector::~AutoScriptSelector() {
	delete _chooser;
}

int AutoScriptSelector::discoverFiles() {
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(_directory.c_str())) == NULL) {
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		if (string(dirp->d_name).find(".txt") != string::npos) {
			_files.push_back(string(dirp->d_name));
		}
	}
	closedir(dp);
	return 0;
}

void AutoScriptSelector::initSendableChooser() {
	_chooser->AddDefault(_files[0].substr(0, _files[0].length() - 4).c_str(), new int(0));
	for (int i = 1; i < (int)_files.size(); i++) {
		_chooser->AddObject(_files[i].substr(0, _files[i].length() - 4).c_str(), new int(i));
	}
	SmartDashboard::PutData("Autonomous Scripts", _chooser);
}

string AutoScriptSelector::getSelectedFileName() {
	return _files[*(int*)_chooser->GetSelected()];
}










