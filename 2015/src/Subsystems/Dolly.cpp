#include "Dolly.h"
#include "../RobotMap.h"

Dolly::Dolly() : Subsystem("Dolly") {
	_constants = RobotMap::constants;
	_cylinder = RobotMap::dollyCylinder;
}
    
void Dolly::InitDefaultCommand() {

}

void Dolly::setDolly(bool back) {
	if (back) {
		_cylinder->Set(_constants->dollyStates.back);
	} else {
		_cylinder->Set(_constants->dollyStates.forward);
	}
	_constants->reducePressure(_constants->pneumaticConstants.dollyActuationLoss);
}

bool Dolly::dollyBack() {
	if (_cylinder->Get() == _constants->dollyStates.back) {
		return true;
	} else {
		return false;
	}
}
