#include "subsystems/HatchManipulator.h"

HatchManipulator::HatchManipulator() : frc::Subsystem("HatchManipulator") {}

void HatchManipulator::setSpeed(double speed){
    m_talonhatch.Set(speed);
}

int HatchManipulator::hatchPosition(){
    return m_talonhatch.GetSelectedSensorPosition();
}