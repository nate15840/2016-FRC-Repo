#include "WPILib.h"

/*
 * Nate Thorn
 * C
 * 23 JAN 2016
 */

class Robot: public IterativeRobot
{
public:
	//initialize channels
	const static int rightChannel			=	0;
	const static int leftChannel			=	1;
	const static int compressor				=	0;
	const static int rightStickChannel		=	0;
	const static int leftStickChannel		=	1;
	const static int sol0					=	0;
	const static int sol1					=	1;
	const static int canChannel0			=	0;
	const static int canChannel5			=	5;

	Victor rightVictor, leftVictor;
	Compressor comp;
	Joystick rightStick, leftStick;
	DoubleSolenoid dsol;
	RobotDrive tank;
	CANTalon talon0, talon5;

	const int SHIFT_BUTTON					=	1;

	Robot():
		rightVictor(rightChannel),
		leftVictor(leftChannel),
		comp(compressor),
		rightStick(rightStickChannel),
		leftStick(leftStickChannel),
		dsol(sol0, sol1),
		tank(leftVictor, rightVictor),
		talon0(canChannel0),
		talon5(canChannel5)
	{
		talon0.SetControlMode(CANSpeedController::kSpeed);

		talon5.SetControlMode(CANSpeedController::kFollower);
		talon5.Set(talon0);
	}
/*
	void RobotInit()
	{

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}
*/

	void TeleopInit()
	{
		tank.SetSafetyEnabled(false);
	}

	void TeleopPeriodic()
	{
		talon0.Set(rightStick.(getX));

		tank.TankDrive(leftStick, rightStick);
		if ((rightStick.GetRawButton(SHIFT_BUTTON) == true) or (leftStick.GetRawButton(SHIFT_BUTTON) == true))
		{
			dsol.Set(DoubleSolenoid::kForward);
		}
		else
		{
			dsol.Set(DoubleSolenoid::kReverse);
		}
	}
};

START_ROBOT_CLASS(Robot)
