#include "Dolly.h"
#include "../RobotMap.h"

Dolly::Dolly() : Subsystem("Dolly") {
	_constants = RobotMap::constants;
	_cylinder = RobotMap::dollyCylinder;
	SmartDashboard::PutString("Dolly", "FORWARD");
}
    
void Dolly::InitDefaultCommand() {

}

void Dolly::dollyBack() {
	if (!isDollyBack()) {
		_cylinder->Set(_constants->dollyStates.back);
		_constants->reducePressure(_constants->pneumaticConstants.dollyActuationLoss);
		SmartDashboard::PutString("Dolly", "BACK");
	}
}

void Dolly::dollyForward() {
	if (isDollyBack()) {
		_cylinder->Set(_constants->dollyStates.forward);
		_constants->reducePressure(_constants->pneumaticConstants.dollyActuationLoss);
		SmartDashboard::PutString("Dolly", "FORWARD");
	}
}

bool Dolly::isDollyBack() {
	return (_cylinder->Get() == _constants->dollyStates.back);
}
