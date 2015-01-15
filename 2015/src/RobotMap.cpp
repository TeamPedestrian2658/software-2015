#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

SendableChooser *RobotMap::autoChooser = NULL;

Talon *RobotMap::driveLeft = NULL;
Talon *RobotMap::driveRight = NULL;

Solenoid *RobotMap::shifterLeft = NULL;
Solenoid *RobotMap::shifterRight = NULL;

void RobotMap::init() {

	autoChooser = new SendableChooser();

	driveLeft = new Talon(0);
	driveRight = new Talon(1);

	shifterLeft = new Solenoid(0, 0);
	shifterRight = new Solenoid(0, 1);

	LiveWindow* lw = LiveWindow::GetInstance();

}
