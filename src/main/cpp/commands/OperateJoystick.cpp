#include "commands/OperateJoystick.h"

#include "subsystems/HatchManipulator.h" 
#include "Robot.h"

OperateJoystick::OperateJoystick(){
    Requires(HatchManipulator::getInstance());
}

void OperateJoystick::Initialize(){
    HatchManipulator::getInstance()->setSpeed(0.0);
}

void OperateJoystick::Execute(){
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

bool OperateJoystick::IsFinished(){
    return false;
}

void OperateJoystick::End(){
    HatchManipulator::getInstance()->setSpeed(0.0);
}

void OperateJoystick::Interrupted(){
    End();
}