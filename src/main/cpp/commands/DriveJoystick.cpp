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
    int HatchSpeed = m_logitechController.GetPOV();
    if (HatchSpeed == 0){
        HatchManipulator::getInstance()->setSpeed(-.3);
    }
    else if (HatchSpeed == 180){
        HatchManipulator::getInstance()->setSpeed(.2);
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