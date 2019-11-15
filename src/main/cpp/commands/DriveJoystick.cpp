#include "commands/DriveJoystick.h"

#include "subsystems/HatchManipulator.h" 
#include "Robot.h"

DriveJoystick::DriveJoystick(){
    Requires(HatchManipulator::getInstance());
}

void DriveJoystick::Initialize(){
    HatchManipulator::getInstance()->setSpeed(0.0);
}

void DriveJoystick::Execute(){
    int HatchPov = m_logitechController.GetPOV();
    int HatchPosition = HatchManipulator::getInstance()->hatchPosition();
    if (HatchPov == 0 || HatchPov == 45 || HatchPov == 315){
        HatchManipulator::getInstance()->setSpeed(-.4);
    }
    else if (HatchPov == 180 || HatchPov == 135 || HatchPov == 225){
        HatchManipulator::getInstance()->setSpeed(.2);
    }
    // Keeps hatch up when in a specific range
    else if (HatchPosition <= -700 && HatchPosition >= -1500){
        HatchManipulator::getInstance()->setSpeed(-.4);
    }
    else {
        HatchManipulator::getInstance()->setSpeed(0.0);
    }
}

bool DriveJoystick::IsFinished(){
    return false;
}

void DriveJoystick::End(){
    HatchManipulator::getInstance()->setSpeed(0.0);
}

void DriveJoystick::Interrupted(){
    End();
}