#include "ToteMover.h"
#include "../RobotMap.h"

ToteMover::ToteMover() : Subsystem("ToteMover") {
	mover = RobotMap::toteMoverTalon;
}

void ToteMover::InitDefaultCommand()
{

}

void ToteMover::setToteMover(double value) {
	mover->Set(value);
}

double ToteMover::getToteMover() {
	return mover->Get();
}
