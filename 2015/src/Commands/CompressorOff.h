#ifndef CompressorOff_H
#define CompressorOff_H

#include "../Robot.h"
#include "WPILib.h"

class CompressorOff: public Command
{
public:
	CompressorOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
