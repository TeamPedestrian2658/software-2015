#ifndef CompressorOn_H
#define CompressorOn_H

#include "../Robot.h"
#include "WPILib.h"

class CompressorOn: public Command
{
public:
	CompressorOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
