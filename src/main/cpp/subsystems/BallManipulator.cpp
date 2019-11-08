
#include "subsystems/BallManipulator.h"

BallManipulator::BallManipulator() : frc::Subsystem("BallManipulator") {}

void BallManipulator::setSpeedArm(const double& speedArm) {

	m_talonTip.Set(speedArm);

}

void BallManipulator::setSpeedIntake(const double& speedIntake) {

	m_intakeLeft.Set(speedIntake);
	m_intakeRight.Set(speedIntake);

}

