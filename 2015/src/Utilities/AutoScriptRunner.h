/*
 * AutoScriptRunner.h
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#ifndef SRC_UTILITIES_AUTOSCRIPTRUNNER_H_
#define SRC_UTILITIES_AUTOSCRIPTRUNNER_H_

class AutoScriptRunner {
private:
	void parseFile();
	void createCommandGroup();
public:
	AutoScriptRunner();
	virtual ~AutoScriptRunner();

	void executeFile(string filename);
	void registerCommand(string name, int args);
};

#endif /* SRC_UTILITIES_AUTOSCRIPTRUNNER_H_ */
