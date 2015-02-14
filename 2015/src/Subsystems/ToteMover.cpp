#include "ToteMover.h"
#include "../RobotMap.h"
#include "../Commands/ToteMover/ToteMoverManager.h"

ToteMover::ToteMover() : Subsystem("ToteMover") {
	_constants = RobotMap::constants;
	_mover = RobotMap::toteMoverTalon;

	SmartDashboard::PutString("Tote Mover", "STOPPED");
}

void ToteMover::InitDefaultCommand()
{
	SetDefaultCommand(new ToteMoverManager());
}

void ToteMover::moveTotesLeft() {
	_mover->Set(_constants->toteMoverStates.moveTotesLeft);
	SmartDashboard::PutString("Tote Mover", "LEFT");
}

void ToteMover::moveTotesRight() {
	_mover->Set(_constants->toteMoverStates.moveTotesRight);
	SmartDashboard::PutString("Tote Mover", "RIGHT");
}

void ToteMover::stop() {
	_mover->Set(_constants->toteMoverStates.stop);
	SmartDashboard::PutString("Tote Mover", "STOPPED");
}
