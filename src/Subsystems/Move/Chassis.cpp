#include "Chassis.h"
#include "../../RobotMap.h"
#include <Commands/PotatoDrive.h>

Chassis :: Chassis(): Subsystem ("Chassis"){

	drivemotorA = new Talon (DRIVE_MOTOR_A_PWM);
	drivemotorB = new Talon (DRIVE_MOTOR_B_PWM);
	drivemotorC = new Talon (DRIVE_MOTOR_C_PWM);
	drivemotorD = new Talon (DRIVE_MOTOR_D_PWM);
}

Chassis :: ~Chassis (){

	delete drivemotorA;
	delete drivemotorB;
	delete drivemotorC;
	delete drivemotorD;

}

void Chassis::Drive(double vX, double vY, double vZ, double Throttle, double k){
	double mA;
	double mB;
	double mC;
	double mD;

	mA = 0 - vY - k * vZ;
	mB = vX + 0 - vZ;
	mC = 0 + vY - k * vZ;
	mD = -vX + 0 - vZ;

	double array [] = {mA, mB, mC, mD};

	double max;

	for (int i = 0; i <= 3; i += 1)
	{
		if (abs(array[i]) > max)
		{
			    max = abs(array[i]);
		}
	}

	for (int i=0; i <= 3; i+= 1)
	{
		array[i] = array[i]/max;
	}

	for (int i=0; i <= 3; i += 1)
	{
		array[i] = array[i] * Throttle;
	}

	drivemotorA->Set(array[0]);
	drivemotorB->Set(array[1]);
	drivemotorC->Set(array[2]);
	drivemotorD->Set(array[3]);
}

void Chassis :: InitDefaultCommand(){

	SetDefaultCommand(new PotatoDrive());
}
