#include "subsystems/HatchManipulator.h"

HatchManipulator::HatchManipulator() : frc::Subsystem("HatchManipulator") {}

void HatchManipulator::setSpeed(double speed){
    m_talonhatch.Set(speed);
}

