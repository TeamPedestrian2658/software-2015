#include "Dolly.h"
#include "../RobotMap.h"

Dolly::Dolly() : Subsystem("Dolly") {
	_constants = RobotMap::constants;
	_cylinder = RobotMap::dolleyCylinder;
}
    
void Dolly::InitDefaultCommand() {

}

void Dolly::setDolly(bool back) {
	if (back) {
		_cylinder->Set(_constants->dolleyStates.back);
	} else {
		_cylinder->Set(_constants->dolleyStates.forward);
	}
}

bool Dolly::dollyBack() {
	if (_cylinder->Get() == _constants->dolleyStates.back) {
		return true;
	} else {
		return false;
	}
}
