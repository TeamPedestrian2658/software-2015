/*
 * AutoScriptSelector.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include <string>
#include <vector>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include "WPILib.h"

using namespace std;

#ifndef SRC_UTILITIES_AUTOSCRIPTSELECTOR_H_
#define SRC_UTILITIES_AUTOSCRIPTSELECTOR_H_

class AutoScriptSelector {
private:
	SendableChooser *_chooser;
	string _directory;
	vector<string> _files;

	int discoverFiles();
	void initSendableChooser();

public:
	AutoScriptSelector(string directory);
	virtual ~AutoScriptSelector();

	string getSelectedFileName();

};

#endif /* SRC_UTILITIES_AUTOSCRIPTSELECTOR_H_ */
