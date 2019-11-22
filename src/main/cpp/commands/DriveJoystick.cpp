#include "commands/DriveJoystick.h"

#include "subsystems/HatchManipulator.h" 
#include "Robot.h"
#include "subsystems/BallManipulator.h"
#include "OI.h"

DriveJoystick::DriveJoystick(){
    Requires(HatchManipulator::getInstance());
}

void DriveJoystick::Initialize(){
    HatchManipulator::getInstance()->setSpeed(0.0);
    BallManipulator::getInstance()->setSpeedIntake(0.0);
    BallManipulator::getInstance()->setSpeedArm(0.0);
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
    double leftStickY = m_logitechController.GetRawAxis(LOGITECH_AXIS_LEFT_Y);
      if(abs(leftStickY) > 0.1) {
        BallManipulator::getInstance()->setSpeedArm(leftStickY);
      }
      else {
          BallManipulator::getInstance()->setSpeedArm(0);
      }
    if (m_logitechController.GetRawButton(LOGITECH_BUTTON_LEFT_BUMPER)) {
        BallManipulator::getInstance()->openManipulator();
    } 
    if (m_logitechController.GetRawButton(LOGITECH_BUTTON_RIGHT_BUMPER)) {
        BallManipulator::getInstance()->closeManipulator();
    } 
    if (m_logitechController.GetRawButton(LOGITECH_RIGHT_TRIGGER)) {
        BallManipulator::getInstance()->setSpeedIntake(-0.2);
    }
    else if (m_logitechController.GetRawButton(LOGITECH_LEFT_TRIGGER)) {
        BallManipulator::getInstance()->setSpeedIntake(0.2);
    }
    else {
        BallManipulator::getInstance()->setSpeedIntake(0.2);
    }
}
bool DriveJoystick::IsFinished(){
    return false;
}

void DriveJoystick::End(){
    HatchManipulator::getInstance()->setSpeed(0.0);
    BallManipulator::getInstance()->setSpeedIntake(0.0);
    BallManipulator::getInstance()->setSpeedArm(0.0);
}

void DriveJoystick::Interrupted(){
    End();
}