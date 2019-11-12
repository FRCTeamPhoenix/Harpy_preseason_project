
#include "subsystems/BallManipulator.h"
#include "PCMHandler.h"

BallManipulator::BallManipulator() : frc::Subsystem("BallManipulator") {}

void BallManipulator::setSpeedArm(const double& speedArm) {

	m_talonTip.Set(speedArm);

}

void BallManipulator::setSpeedIntake(const double& speedIntake) {

	m_intakeLeft.Set(speedIntake);
	m_intakeRight.Set(speedIntake);

}

void BallManipulator::openManipulator() {

	PCMHandler::getInstance()->openManipulator();

}

void BallManipulator::closeManipulator() {

	PCMHandler::getInstance()->closeManipulator();

}

