#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

#include "RobotMap.h"

class BallManipulator : public frc::Subsystem {
    public:
        //have a singleton based subsytem since you will only have 1 object
        static BallManipulator* getInstance(){
            static BallManipulator instance;
            
            return &instance;
        }

        //prevent copying
        BallManipulator(BallManipulator const&) = delete;
        void operator=(BallManipulator const&)  = delete;

        void setSpeedArm(const double& speedArm);
        void setSpeedIntake(const double& speedIntake);
        void openManipulator();
        void closeManipulator();

    private:
        BallManipulator();

         const int TIMEOUT = 10;

       WPI_TalonSRX m_talonTip = {TALON_TIP};
       WPI_VictorSPX m_intakeLeft = {VICTOR_INTAKE_LEFT};
       WPI_VictorSPX m_intakeRight = {VICTOR_INTAKE_RIGHT};
};