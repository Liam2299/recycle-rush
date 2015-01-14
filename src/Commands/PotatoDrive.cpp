#include "PotatoDrive.h"
#include "../RobotMap.h"
#include "../CommandBase.h"


PotatoDrive::PotatoDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(chassis);
}

// Called just before this Command runs the first time
void PotatoDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PotatoDrive::Execute()
{
	double x = oi->getJoyDrvX();
	double y = oi->getJoyDrvY();
	double z = oi->getJoyDrvZ();
	double throttle = oi->getJoyDrvThrottle();

	chassis->Drive(x, y, z, throttle, STRAFE_MOTOR_RATIO);
}

// Make this return true when this Command no longer needs to run execute()
bool PotatoDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PotatoDrive::End()
{
	chassis->Drive(0, 0, 0, 0, STRAFE_MOTOR_RATIO);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PotatoDrive::Interrupted()
{

}
