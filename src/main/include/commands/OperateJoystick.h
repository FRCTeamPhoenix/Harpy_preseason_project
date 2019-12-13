#pragma once

#include <frc/commands/Command.h>
#include <frc/Joystick.h>

class OperateJoystick : public frc::Command{
    public:
        OperateJoystick();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;

    private:
        frc::Joystick m_logitechController = frc::Joystick(1);

};